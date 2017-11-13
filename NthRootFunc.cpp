//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//
float power(int n, float x)
{
    float temp = x;
    while (n > 1) {
        x = x * temp;
        n--;
    }
    return x;
}

float calc(int n, float x, float s)
{
    x = ((n - 1) * x / n) + (s / (n * power(n - 1, x)));
    return x;
}
float NthRoot(const float S, const int N, const float precision) {
float s = S;
    int n = N;
    float p = precision;
	
	if(n<2)
		return std::numeric_limits<float>::quiet_NaN();
	if(p<=0)
		return std::numeric_limits<float>::quiet_NaN();
	if(s<0&&n%2==0)
		return std::numeric_limits<float>::quiet_NaN();
    float x = s / n;
    float check = (s - power(n, x)) / s;

    if (check < 0)
        check = check * (-1);

    while (check > p) {
        x = calc(n, x, s);
        check = (s - power(n, x)) / s;
        if (check < 0)
            check = check * (-1);
    }
    return x;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl; 

  return 0;
}

#endif
