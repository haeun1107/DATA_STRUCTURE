#include "grade.h"

int main(void) {
    char c;
    printf("Reading record from %s\n", fname);
    read_record(fname);
    printf("%d records have read.\n", num_record);
    printf("********** 명령어 ********** \n");
    printf("P: Print all records \n");
    printf("S: Search record\n");
    printf("C : Change record\n");
    printf("W : Write record\n");
    printf("Q : Save and quit\n");
    printf("***************************\n");

    while (1) {
        printf("\nCommand> ");
        c = getchar();
        c = toupper(c);
        printf("\n");

        switch (c) {
            case 'P':
                print_record();
                break;
            case 'S':
                search_record();
                break;
            case 'C':
                change_record();
                break;
            case 'W':
                write_record(fname);
                break;   
            case 'Q':
                printf("\n");
                exit(1);
                break; 
            default:
                printf("Unknown command!\n");
                break;
        }
        fflush(stdin);
    }
}
