/**
 * https://nus-cs1010.github.io/1819-s1/03-func/index.html#problem-32-ownself-calls-ownself
 *
 * @author Evan Tay
 * @version CS1010 Problem Set 3.2 (b)
 */

#include "cs1010.h"

int recursive_pow(int integer, int exponent)
{
  if (exponent == 1)
  {
    return integer;
  }
  else
  {
    return integer * recursive_pow(integer, --exponent);
  }
}

int main()
{
  cs1010_print_string("recursive_pow(2, 3) aka 2^3: ");
  int output = recursive_pow(2, 3);
  cs1010_println_long(output);
}
