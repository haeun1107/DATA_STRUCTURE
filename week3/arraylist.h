#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxSize 3 
#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;
// Global로 선언한 List 자료구조
Element List[MaxSize];
int size = 0;

void list_insert(Element e); 
void list_delete(Element e); 
boolean list_empty(); 
boolean list_full();
void list_show();

boolean list_full() {
    if(size == MaxSize)
        return true; // 리스트가 가득 차 있으면 true
    else
        return false;
}

boolean list_empty() {
    if(size == 0)
        return true; // 리스트가 비어 있으면 true
    else
        return false;
}

void list_show() {
    if(list_empty())
        printf("List is Empty!!!\n");
    else {
        for(int i = 0; i < size; i++)
            printf("%c ", List[i]);
    }
}

void list_insert(Element e) {
    if(list_full())
        printf("List is full!!!\n");
    else {
        List[size] = e;
        size++;
    }
}

void list_delete(Element e) {
    if(list_empty())
        printf("List is Empty!!!\n");
    else {
        for(int i = 0; i < size; i++) {
            if(List[i] == e) {
                for(int j = i; j < size-1; j++) {
                    List[j] = List[j+1];
                }
                size--;
                return;
            }
        }
        printf("Data does not exist!!\n");
    }
}