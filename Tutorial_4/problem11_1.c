#include <math.h>
#include "cs1010.h"

long factorial(long n)
{
  long product;
  // Initialise product as 1
  // While n is bigger or equal than 2, i.e. not 1
  // Multiply the product by n
  // Then n -= 1
  for (product = 1; n >= 2; n -= 1)
  {
    product *= n;
  }
  
  return product;
}

int main() 
{
  cs1010_print_string("Enter n to calculate n factorial: ");
  long n = cs1010_read_long();
  cs1010_println_long(factorial(n));
}
