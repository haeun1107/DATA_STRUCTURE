#include "binary_tree.h"
tree_pointer build_simple_tree() {
    tree_pointer n1, n2, n3, n4, n5, n6, n7, n8, n9;
    n1 = (tree_pointer)malloc(sizeof(node));
	n2 = (tree_pointer)malloc(sizeof(node));
	n3 = (tree_pointer)malloc(sizeof(node));
	n4 = (tree_pointer)malloc(sizeof(node));
	n5 = (tree_pointer)malloc(sizeof(node));
	n6 = (tree_pointer)malloc(sizeof(node));
	n7 = (tree_pointer)malloc(sizeof(node));
    n8 = (tree_pointer)malloc(sizeof(node));
	n9 = (tree_pointer)malloc(sizeof(node));

    n1->data = 10;
	n1->left_child = n2;
	n1->right_child = n3;

	n2->data = 20;
	n2->left_child = n4;
	n2->right_child = n5;

	n3->data = 30;
	n3->left_child = n6;
	n3->right_child = n7;

	n4->data = 40;
	n4->left_child = n8;
	n4->right_child = n9;

	n5->data = 50;
	n5->left_child = NULL;
	n5->right_child = NULL;

	n6->data = 60;
	n6->left_child = NULL;
	n6->right_child = NULL;

	n7->data = 70;
	n7->left_child = NULL;
	n7->right_child = NULL;

    n8->data = 80;
	n8->left_child = NULL;
	n8->right_child = NULL;
    
    n9->data = 90;
	n9->left_child = NULL;
	n9->right_child = NULL;
    
    return n1;
}

int bt_count(tree_pointer ptr) {
    int cnt = 0;
    if (!ptr) return 0;
    cnt = 1 + bt_count(ptr->left_child) + bt_count(ptr->right_child);
    return cnt;
}

int bt_sum(tree_pointer ptr) {
    int sum = 0;
    if (!ptr) return 0;
    sum += ptr->data + bt_sum(ptr->left_child) + bt_sum(ptr->right_child);
    return sum;
}

int bt_height(tree_pointer ptr) {
    int height = 0;
    if (!ptr) return 0;
    height = 1 + max(bt_height(ptr->left_child), bt_height(ptr->right_child));
	return height;
}

void bt_show_preorder(tree_pointer ptr) {
    if (!ptr) return;
    printf("%d  ", ptr->data);
    bt_show_preorder(ptr->left_child);
    bt_show_preorder(ptr->right_child);
}

void bt_free(tree_pointer ptr) {
    if (!ptr) return;
    bt_free(ptr->left_child);
    bt_free(ptr->right_child);
    printf("free node with item %d\n", ptr->data);
    free(ptr);
}

int main(void) {
    char c;
    int n;
    tree_pointer t;

    t = build_simple_tree();
    printf("************* Command ************\n"); 
    printf("C: Count tree, A: Sum tree data \n"); 
    printf("H: Height of tree, S: Show preorder \n"); 
    printf("F: Free tree, Q: Quit \n"); 
    printf("**********************************\n");

    while (1) { 
        printf("\nCommand> ");
        c = getchar();
        c = toupper(c);
        switch (c) {
            case 'C' : 
                n = bt_count(t);
                printf("\n Total number of node = %d \n", n);
                break;
            case 'A' :
                n = bt_sum(t);
                printf ("\n Sum of tree data = %d \n", n);
                break;
            case 'H' :
                n = bt_height(t);
                printf ("\n Height of tree = %d \n", n);
                break;
            case 'S' : 
                printf ("\n");
                bt_show_preorder(t); 
                printf ("\n");
                break;
            case 'F' : 
                printf ("\n"); 
                bt_free(t);
            case 'Q' : 
                printf("\n");
                exit(1); 
            default : break;
        }
        fflush(stdin);
    }
}