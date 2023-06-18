#include "linked_queue.h"

int main(void)
{
	char c, e; 
	front = rear = NULL;

	printf("\n****************Command********************\n");
	printf("+<c> : AddQ c, -: DeleteQ, \nS:Show, Q : Quit\n");
	printf("*******************************************\n");


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
                if (is_queue_empty()) {
                    printf("\n Queue is empty !!! \n");
                }
                else {
                    e = deleteq();
                    printf("\n %c ", e);
                }
                break;
            case 'S': 
                queue_show(); 
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
