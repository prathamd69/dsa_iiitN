#include <stdio.h>
#include <stdbool.h>

void push(int *top, int n, char stack[], char data) {
    if (*top == n - 1) {
        printf("Overflow\n");
    } else {
        (*top)++;
        stack[*top] = data;
    }
}


bool is_palindrome(){
    int n = 8;
    char stack1[n];
    char stack2[n];
    int top1 = -1;
    int top2 = -1;
    
    push(&top1,n,stack1,'a');
    push(&top1,n,stack1,'a');
    push(&top1,n,stack1,'b');
    push(&top1,n,stack1,'b');
    push(&top1,n,stack1,'b');
    push(&top1,n,stack1,'a');
    push(&top1,n,stack1,'a');
    push(&top1,n,stack1,'a');
    
    int track = top1;
    
    while (track != -1){
        push(&top2,n,stack2,stack1[track]);
        track--;
    }
    
    for (int i = top1 ; i >=0 ; i--){
        if (stack1[top1] != stack2[top2]){
            return false;
        }
        top1--;
        top2--;
    }
    return true;
    
    
}

int main() {
    if (is_palindrome()) {
        printf("The sequence is a palindrome.\n");
    } else {
        printf("The sequence is not a palindrome.\n");
    }
    return 0;
}



