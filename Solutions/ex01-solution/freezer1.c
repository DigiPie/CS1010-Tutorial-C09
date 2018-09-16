#include <math.h>
#include "cs1010.h"

int main() 
{
  long hours = cs1010_read_long();
  double final_temperature = 4.0*hours * hours/(hours + 2) - 20;
  cs1010_println_double(final_temperature);
}
