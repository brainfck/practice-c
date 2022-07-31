#include <stdio.h>
#include <stdlib.h>

struct item {
  int data;
  struct item *next;
};

/* adding items to end of list */
struct item *int_array_to_list(const int *arr, int len) {
  struct item *first = NULL, *last = NULL, *tmp;
  int i;
  for (i = 0; i < len; i++) {
    tmp = malloc(sizeof *first);
    tmp->data = arr[i];
    tmp->next = NULL;
    if (last) {
      last->next = tmp;
      last = last->next;
    } else {
      first = last = tmp;
    }
  }

  return first;
}

/* adding items to tart of list */
struct item *int_array_to_list_start(const int *arr, int len) {
  struct item *first = NULL, *tmp;
  int i;
  for (i = len - 1; i >= 0; i--) {
    tmp = malloc(sizeof *first);
    tmp->data = arr[i];
    tmp->next = first;
    first = tmp;
  }

  return first;
}

void delete_int_list(struct item *list) {
  while (list) {
    struct item *tmp = list;
    list = list->next;
    free(tmp);
  }
}

int int_list_sum(const struct item *list) {
  int sum = 0;
  for (; list; list = list->next) {
    sum += list->data;
  }
  return sum;
}

void print_int_list(const struct item *list) {
  for (; list; list = list->next) {
    printf("%d \n", list->data);
  }
}

void delete_from_int_list(struct item **pcur, int (*crit)(int)) {
  while (*pcur) {
    if ((*crit)((*pcur)->data)) {
      struct item *tmp = *pcur;
      *pcur = (*pcur)->next;
      free(tmp);
    } else {
      pcur = &(*pcur)->next;
    }
  }
}

int is_negative(int x) { return x < 0; }

int is_even(int x) { return x % 2 == 0; }

int is_div7(int x) { return x % 7 == 0; }

int main() {
  /* int arr[10] = {-1, -2, 3, 4, 5, 6, -7, 8, 9, 10}; */
  /* struct item *first = int_array_to_list(arr, 10); */
  /* delete_from_int_list(&first, &is_negative); */
  /* print_int_list(first); */
  /* int sum = int_list_sum(first); */
  /* printf("Sum: %d \n", sum); */
}
