#include <math.h>
#include "cs1010.h"

/**
 * Read the number of hours and minutes since power 
 * failure and output the freezer temperature.
 */
 
int main() 
{
  // Variables
  double time;
  double temp;

  // Input
  long hour = cs1010_read_long();
  long minute = cs1010_read_long();

  // Calculations
  time = hour + (double)minute/60;
  temp = (double)((4*t*t)/(t+2))-20;

  // Output
  cs1010_println_double(temp);
}
