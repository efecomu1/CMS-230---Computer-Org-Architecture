/**
Write a function called root that takes double n and double x as inputs, then
performs the Babylonian square root algorithm
*
Efe Comu
*/

#include <stdio.h>
#define TOL .0001

double root(double n, double x) {

  // Start with a large diff for the first iteration
  double diff = 100.0;

  while (diff > TOL || diff < -TOL) {
    // Save the current value of x
    double cur = x;

    // Calculate new value using the update rule
    x = .5 * (x + n / x);

    // Update diff
    diff = x - cur;
  }
  return x;
}
int main(int argc, char *argv[]) { printf("%.4f", root(2, 1.5)); }
