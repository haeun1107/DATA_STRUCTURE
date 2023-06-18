#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#define Element char 
#define bool int 
#define true 1 
#define false 0

typedef struct list_node* list_pointer; 
typedef struct list_node{
    Element data;
    list_pointer link; 
} list_node;

void list_insert(list_pointer head, Element e);
void list_delete(list_pointer head, Element e); 
list_pointer list_search(list_pointer head, Element e); 
bool list_empty(list_pointer head);
void list_show(list_pointer head);

void list_insert(list_pointer head, Element e) {
    list_pointer new;
    new = (list_pointer)malloc(sizeof(list_node));
    new->data = e;
    new->link = head->link;
    head->link = new;
}

void list_delete(list_pointer head, Element e) {
    list_pointer pre = head;
    list_pointer now = head->link;

    while (now->data != e) {
		pre = now;
		now = now->link;

		if (now == NULL) {
			printf("NULL!!\n");
			return;
		}
	}
    pre->link = now->link;
}

list_pointer list_search(list_pointer head, Element e) {
    list_pointer now = head;

    while (now->data != e) {
        now = now->link;

        if (now == NULL) {
            return NULL;
        }
    }
    return now;
}

bool list_empty(list_pointer head) {
    if (head->link == NULL) return true;
    else return false;
}

void list_show(list_pointer head) {
    list_pointer now = head->link;

    if (list_empty(head)) {
        printf("EMPTY!!");
        return;
    }

    while (now != NULL) {
        printf("%c ", now->data);
        now = now->link;
    }
}