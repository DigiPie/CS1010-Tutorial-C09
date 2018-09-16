#include <math.h>
#include "cs1010.h"

int main() 
{
  long hours = cs1010_read_long();
  long minutes = cs1010_read_long();
  double time_since = hours + minutes/60.0;
  double final_temperature = 4.0*time_since*time_since/(time_since + 2) - 20;
  cs1010_println_double(final_temperature);
}
