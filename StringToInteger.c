// https://leetcode.com/problems/string-to-integer-atoi/
#include "base.c"

int myAtoi(char *str) {
  int len = strlen(str);
  int i = 0;
  const int MAX_POS = 2147483647;
  const int MAX_NEG = -2147483648;
  int sign = 1;
  int max = MAX_POS;
  int rval = 0;

  while (str[i] == ' ' && i < len)
    i++;

  if (str[i] == '-') {
    sign = -1;
    max = MAX_NEG;
  }

  if (str[i] == '-' || str[i] == '+')
    i++;

  for (; i < len; i++) {
    if (str[i] < '0' || str[i] > '9')
      break;

    if (((max - (str[i] - '0') * sign) / 10) * sign >= rval)
      rval = rval * 10 + str[i] - '0';
    else
      return max;
  }

  return sign * rval;
}

void print_integer(int n) { printf("%d\n", n); }

int main(void) {
  print_integer(myAtoi("2147483648"));
  print_integer(atoi("    10522545459"));
  return 0;
}
