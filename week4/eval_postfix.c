#include "eval_postfix.h"

int main() {
    char exp[100]; // postfix expression
    int result;

    while(1) {
        printf("\n Input postfix expression: "); 
        scanf("%s", exp);

        result = eval_postfix(exp);
        if (err_check == false)
            printf(" Result = %d \n\n", result);
    }
}