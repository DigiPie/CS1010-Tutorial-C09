/**
 * CS1010 Semester 1 AY18/19
 * Exercise 1: Freezer
 * @file: freezer2.c
 * @author: Sim Yu Jie (Group 09)
 */
#include <math.h>
#include "cs1010.h"

/**
 * Read the number of hours and minutes since power 
 * failure and output the freezer temperature.
 */
 
int main() 
{
  long h = cs1010_read_long();
  long m = cs1010_read_long();
  double t;
  double blub;
  t = (long)h +(double)m/60;
  blub = (double)((4*t*t)/(t+2))-20;
  cs1010_println_double(blub);
}
