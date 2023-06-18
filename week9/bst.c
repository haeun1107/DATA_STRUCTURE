#include "bst.h"

int main(void) {
    char c, grade;
    int id;

    printf("************* Command ************\n"); 
    printf("I: Insert data, S: Search data \n");
    printf("P: Print inorder, Q: Quit \n"); 
    printf("**********************************\n");

    while (1) {
        printf("\nCommand> "); 
        c = getchar();
        c = toupper(c); 
        switch (c) {
            case 'I': 
                printf("\n id and grade: "); 
                scanf("%d %c", &id, &grade);
                bst_insert(id, grade); 
                break;
            case 'S':
                printf("\n id: ");
                scanf("%d", &id);
                grade = bst_search(id);
                if (grade) printf(" Grade of %d: %c \n", id, grade); 
                else printf(" No such id ! \n"); 
                break;
            case 'P':
                printf("\n");
                bst_show_inorder(root);
                break;
            case 'Q':
                printf("\n");
                exit(1);
            default: break;
        }
        fflush(stdin);
    }
}

void bst_insert(int key, char data) {
    tree_pointer a, b, temp;

    a = NULL;
    b = root;

    while (b != NULL) {
        if (key == b->key) return;
        a = b;
        if (key < b->key) b = b->left;
        else b = b->right;
    }

    temp = (tree_pointer)malloc(sizeof(tree_node));
    temp->key = key;
    temp->data = data;
    temp->left = temp->right = NULL;

    if (a != NULL) {
        if (key < a->key) a->left = temp;
        else a->right = temp;
    }
    else
        root = temp;
}

char bst_search(int key) {
    tree_pointer ptr = root;

    while (ptr != NULL) {
        if (key == ptr->key) return ptr->data;   // key is found
        if (key < ptr->key) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return '\0';
}

void bst_show_inorder(tree_pointer ptr)
{
    if (ptr == NULL) return;
    bst_show_inorder(ptr->left);
    printf(" %d %c \n", ptr->key, ptr->data);
    bst_show_inorder(ptr->right);
}

