#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

// Function declarations
struct queue* create_queue();
struct queue* insert(struct queue *, int);
struct queue* delete_element(struct queue *);
void display(struct queue *);
int peek(struct queue *);

int main() {
    int val, option;
    struct queue *q = create_queue();  // Allocate memory properly

    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;
            case 2:
                q = delete_element(q);
                break;
            case 3:
                val = peek(q);
                if (val != -1)
                    printf("The value at front of queue is: %d", val);
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while(option != 5);

    return 0;
}

// Function to create and initialize a new queue
struct queue* create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to insert an element into the queue
struct queue* insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if(q->front == NULL) {
        q->front = ptr;
        q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }

    return q;
}

// Function to delete an element from the queue
struct queue* delete_element(struct queue *q) {
    struct node *ptr;

    if(q->front == NULL) {
        printf("UNDERFLOW: Queue is empty.\n");
    } else {
        ptr = q->front;
        q->front = q->front->next;
        printf("The value being deleted is: %d\n", ptr->data);
        free(ptr);

        // If the queue becomes empty
        if (q->front == NULL)
            q->rear = NULL;
    }

    return q;
}

// Function to peek at the front element
int peek(struct queue *q) {
    if(q->front == NULL) {
        printf("QUEUE IS EMPTY\n");
        return -1;
    } else {
        return q->front->data;
    }
}

// Function to display all elements of the queue
void display(struct queue *q) {
    struct node *ptr = q->front;

    if(ptr == NULL) {
        printf("QUEUE IS EMPTY\n");
    } else {
        printf("Queue contents: ");
        while(ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

