#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define	boolean	unsigned char
#define	true	1
#define	false	0

typedef char Element;
// Global queue
typedef struct queue* queue_pointer;
typedef struct queue {
	Element 		item;
	queue_pointer 	link;
} queue;
queue_pointer front, rear;

void addq(Element e);
Element deleteq();
void queue_show();
boolean is_queue_empty();

void addq(Element e) {
	queue_pointer add = (queue_pointer)malloc(sizeof(queue));
	add->item = e;
	add->link = NULL;

	if (is_queue_empty()) {
		front = rear = add;
	}
	else {
		rear->link = add;
		rear = add;
	}
}

Element deleteq() {
	Element c;
	queue_pointer tmp;
	c = front->item;
	tmp =  front;
	front = front->link;
	free(tmp);
	return c;
}

void queue_show() {
	queue_pointer tmp = front;
	printf("\n");
	while (tmp != NULL) {
		printf("%3c", tmp->item);
		tmp = tmp->link;
	}
}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
