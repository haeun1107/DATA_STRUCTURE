#include <stdio.h>

int binary_search(int list[], int searchnum, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = (left+right) / 2 ;
    if (searchnum == list[mid]) {
        return mid;
    }

    else if(list[mid] > searchnum) {
        return binary_search(list, searchnum,left, mid-1);
    }

    else {
        return binary_search(list, searchnum, mid-1, right);
    }
}

int main(void) {
    int num, result;
    int left = 0;
    int right = 9;

    printf("Search number : ");
    scanf("%d", &num);

    int a[10] = {1,3,5,7,9,11,13,15,17,19};
    result = binary_search(a, num, left, right);

    printf("%d is in a[%d]\n", num, result);
    return 0;
}