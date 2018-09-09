long max_of_three(long a, long b, long c)
{
  long max = 0;
  if ((a >= b) && (a >= c)) {
    // a is larger than b and c
    max = a;
  }
  if ((b >= a) && (b >= c)) {
    // b is larger than a and c
    max = b;
  }
  if ((c >= a) && (c >= b)) {
    // c is larger than a and b
    max = c;
  }
  return max;
}
