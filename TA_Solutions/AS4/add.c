/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Add
 *
 * @file: add.c
 * @author: Evan Tay (Group C09)
 */

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "cs1010.h"

/**
 * Performs a single digit addition. The digits are stored in char form.
 *
 * @pre a and b can only be '0', '1', .. '9'
 * @param[in] a The first operand of addition (in char)
 * @param[in] b The second operand of addition (in char)
 * @param[in,out] has_carry Whether we should add a carry when adding
 * a + b.  If a + b generates a carry, *has_carry will be set to true, 
 * otherwise to false.
 *
 * @return The least significant digit of a + b (as char)
 */
char add_digits(char a, char b, bool *has_carry) {
  // '0' - '0' = 0, '1' - '0' = 1, etc.
  long sum = (a - '0') + (b - '0');
  if (*has_carry) {
    sum += 1;
  }

  char result;
  if (sum >= 10) {
    // If larger than 10, get the LSB and convert back to appropriate char
    // by adding '0'
    result = (sum % 10) + '0';
    *has_carry = true;
  } else {
    // If less than 10, simply add '0' to convert back to appropriate char
    result = sum + '0';
    *has_carry = false;
  }

  return result;
}

/**
 * Performs an addition of two numbers stored as strings using the
 * add_digit function to perform a series of single digit additions.
 * Prints the result.
 *
 * @pre bigger must be bigger than smaller. Both bigger and smaller can
 * only contain characters '0', '1', .. '9'
 * @param[in] *bigger The larger operand (in string)
 * @param[in] bigger_len The length of bigger
 * @param[in] *smaller The smaller operand (in string)
 * @param[in] smaller_len The length of smaller
 */
void str_add(char *bigger, long bigger_len, char *smaller, 
    long smaller_len) {
    // Array size +1 for carry out and +1 for terminating char
    char *result = calloc(bigger_len + 2, sizeof(char *));
    result[bigger_len + 1] = '\0';

    long i = bigger_len - 1;
    long j = smaller_len - 1;
    long k = bigger_len;
    bool has_carry = false;

    // Start adding from Least Significant Digit till smaller 
    // number is fully added
    while (i >= 0 && j >= 0) {
      result[k] = add_digits(bigger[i], smaller[j], &has_carry);
      i -= 1;
      j -= 1;
      k -= 1;
    }
    
    // Set the remaining digits of result to that of the bigger number
    while (i >= 0) {
      result[k] = add_digits(bigger[i], '0', &has_carry);
      i -= 1;
      k -= 1;
    }
    
    // If last addition of the most significant digit has carry,
    if (has_carry) {
      // Add 1 to the most significant digit of the result
      result[k] = '1';
      cs1010_println_string(result);
    } else {
      // Else only start printing from the 2nd most significant digit
      cs1010_println_string(&result[1]);
    }

    // Free memory
    free(result);
}

int main() {
  // Input
  char *operand1 = cs1010_read_word();
  assert(operand1 != NULL);
  char *operand2 = cs1010_read_word();
  assert(operand2 != NULL);

  // Calculation & Output
  long len1 = strlen(operand1);
  long len2 = strlen(operand2);

  // Always pass in the larger string first, then the smaller one
  if (len1 > len2) {
    str_add(operand1, len1, operand2, len2);
  } else {
    str_add(operand2, len2, operand1, len1);
  }

  // Free memory
  free(operand1);
  free(operand2);
}
