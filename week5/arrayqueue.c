#include "arrayqueue.h"

int main(void) {
    char c, e;
    printf("****************command*******************\n"); printf("+<c> : AddQ c , - : DeleteQ, \n S : show , Q : Quit\n");
    printf("******************************************\n");
    while (1) {
        printf("\nCommand> "); 
        c = getchar();
        c = toupper(c);
        switch (c) {
            case '+': 
                e = getchar();
                addq(e);
                break; 
            case '-':
                e = deleteq();
                if (is_empty != true)
                    printf("\n %c ", e); 
                is_empty = false;
                break;
            case 'S':  
                queue_show();
                break;
            case 'Q': 
                printf("\n");
                exit(1); 
            default: break;
        }
        fflush(stdin);
    }
}   