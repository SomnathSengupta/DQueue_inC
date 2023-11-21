#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct queue_array{
    int arr[max], rear, front;
}queue;

void insertAtFront(queue* qu, int num) {
    if (qu -> front == 0) {
        printf("Insertion at front is not possible.\n");
        return;
    }
    if (qu -> front == -1) {
        qu -> front = 0;
        qu -> rear = 0;
        qu -> arr[qu -> front] = num;
        printf("%d has been inserted at front successfully.\n", num);
        return;
    }
    qu -> front = qu -> front - 1;
    qu -> arr[qu -> front] = num;
    printf("%d has been inserted at front successfully.\n", num);
}
void insertAtRear(queue* qu, int num) {
    if (qu -> rear == max - 1) {
        printf("Queue is full.\n");
        return;
    }
    else if (qu -> front == -1) {
        qu -> front = 0;
    }
    qu -> rear++;
    qu -> arr[qu -> rear] = num;
    printf("%d has been inserted at rear successfully.\n", num);
}
void deleteAtFront(queue* qu) {
    if (qu -> front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    else if (qu -> front > qu -> rear) {
        qu -> front = qu -> rear = -1;
        return;
    }
    else {
        int x = qu -> arr[qu -> front];
        qu -> front++;
        printf("%d has been removed from front successfully.\n", x);
    }
}
void deleteAtRear(queue* qu) {
    int x = qu -> arr[qu -> rear];
    if (qu -> front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    if (qu -> front ==  qu -> rear)
        qu -> front = qu -> rear = -1;
    else
        qu -> rear--;
    printf("%d has been reomved from rear successfully.\n", x);
}
void display(queue qu) {
    if (qu.front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Displaying...\n");
    for (int i = qu.front; i <= qu.rear; i++)
        printf("%d ", qu.arr[i]);
}

int main()
{
    queue qu;
    qu.front = qu.rear = -1;
    int choise, num;
    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete at front\n4. Delete at rear\n5. Display\n6. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &choise);
        switch (choise) {
            case 1:
                printf("\nEnter the value want to insert: ");
                scanf("%d", &num);
                insertAtFront(&qu, num);
                break;
            case 2:
                printf("\nEnter the value want to insert: ");
                scanf("%d", &num);
                insertAtRear(&qu, num);
                break;
            case 3:
                deleteAtFront(&qu);
                break;
            case 4:
                deleteAtRear(&qu);
                break;
            case 5:
                display(qu);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choise.\n");
                break;
        }
    }
    return 0;
}