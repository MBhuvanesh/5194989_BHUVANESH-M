#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int arr[MAX];
    int top;
} Stack;


void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int peek(Stack *s) {
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    int q;
    scanf("%d", &q);

    Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    while (q--) {
        int type, x;
        scanf("%d", &type);

        if (type == 1) {
           
            scanf("%d", &x);
            push(&s1, x);
        } else {
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            if (type == 2) {
                
                pop(&s2);
            } else if (type == 3) {
               
                printf("%d\n", peek(&s2));
            }
        }
    }

    return 0;
}
