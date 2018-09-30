/*
 * CS1010 Semester 1 AY18/19
 * https://piazza.com/class/jkqlna92ju045j?cid=206
 * @file: ne.c
 * @author: Evan Tay (Group C09)
 */
#include <stdio.h>

int ne(int x, int y)
{
  if (x == 0 || y == 0)
  {
    return 1;
  }
  else
  {
    return ne(x - 1, y) + ne(x, y - 1);
  }
}

int main()
{
  int x;
  int y;

  printf("Enter x: ");
  scanf("%d", &x);

  printf("Enter y: ");
  scanf("%d", &y);

  printf("ne(%d, %d) = %d\n", x, y, ne(x, y));
}
