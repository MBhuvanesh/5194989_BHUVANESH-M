#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char **data;
    int top;
} Stack;

void push(Stack *stack, const char *s) {
    stack->top++;
    stack->data[stack->top] = malloc(strlen(s)+1);
    strcpy(stack->data[stack->top], s);
}

void pop(Stack *stack, char *s) {
    strcpy(s, stack->data[stack->top]);
    free(stack->data[stack->top]);
    stack->top--;
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[100001] = ""; 
    Stack stack;
    stack.data = malloc(Q * sizeof(char*));
    stack.top = -1;

    for(int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);
        if(type == 1) { 
            char str[100001];
            scanf("%s", str);
            push(&stack, S);
            strcat(S, str);
        }
        else if(type == 2) { 
            int k;
            scanf("%d", &k);
            push(&stack, S);
            S[strlen(S)-k] = '\0';
        }
        else if(type == 3) { 
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k-1]);
        }
        else if(type == 4) { 
            pop(&stack, S);
        }
    }

    
    while(stack.top >= 0) {
        free(stack.data[stack.top]);
        stack.top--;
    }
    free(stack.data);

    return 0;
}

