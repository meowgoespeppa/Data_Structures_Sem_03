/*

  LAB PROGRAM 8

  Write a program
  a) To construct a binary Search tree.
  b) To traverse the tree using all the methods i.e., in-order,
  preorder and post order
  c) To display the elements in the tree.

*/

#include <stdio.h>
#include <stdlib.h>

/* Structure definition */
typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

/* Create a new node */
Node *create_node() {
  Node *new_node = malloc(sizeof(Node));
  printf("Enter data: ");
  scanf("%d", &new_node->data);
  new_node->left = new_node->right = NULL;
  return new_node;
}

/* Insert node into BST */
void insert(Node *root, Node *temp) {
  if (temp->data < root->data) {
    if (root->left != NULL)
      insert(root->left, temp);
    else
      root->left = temp;
  } else if (temp->data > root->data) {
    if (root->right != NULL)
      insert(root->right, temp);
    else
      root->right = temp;
  } else
    printf("Duplicate value not allowed!\n");
}

/* Preorder Traversal */
void preorder(Node *root) {
  if (root) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

/* Inorder Traversal */
void inorder(Node *root) {
  if (root) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

/* Postorder Traversal */
void postorder(Node *root) {
  if (root) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

/* Main function */
int main() {
  char ch;
  Node *root = NULL, *temp;

  do {
    temp = create_node();
    if (!root)
      root = temp;
    else
      insert(root, temp);

    printf("Do you want to enter more (y/n)? ");
    scanf(" %c", &ch);
  } while (ch == 'y' || ch == 'Y');

  printf("\nPreorder Traversal: ");
  preorder(root);

  printf("\nInorder Traversal: ");
  inorder(root);

  printf("\nPostorder Traversal: ");
  postorder(root);

  return 0;
}

/*

  OUTPUT

  Enter data: 10
  Do you want to enter more (y/n)? y
  Enter data: 40
  Do you want to enter more (y/n)? y
  Enter data: 30
  Do you want to enter more (y/n)? y
  Enter data: 50
  Do you want to enter more (y/n)? y
  Enter data: 25
  Do you want to enter more (y/n)? y
  Enter data: 35
  Do you want to enter more (y/n)? n

  Preorder Traversal: 10 40 30 25 35 50
  Inorder Traversal: 10 25 30 35 40 50
  Postorder Traversal: 25 35 30 50 40 10

*/
