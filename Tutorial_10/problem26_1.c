#include "cs1010.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool appear_before(char str[], long k, long i) {
  for (int j = k; j < i; j += 1) {
    if (str[j] == str[i]) {
      return true;
    }
  }

  return false;
}

void swap(char str[], long i, long j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void permute(char str[], long len, long curr) {
  if (curr == len-1) {
    cs1010_println_string(str);
    return;
  }
  permute(str, len, curr+1);
  for (long i = curr+1; i < len; i+= 1) {
    if (!appear_before(str, curr, i)) {
      swap(str, curr, i);
      permute(str, len, curr+1);
      swap(str, i, curr);
    }
  }
}

int main() {
  char *str = cs1010_read_word();
  permute(str, strlen(str), 0);
  free(str);
}

