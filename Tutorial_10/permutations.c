#include "cs1010.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void swap(char a[], long i, long j) {
  char temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void permute(char str[], long n, long k) {
  if (k == n-1) {
    cs1010_println_string(str);
    return;
  }
  permute(str, n, k+1);
  for (long i = k+1; i < n; i+= 1) {
    swap(str, k, i);
    permute(str, n, k+1);
    swap(str, i, k);
  }
}

int main() {
  char *str = cs1010_read_word();
  permute(str, strlen(str), 0);
  free(str);
}

