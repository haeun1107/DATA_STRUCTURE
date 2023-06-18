#include "arraylist.h"

int main(void) {
    char c;
    printf("******************** Command *******************\n");
    printf("+<c>: Insert c, -<c>: Delete c, \n");
    printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n"); 
    printf("************************************************\n"); 
    while (1) {
        printf("\nCommand> ");
        c = getchar();
        c = toupper(c);
        fflush(stdin);
        switch (c) {
            case '+': 
                c = getchar();
                list_insert(c);
                break; 
            case '-':
                c = getchar();
                list_delete(c);
                break;
            case 'E': 
                if (list_empty())
                    printf("\nTRUE \n");
                else
                    printf("\nFALSE \n");
                break;
            case 'F': 
                if (list_full())
                    printf("\nTRUE \n");
                else
                    printf("\nFALSE \n");
                    break;
            case 'S': 
                list_show();
                break; 
            case 'Q':
                printf("\n");
                exit(1);
            default:
                break; 
        }
        fflush(stdin);
    }
}