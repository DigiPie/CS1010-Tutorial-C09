/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: SelectionSort
 *
 * @file: selectionsort.c
 * @author: Evan Tay (Group C09)
 */

#include "cs1010.h"

/**
 * Prints an array of long on a single line, elements delimited by
 * a single space.
 *
 * @param[in] length The number of elements in the array
 * @param[in] list The array to print.
 */
void print_array(long length, const long list[length]) {
  for (long i = 0; i < length; i += 1) {
    cs1010_print_long(list[i]);
    cs1010_print_string(" ");
  }

  cs1010_println_string("");
}

/**
 * Swaps the maximum value in the list with the (n - 1)th term.
 *
 * @param[in] last_unsorted The index of the last unsorted element.
 * @param[in] list The list to be sorted.
 */
void selection_swap(long last_unsorted, long list[last_unsorted]) {
  long max = list[0];
  long max_index = 0;
  for (long i = 1; i <= last_unsorted; i += 1) {
    if (list[i] > max) {
      max = list[i];
      max_index = i;
    }
  }

  if (max_index != last_unsorted) {
    long temp = list[last_unsorted];
    list[last_unsorted] = list[max_index];
    list[max_index] = temp;
  }
}

/**
 * Sorts an array using selection sort by performing
 * selection_swap n - 1 times.
 *
 * @param[in] length The length of the array.
 * @param[in] list The array of long to be sorted.
 */
void selection_sort(long length, long list[length]) {
  long last_unsorted = length - 1;

  while(last_unsorted > 0) {
    selection_swap(last_unsorted, list);
    print_array(length, list);
    last_unsorted -= 1;
  }
}

int main() {
  // Input
  long n = cs1010_read_long();
  long *list = cs1010_read_long_array(n);

  // Calculation & Print
  selection_sort(n, list);

  // Free memory
  free(list);
}
