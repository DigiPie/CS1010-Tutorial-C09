long max_of_three(long a, long b, long c)
{
  long max = 0;
  if (a >= b) {
    if (a >= c) {
      max = a;
    } else {
      max = c;
    }
  } else if (b >= c) {
     max = b;
  } else {
    max = c;
  }
}
