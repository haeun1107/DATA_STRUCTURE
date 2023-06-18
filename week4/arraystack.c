#include "arraystack.h"

int main(void) {
    char c, e;

    printf("******************** Command *******************\n"); 
    printf("+<c>: push c, - : pop, \n");
    printf("S: Show, Q: Quit \n");
    printf("************************************************\n"); 
    while (1) {
        printf("\nCommand> "); 
        c = getchar();
        c = toupper(c);
        fflush(stdin);
        switch (c) {
            case '+':
                e = getchar(); 
                push(e);
                break; 
            case '-':
                e = pop();
                if (e != '\0')
                    printf("\n %c \n", e);
                break; 
            case 'S': 
                stack_show();
                break; 
            case 'Q': 
                printf("\n");
                exit(1); 
            default: break;
        }
        fflush(stdin);
    }
}