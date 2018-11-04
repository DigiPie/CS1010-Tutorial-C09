#include "cs1010.h"
#include <math.h>

/**
 * Evalute the expression ax^3 + bx^2 + cx + d with a 
 * given value of x.
 *
 * @param[in] a Coefficient to the x^3 term
 * @param[in] b Coefficient to the x^2 term
 * @param[in] c Coefficient to the x term
 * @param[in] d Constant coefficient
 * @param[in] x The value to plug into the cubic equation
 */
double f(double a, double b, double c, double d, double x) {
  return a*x*x*x + b*x*x + c*x + d;
}

/**
 * Evalute the expression 3ax^2 + 2bx + c with a given 
 * value of x.
 *
 * @param[in] a Coefficient to the x^2 term
 * @param[in] b Coefficient to the x term
 * @param[in] c Constant coefficient
 * @param[in] x The value to plug into the cubic equation
 */
double fp(double a, double b, double c, double x) {
  return 3*a*x*x + 2*b*x + c;
}

/**
 * Find the root of ax^3 + bx^2 + cx + d using Newton's method,
 * with initial estimate x.
 *
 * @param[in] a Coefficient to the x^3 term
 * @param[in] b Coefficient to the x^2 term
 * @param[in] c Coefficient to the x term
 * @param[in] d Constant coefficient
 * @param[in] x Initial estimate of root.
 *
 * @return The root estimated using Newton's method starting from x.
 */
double find_root(double a, double b, double c, double d, double x) {
  double fx;
  double fpx;
  
  do {
    fx = f(a, b, c, d, x);
    fpx = fp(a, b, c, x);
    x -= fx/fpx;
  } while (fabs(fx) >= 0.000000001);

  return x;
}

int main()
{
  double a = cs1010_read_double();
  double b = cs1010_read_double();
  double c = cs1010_read_double();
  double d = cs1010_read_double();
  double x = cs1010_read_double();

  x = find_root(a, b, c, d, x);

  cs1010_println_double(x);
}
