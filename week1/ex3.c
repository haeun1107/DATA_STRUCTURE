#include <stdio.h>

int main(void) {
    int i, max_index = 0;
    int score[10] = {55, 20, 33, 85, 13, 22, 45, 98, 67, 77}; 
    
    for (i = 0; i < 10; i++) {
        printf("%d 번 : %d\n", i, score[i]);
        if (score[i] > score[max_index]) {
            max_index = i;
        }
    }
    printf("1등은 %d 번, 성적은 %d 입니다. \n\n", max_index, score[max_index]);
    return 0;
}