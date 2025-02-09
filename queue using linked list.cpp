#include <stdio.h>
#include <stdlib.h>
#define MAX 5  
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}
int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}
void push(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0; 
        }
        q->rear++;
        q->arr[q->rear] = value;
        printf("%d added to the queue.\n", value);
    }
}
int pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Nothing to dequeue.\n");
        return -1; 
    } else {
        int value = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return value;
    }
}
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    int choice, value;
    initializeQueue(&q);

    do {
        printf("\nQueue Operations:\n");
        printf("1. Push (Enqueue)\n");
        printf("2. Pop (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&q, value);
                break;
            case 2: 
                value = pop(&q);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

