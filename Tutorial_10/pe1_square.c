/**
 * CS1010 Semester 1 AY18/19
 * Practical Exam 1: Square 
 *
 * @file: square.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

/**
 * Print a line of given width consisting of # only.
 *
 * @param[in] width The width of the line.
 */
void print_line(long width) {
  for (long i = 0; i < width; i+=1) {
    cs1010_print_string("#");
  }
}

/**
 * Print a line of given width, consisting of " " except
 * the first and last characters, which is #.
 *
 * @param[in] width The width of the line.
 */
void print_border(long width) {
  cs1010_print_string("#");
  for (long i = 0; i < width - 2; i+=1) {
    cs1010_print_string(" ");
  }
  cs1010_print_string("#");
}

/**
 * Print one row of a concentric square, recursively.  
 *
 * @param[in] row Which row of the square to draw.
 * @param[in] width The width of the square.
 */
void draw_square(long row, long width) {
  if (width == 1) {
    cs1010_print_string("#");
  } else if (row == 0 || row == width - 1) {
    print_line(width);
  } else if (row == 1 || row == width - 2) {
    print_border(width);
  } else {
    cs1010_print_string("# ");
    draw_square(row - 2, width - 4);
    cs1010_print_string(" #");
  }
}

int main()
{
  long width = cs1010_read_long();
  for (long row = 0; row < width; row += 1) {
    draw_square(row, width);
    cs1010_println_string("");
  }
}
