/*
 * CS1010 Semester 1 AY18/19
 * Exercise 1: Freezer
 * @file: freezer1.c
 * @author: Evan Tay (Group C09)
 */
#include <math.h>
#include "cs1010.h"

/**
 * Read the number of hours since power failure and 
 * output the freezer temperature.
 */
int main() 
{
  double hour = cs1010_read_double();
  double temp = 4 * pow(hour, 2) / (hour + 2) - 20; // pow returns a double
  cs1010_println_double(temp);
}
