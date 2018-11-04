#include "cs1010.h"

void print_peg(long n) {
  if (n == 1) {
    cs1010_print_string("A");
  } else if (n == 2) {
    cs1010_print_string("B");
  } else {
    cs1010_print_string("C");
  }
}

/**
 * Move Disk k from Peg source to Peg dest.
 *
 * @param[in] k The disk to move
 * @param[in] source The peg Disk k is currently at.
 * @param[in] dest The peg Disk k is moved to.
 */
void move(long k, long source, long dest) {
  cs1010_print_string("Disk ");
  cs1010_print_long(k);
  cs1010_print_string(": Peg ");
  print_peg(source);
  cs1010_print_string(" -> Peg ");
  print_peg(dest);
  cs1010_println_string("");
}

void solve(long k, long source, long dest, long placeholder) {
  if (k == 1) {
    move(k, source, placeholder);
    move(k, placeholder, dest);
  } else {
    solve(k - 1, source, dest, placeholder);
    move(k, source, placeholder);
    solve(k - 1, dest, source, placeholder);
    move(k, placeholder, dest);
    solve(k - 1, source, dest, placeholder);
  }
}

int main() {
  long k = cs1010_read_long();
  cs1010_println_string("Problem 25.1");
  solve(k, 1, 3, 2);
}

