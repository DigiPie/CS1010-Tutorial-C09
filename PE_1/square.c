/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 1: Square 
 *
 * @file: square.c
 * @author: XXX (Group YYY)
 */

#include "cs1010.h"

void draw_square(long row, long width) {
  // TODO(by student)
}

int main()
{
  long n = cs1010_read_long();
  for (long i = 1; i <= n; i += 1) {
    draw_square(i, n);
    cs1010_println_string("");
  }
}
