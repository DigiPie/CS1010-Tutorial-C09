/*
 * CS1010 Semester 1 AY18/19
 * Problem 21.1
 * https://nus-cs1010.github.io/1819-s1/21-assert/index.html
 * @file: problem21_1.c
 * @author: Evan Tay (Group C09)
 */
#include <assert.h>
#include "cs1010.h"

void foo(long x) {
  if (x % 2 == 0) {
    // do something
  } else {
    assert(x % 2 == 1);
  }
}

int main()
{
  long test_arr[3] = {0, 1, -1};
  for (long i = 0; i < 3; i += 1) {
    cs1010_print_string("Testing foo(");
    cs1010_print_long(i);
    cs1010_println_string(")");
    foo(test_arr[i]);
  }
}
