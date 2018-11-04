#include "cs1010.h"

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
  cs1010_print_long(source);
  cs1010_print_string(" -> Peg ");
  cs1010_println_long(dest);
}

void solve(long k, long source, long dest, long placeholder) {
  if (k == 1) {
    move(k, source, dest);
  } else {
    solve(k - 1, source, placeholder, dest);
    move(k, source, dest);
    solve(k - 1, placeholder, dest, source);
  }
}

int main() {
  long k = cs1010_read_long();
  solve(k, 1, 3, 2);
}

