#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX 100
// Structures
typedef struct {
    char name[10];
    int id;
    char grade[4];
} StudentRecord;


// Global variables
StudentRecord r[MAX]; // Student record: name, id, grade
int num_record = 0; // Total # of records read from file
char *fname = "grade.txt"; // Grade file name

// Function prototypes
void read_record(char *fname);
void print_record();
void search_record();
void change_record();
void write_record(char *fname);

void read_record(char* fname) {
    int i = 0;
    FILE* ifp;

    ifp = fopen(fname, "r");
    while(fscanf(ifp, "%s%d%s", r[i].name, &r[i].id, r[i].grade) == 3) {
        ++i;
    }
    num_record = i;
    fclose(ifp);
}

void print_record() {
    printf("\n------------------------------------\n");
    for(int i = 0; i < num_record; i++) { // r[i].id != NULL
        printf("%10s %10d %10s\n", r[i].name, r[i].id, r[i].grade);
        }
    printf("------------------------------------\n");

}

void search_record() {
    char sname[10];

    printf("Search name : ");
    scanf("%s", sname);

    for (int i = 0; i < num_record; i++) {
        if (!strcmp(sname, r[i].name)) {
            printf("    Name  : %s\n", r[i].name);
            printf("    ID    : %d\n", r[i].id);
            printf("    Grade : %s\n", r[i].grade);
            return;
        }
    }

    printf("\nI can't search!!!!!!\n");
}

void change_record() {
    char cname[10];
    char grade[4];

    printf("    Name  : ");
    scanf("%s", cname);
    printf("    Grade : ");
    scanf("%s", grade);

    for (int i = 0; i < num_record; i++) {
        if (!strcmp(cname, r[i].name)) {
            strcpy(r[i].grade, grade);
            printf("\nRecord changed!\n");
            return;
        }
    }

    printf("\nI can't search!!!!!!!\n");
}

void write_record(char *fname) {
    FILE* ifp;
    ifp = fopen(fname, "w+");

    for (int i = 0; i < num_record; i++) {
        fprintf(ifp, "%s %d %s\n", r[i].name, r[i].id, r[i].grade);
    }

    printf("\n%d records have written to grade.txt\n", num_record);
    fclose(ifp);
}               