/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Mastermind
 *
 * @file: mastermind.c
 * @author: Evan Tay (Group C09)
 */

#include <stdbool.h>
#include "cs1010.h"

#define PEGS 4 // Number of colour pegs for the game

/**
 * Prints the results in the desired output format.
 *
 * @param[in] colour_pos The number of pegs which are of
 * the right colour and in the right position.
 * @param[in] colour_only The number of pegs which are of
 * the right colour but in the wrong position; not double-counted
 * with colour_pos.
 */
void print_results(long colour_pos, long colour_only) {
  cs1010_print_long(colour_pos);
  cs1010_print_string(" ");
  cs1010_println_long(colour_only);
}

/**
 * Checks if the answer is correct by comparing the answer and the
 * guess. Prints the number of pegs in right position and of right
 * colour followed by the number of pegs of right colour but wrong
 * position.
 *
 * @pre The length of answer and guess must be equal to PEGS.
 * @param[in] answer The array of pegs corresponding to the answer.
 * @param[in] guess The array of pegs corresponding to the guess.
 * @return True if game is not over yet because guess is not correct,
 * false if game is over because every peg is in right position and
 * of right colour.
 */
bool game_check(const char answer[], const char guess[]) {
  long right_colour_pos = 0; // Right colour peg in right position
  long right_colour_only = 0; // Right colour peg in wrong position

  bool guess_to_check[PEGS];
  bool answer_to_check[PEGS];

  // For every peg
  for (long i = 0; i < PEGS; i += 1) {
    // If right position and of right colour
    if (guess[i] == answer[i]) {
      right_colour_pos += 1;
      guess_to_check[i] = false;
      // Don't compare the guess peg again when checking for right colour
      // but wrong position to avoid double counting.
      answer_to_check[i] = false;
      // Don't allow comparison with the answer peg when checking for right
      // colour but wrong position to avoid double counting here too.
    } else {
      // If no match, do check this guess peg and also allow the answer
      // peg to be matched with
      guess_to_check[i] = true;
      answer_to_check[i] = true;
    }
  }

  for (long i = 0; i < PEGS; i += 1) {
    bool searching = true;
    for (long j = 0; j < PEGS && searching; j += 1) {
      // If answer peg has not been matched yet and guess peg has not 
      // been counted previously and guess peg is of same colour (but 
      // not same position) as the answer peg, count.
      if (answer_to_check[j] && guess_to_check[i] &&
            guess[i] == answer[j]) {
        right_colour_only += 1;
        answer_to_check[j] = false;
        // Don't allow further matching with this answer peg
        searching = false;
        // Stop matching for this peg
      }
    }
  }

  print_results(right_colour_pos, right_colour_only);
  return right_colour_pos != PEGS;
}

int main()
{
  char *answer = cs1010_read_word();
  char *guess;
  bool wrong = true;
  while (wrong) {
    guess = cs1010_read_word();
    wrong = game_check(answer, guess);
    free(guess); // Free guess before next allocation
  }

  // Free memory
  free(answer);
}
