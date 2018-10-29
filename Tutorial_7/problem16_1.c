/*
 * CS1010 Semester 1 AY18/19
 * Problem 16.1
 * https://nus-cs1010.github.io/1819-s1/16-string/index.html
 * @file: problem16_1.c
 * @author: Evan Tay (Group C09)
 */
#include <stdbool.h>
#include "cs1010.h"

long string_length(char *str) {
  long count = 0;
  // Initialise by pointing to first char of string
  // While not pointing at terminating null character
  // Increment count
  // Point to next char of string
  for (char *curr = str; *curr != '\0'; curr += 1) {
    count += 1;
  }

  return count;
}

bool string_equal(char *str1, char *str2) {
  // While there are chars to be checked for both strings
  while (*str1 != '\0' && *str2 != '\0') {
    // If characters differ, return false (terminate this function)
    if (*str1 != *str2) {
      return false;
    }

    str1 += 1;
    str2 += 1;
  }

  // Assertion: After the while loop is completed, both pointers
  // should point to the null terminating char. If this is not the
  // case, return false because 1 string is longer than the other
  if (*str1 != '\0' || *str2 != '\0') {
    return false;
  }

  return true;
}

bool has_needle_here(char *needle, char *haystack) {
  while (*needle != '\0') {
    if (*needle != *haystack) {
      return false;
    }

    needle += 1;
    haystack += 1;
  }

  return true;
}

char* string_in_string(char *needle, char *haystack) {
  char *curr_haystack = haystack;
  // If needle is "gal" (len of 3)
  // and haystack array is "Yo what's up bro." (len of 17)
  // end_haystack is haystack[17 - 3] == haystack[14] == r
  // So the last while loop will check 'ro.' for 'gal'.
  char *end_haystack = haystack + 
      string_length(haystack) - string_length(needle);
  while (curr_haystack <= end_haystack) {
    if (has_needle_here(needle, curr_haystack)) {
      return curr_haystack;
    }
  }

  return NULL;
}

void print_str_len(char *str) {
  cs1010_print_string("The length of \"");
  cs1010_print_string(str);
  cs1010_print_string("\" is: ");
  cs1010_println_long(string_length(str));
}

void print_str_eq(char* str1, char* str2)
{
  cs1010_print_string("The string \"");
  cs1010_print_string(str1);

  if (string_equal(str1, str2))
  {
    cs1010_print_string("\" is the same as \"");
  }
  else
  {
    cs1010_print_string("\" is NOT the same as \"");
  }

  cs1010_print_string(str2);
  cs1010_println_string("\"");
}

void print_str_in_str(char* str1, char* str2)
{
  cs1010_print_string("Is \"");
  cs1010_print_string(str1);
  cs1010_print_string("\" in \"");
  cs1010_print_string(str2);
  cs1010_print_string("\"? ");
  cs1010_println_string(string_in_string(str1, str2));
}

int main()
{
  // a)
  char *helloMsg = "Hello World!";
  cs1010_println_string("Part a)");
  print_str_len(helloMsg);

  // b)
  char *helloMsgLong = "Hello World! Welcome.";
  cs1010_println_string("\nPart b)");
  print_str_len(helloMsgLong);
  print_str_eq(helloMsgLong, helloMsgLong);
  print_str_eq(helloMsg, helloMsgLong);

  // c)
  char *nullMsg = "";
  cs1010_println_string("\nPart c)");
  print_str_in_str(helloMsg, helloMsgLong);
  print_str_in_str(helloMsgLong, helloMsg);
  print_str_in_str(nullMsg, helloMsg);
}
