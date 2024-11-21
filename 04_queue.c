#include <stdio.h>
#include <stdlib.h>

int max;
int *queue;
int rear = -1;
int front = 0;
int count = 0;

void enqueue() {
  int ele;
  if (count == max) {
    printf("Overflow Error.\n");
    return;
  }
  printf("Enter the element to enqueue: ");
  scanf("%d", &ele);
  rear = (rear + 1) % max;
  queue[rear] = ele;
  count++;
}

void dequeue() {
  int ele;
  if (count == 0) {
    printf("Underflow Error.\n");
    return;
  }
  ele = queue[front];
  front = (front + 1) % max;
  printf("Deleted element is %d\n", ele);
  count--;
}

void display() {
  int i, k;
  if (count == 0) {
    printf("Queue is empty.\n");
    return;
  }
  k = front;
  for (i = 0; i < count; i++) {
    printf("%d ", queue[k]);
    k = (k + 1) % max;
  }
  printf("\n");
}

int main() {
  int choice, ele;
  printf("Enter max: ");
  scanf("%d", &max);
  queue = (int *)malloc(max * sizeof(int));
  while (1) {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    default:
      printf("Invalid case.\n");
      free(queue);
      exit(0);
    }
  }
  free(queue);
  return 0;
}