/*
 * CS1010 Semester 1 AY18/19
 * Problem 17.1
 * https://nus-cs1010.github.io/1819-s1/16-string/index.html
 * @file: problem17_1.c
 * @author: Evan Tay (Group C09)
 */
#include <stdbool.h>
#include "cs1010.h"

void find_min_max(long length, long array[length], long *min, long *max)
{
  *max = -LONG_MAX;
  *min = LONG_MAX;

  for (long i = 0; i < length; i++) {
    if (array[i] > *max) {
      *max = array[i];
    }

    if (array[i] < *min) {
      *min = array[i];
    }
  }
}

int main()
{
  long list[10] = {1, 2, 3, 4, -4, 5, 6, -8, 3, 1};
  long min;
  long max;
  // No need to initialise min and max because find_min_max does
  find_min_max(10, list, &min, &max);
  cs1010_print_string("Min of list: ");
  cs1010_println_long(min);
  cs1010_print_string("Max of list: ");
  cs1010_println_long(max);;
}
