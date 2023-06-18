#include "linked_list.h"

int main(void) {
    char c, e; 
    list_pointer head, p;
    // dummy head 노드
    head = (list_pointer)malloc(sizeof(list_node));
    head->data = 0;
    head->link = 0; 
    printf("******************command*******************\n"); 
    printf("+<c> : Insert c , -<c> : Delete c, \n ?<c> : Search c, S : show , Q : Quit\n"); 
    printf("********************************************\n");
    while (1) {
        printf("\nCommand> ");
        c = getchar();
        c = toupper(c);
        switch (c) { 
            case '+':
                e = getchar(); 
                list_insert(head, e); 
                break;
            case '-':
                e = getchar(); 
                list_delete(head, e); 
                break;
            case '?':
                e = getchar();
                p = list_search(head, e); 
                if (p) {
                    printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
                }
                else printf("\n %c is not in the list \n", e); 
                break;
            case 'S':
                list_show(head); 
                break;
            case 'Q': 
                printf("\n"); 
                exit(1);
            default: break;
        } 
        fflush(stdin);
    }
}       