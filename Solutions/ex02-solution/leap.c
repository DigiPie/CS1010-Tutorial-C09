/**
 * Read in a year and prints out if the input year is a leap year.
 * @file: leap.c
 * @author: XXX (Group YYY)
 */
#include <stdbool.h>
#include "cs1010.h"

bool is_leap_year(long year) 
{
  return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

int main() 
{
  long year = cs1010_read_long();
  cs1010_print_long(year);
  if (is_leap_year(year)) {
    cs1010_println_string(" is a leap year");
  } else {
    cs1010_println_string(" is not a leap year");
  }
}
