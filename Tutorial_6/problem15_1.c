/*
 * CS1010 Semester 1 AY18/19
 * Problem 15.1
 * https://nus-cs1010.github.io/1819-s1/15-array/index.html#problem-152
 * @file: problem15_1.c
 * @author: Evan Tay (Group C09)
 */
#include "cs1010.h"

double avg(const long list[], long length)
{
  long sum = list[0];
  // This is better than:
  // long sum = 0;
  // Then subsequently doing a for loop starting with i = 0
  // As this avoids a wasted assignment of sum = 0, and one loop iteration
  for (long i = 1; i < length; i += 1) {
    sum += list[i];
  }

  return sum*1.0/length;
  // You can also type-cast with (double) to prevent integer division
}

int main()
{
  long a[10] = {1, 2, 3, 4, 1, 9, 10, 44, -1, -5};
  cs1010_println_long(avg(a, 10));
}
