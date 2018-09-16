#include <stdlib.h>
#include <sys/times.h>
#include "cs1010.h"

int main()
{
  // Initialize the random number generator
  srandom(times(0));

  // Generate a random number between 1 and 100
  long answer = (random() % 100) + 1;

  long guess;
  long count = 0; // New addition
  do {
    // Read guess and feedback to user
    guess = cs1010_read_long();
    count += 1; // New addition
    if (guess > answer) {
      cs1010_println_string("too high");
    } else if (guess < answer) {
      cs1010_println_string("too low");
    }
  } while (guess != answer);

  // { guess == answer }
  cs1010_print_string("you got it after ");
  cs1010_print_long(count);
  cs1010_println_string(" tries.  congrats!");
}
