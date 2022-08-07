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

int my_strcmp(const char *s1, const char *s2) {
  for (; *s1; s1++, s2++) {
    if (*s1 != *s2)
      return 0;
  }

  return 1;
}

void swap_char(char *str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void reverse(char *str) {
  int len = string_length(str);
  int i;
  for (i = len; i > len / 2; i--) {
    swap_char(str, i, len - i - 1);
  }
}

int main() {
  /* printf("%i \n", string_length("SOME BIG STRING")); */
  /* char dst[] = "Unimaginable"; */
  /* char src[] = "Look Here\0"; */
  /* my_strcpy(dst, src); */
  /* printf("Dest: %s \nSource: %s \n", dst, src); */
  /* printf("%d \n", my_strcmp(dst, src)); */

  char test[] = "abcdefghijklmnopqrstuvwxyz";
  printf("%s \n", test);
  reverse(test);
  printf("%s \n", test);
  return 0;
}
