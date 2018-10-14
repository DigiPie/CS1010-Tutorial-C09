/*
 * CS1010 Semester 1 AY18/19
 * Problem 15.3
 * https://nus-cs1010.github.io/1819-s1/15-array/index.html#problem-152
 * @file: problem15_3.c
 * @author: Evan Tay (Group C09)
 */
#include <stdio.h>
#include "cs1010.h"

int main()
{
  char a[3] = {'A', 'B', 'C'};

  for (long i = 0; i < 3; i += 1)
  {
    printf("%x\n", &a[i]);
  }
}
