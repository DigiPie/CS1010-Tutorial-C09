#include <stdlib.h>
#include <sys/times.h>
#include "cs1010.h"

long guess_a_number()
{
  // Generate a random number between 1 and 100
  long answer = (random() % 100) + 1;

  long guess = cs1010_read_long();
  long count = 1; // New addition

  while (guess != answer) {
    // Read guess and feedback to user
    count += 1; // New addition
    if (guess > answer) {
      cs1010_println_string("too high");
    } else if (guess < answer) {
      cs1010_println_string("too low");
    }

    guess = cs1010_read_long();
  }

  cs1010_print_string("you got it after: ");
  cs1010_print_long(count);
  cs1010_println_string(" tries. congrats!");
  return count;
}

int main()
{
  // Initialize the random number generator
  srandom(times(0));

  long total_count = 0;

  for (int i = 1; i < 5; i += 1)
  {
    cs1010_print_string("round: ");
    cs1010_println_long(i);
    total_count += guess_a_number();
    cs1010_print_string("total tries at: ");
    cs1010_println_long(total_count);
  }

  double avg_count = total_count/5.0;

  cs1010_print_string("your average number of guesses over five rounds:  ");
  cs1010_print_double(avg_count);
  cs1010_println_string(" tries.  congrats!");
}
