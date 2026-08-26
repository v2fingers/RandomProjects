#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *back;
};

int main() {
  struct Node *node1 = NULL;
  struct Node *node2 = NULL;
  struct Node *node3 = NULL;

  node1 = (struct Node *)malloc(sizeof(struct Node));
  node2 = (struct Node *)malloc(sizeof(struct Node));
  node3 = (struct Node *)malloc(sizeof(struct Node));

  if (!node1 || !node2 || !node3) {
    printf("Memory allocation failed\n");
    return 1;
  }

  node1->data = 13;
  node1->next = node2;
  node1->back = node3;

  node2->data = 100;
  node2->next = node3;
  node2->back = node1;

  node3->data = 20;
  node3->next = node1;
  node3->back = node2;

  struct Node *temp = node1;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("END\n");

  temp = node3;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->back;
  }
  printf("END\n");

  temp = node1;
  while (temp != NULL) {
    struct Node *next = temp->next;
    free(temp);
    temp = next;
  }

  return 0;
}
