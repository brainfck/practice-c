#include <stdio.h>

int string_length(const char *str) {
  const char *p;
  for (p = str; *p; p++) {
  }
  return p - str;
}

void my_strcpy(char *dest, const char *src) {
  for (; *src; src++, dest++) {
    *dest = *src;
  }
  *dest = 0;
}

int main() {
  /* printf("%i \n", string_length("SOME BIG STRING")); */
  char dst[] = "Unimaginable";
  char src[] = "Look Here";
  my_strcpy(dst, src);
  printf("%s", dst);
  return 0;
}
