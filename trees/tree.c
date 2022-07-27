#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *left, *right;
};

void int_bin_tree_print(struct node *root) {
  if (!root)
    return;
  int_bin_tree_print(root->left);
  printf("%d ", root->val);
  int_bin_tree_print(root->right);
}

void int_bin_tree_add(struct node **root, int n) {
  if (!*root) {
    *root = malloc(sizeof(**root));
    (*root)->val = n;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return;
  }
  if ((*root)->val == n)
    return;
  if (n < (*root)->val)
    int_bin_tree_add(&(*root)->left, n);
  else
    int_bin_tree_add(&(*root)->right, n);
}

int main() {
  int arr[] = {9, 2, 23, 12, 443, 90, -5, -100, -10000, 22};
  struct node *root = NULL;
  int i;
  for (i = 0; i < sizeof(arr) / sizeof(int); i++) {
    int_bin_tree_add(&root, arr[i]);
  }
  int_bin_tree_print(root);
  printf("\n");
}
