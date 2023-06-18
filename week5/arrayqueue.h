#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 10 
#define boolean int 
#define true 1 
#define false 0

typedef char Element;
// Global queue
Element queue[MAX_SIZE]; 
int front = 0;
int rear = 0;
boolean is_empty = false;

void addq(Element e); 
Element deleteq(); 
void queue_show();

void addq(Element e) {
    if (front == (rear + 1) % MAX_SIZE)
        printf("FULL!!!");
    else {
        rear = (rear + 1) % MAX_SIZE;
		queue[rear] = e;
		is_empty = false;
    }
}

Element deleteq() {
    if (front == rear) {
        printf("EMPTY!!");
        is_empty = true;
        return '\0';
    }
    else {
        front = (front + 1) % MAX_SIZE;
		return queue[front];
    }
}

void queue_show() {
    if (is_empty == 1) printf("EMPTY!!");
    else {
        int i = front;
        while (i != rear) {
            i = (i+1) % MAX_SIZE;
            printf("%c ", queue[i]);
        }
        printf("\n");
    }
}

