// https://leetcode.com/problems/valid-palindrome/

bool isPalindrome(char *s) {
  if (s == NULL || !strcmp(s, ""))
    return true;

  for (char *p = s + strlen(s) - 1; p > s;)
    if (isalnum(*s) && isalnum(*p) && tolower(*(s++)) != tolower(*(p--)))
      return false;
    else if (!isalnum(*s))
      s++;
    else if (!isalnum(*p))
      p--;

  return true;
}
