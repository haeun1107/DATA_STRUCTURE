#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;
// Global stack
Element stack[MAX_SIZE];
int top = -1;

void push(Element e); 
Element pop();
void stack_show();

void push(Element e) {
    if (top < MAX_SIZE - 1)
        stack[++top] = e;
    else
        printf("FULL!!!!\n");
}

Element pop() {
    if (top > -1)
        return stack[top--];
    else
        printf("EMPTY!!!!\n");
    return '\0';
}

void stack_show() {
    if (top > -1) {
        for (int i = 0; i <= top; i++) {
            printf("%3c", stack[i]);
        }
    }
}