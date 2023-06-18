#include <stdio.h>

int find_max(int s[], int size) {
    int maxi = 0;
    for (int i = 0; i < size; i++) {
        printf("%d 번 : %d\n", i, s[i]);
        if (s[i] > s[maxi]) {
            maxi = i;
        }
    }
    return maxi;
}

int main(void) {
    int max_index;
    int score[10] = {55, 20, 33, 85, 13, 22, 45, 98, 67, 77}; 
    
    max_index = find_max(score, 10);
    
    printf("1등은 %d 번, 성적은 %d 입니다. \n\n", max_index, score[max_index]);
    return 0;
}