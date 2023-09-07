#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insertNode(struct Node **head, int data) {
  struct Node *node = createNode(data);
  if (*head == NULL) {
    *head = node;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = node;
}

void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;

  insertNode(&head, 10);
  insertNode(&head, 20);
  insertNode(&head, 30);

  printList(head);

  return 0;
}