#include <stdio.h>
#include <stdlib.h>
int q;
struct Node {
	 int data;
	 struct Node* next;
	 struct Node* prev;
};
struct Node *front=NULL,*rear=NULL,*temp;

void enqueue(int value) {
	 temp = (struct Node*)malloc(sizeof(struct Node));
	 temp->data = value;
	 temp->next = front;
	 temp->prev = rear;

	 if (rear == NULL) {
		  front = rear = front;
	 } else {
		  rear->next = temp;
		  rear = temp;
		  front->prev = rear;
	 }
	 rear->next = front;
	 printf("Element %d enqueued successfully.\n", value);
}

void dequeue() {
	 if (front == NULL) {
		  printf("Queue is empty. Cannot dequeue.\n");
		  return;
	 }
	 temp = front;
	 if (front ==  rear)
		  front = rear = NULL;
		else{
		  front = temp->next;
		  rear->next =  front;
		  front->prev =  rear;
	 }

	 printf("Element %d dequeued successfully.\n", temp->data);
	 free(temp);
}

void displayQueue() {
	 if ( front == NULL) {
		  printf("Queue is empty.\n");
		  return;
	 }
	  printf("Circular Queue: ");
	 for(temp = front; temp->next!=front; temp=temp->next){
		  printf("%d ", temp->data);
		  if(q++>100)
			exit(0);
	 }
	 printf("%d ", temp->data);
	 printf("\n");
}

int main() {
		int choice, value;

    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
		  printf("Enter your choice: ");
		  choice = NULL;
		  scanf("%d", &choice);

		  switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
