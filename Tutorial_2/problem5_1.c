/**
 * https://nus-cs1010.github.io/1819-s1/05-first-c/index.html#problem-51
 *
 * @author Evan Tay
 * @version CS1010 Problem Set 5.1
 */

 #include "cs1010.h"

 int main() {
   cs1010_println_string("Double can hold any integer value without data loss");
   int i = 23;
   cs1010_print_string("Printing int i = 23 as double: ");
   cs1010_println_double(i);

   cs1010_println_string("Converting double to integer results in data loss");
   double d = 3.142;
   cs1010_print_string("Printing double d = 3.142 as integer: ");
   cs1010_println_long(d);
 }
