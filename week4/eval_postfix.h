#include <stdio.h>
#pragma warning(disable : 4996)

#define MAX_SIZE 100
#define boolean unsigned char 
#define true 1
#define false 0

// Global stack
int stack[MAX_SIZE];
int top = -1;
boolean err_check = false;

void push(int e); 
int pop();

int eval_postfix(char* exp); 
boolean is_number(char c); 
boolean is_op(char c);

void push(int e) {
    if (top < MAX_SIZE - 1) 
        stack[++top] = e;
    else
        printf("FULL~~~~");
}

int pop() {
    if (top > -1) {
        return stack[top--];
    }
    else
        printf("EMPTY~~~~");
    return '\0';
}

int eval_postfix(char *exp) {
    top = -1;
    err_check = false;
    int i = 0;
    int n1, n2;
    while(1) {
        if (exp[i] == '\0') {
            return pop();
        }
        if (is_number(exp[i])) {
            push(exp[i] - 48);
        }
        else if(is_op(exp[i])) {
            n2 = pop();
            n1 = pop();
            switch (exp[i]) {
                case '+':
                    push(n1 + n2);
                    break;
                case '-':
                    push(n1 - n2);
                    break;
                case '*':
                    push(n1 * n2);
                    break;
                case '/':
                    if (n2 != 0)
                        push(n1 / n2);
                    else {
                        printf("\ndivided by 0 error\n");
                        err_check = true;
                        return 0;
                    }
                    break;
                default:
                    break;
            }
        }
        i++;
    }
}

boolean is_number(char c) {
    if (('0' <= c) && (c <= '9')) 
        return true;
    else
        return false;
}

boolean is_op(char c) {
    if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
        return true;
    else   
        return false;
}