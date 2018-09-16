/**
 * Read in a month and a day and prints the number of days since the beginning of the year.
 * @file: days.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"

long days_since(long month, long day)
{
  long days_since_1st_of_the_month = 0;
  if (month == 2) {
    days_since_1st_of_the_month = 31;
  } else if (month == 3) {
    days_since_1st_of_the_month = 31 + 28;
  } else if (month == 4) {
    days_since_1st_of_the_month = 31 + 28 + 31;
  } else if (month == 5) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30;
  } else if (month == 6) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31;
  } else if (month == 7) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30;
  } else if (month == 8) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30 + 31;
  } else if (month == 9) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
  } else if (month == 10) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
  } else if (month == 11) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
  } else if (month == 12) {
    days_since_1st_of_the_month = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
  }

  return days_since_1st_of_the_month + day;
}

void print_with_suffix(long number)
{
  cs1010_print_long(number);

  long last_digit = number % 10;
  long penultimate_digit = (number / 10) % 10;

  if (last_digit == 1 && penultimate_digit != 1) {
    cs1010_println_string("st");
  } else if (last_digit == 2 && penultimate_digit != 1) {
    cs1010_println_string("nd");
  } else if (last_digit == 3 && penultimate_digit != 1) {
    cs1010_println_string("rd");
  } else {
    cs1010_println_string("th");
  }
}

int main() 
{
  long month = cs1010_read_long();
  long day = cs1010_read_long();
  long days = days_since(month, day);
  print_with_suffix(days);
}
