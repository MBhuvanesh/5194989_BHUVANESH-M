#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

typedef struct {
    char *text;
} State;

int main() {
    int Q;
    scanf("%d", &Q);

    char *s = calloc(MAX, sizeof(char));
    int len = 0;

    State stack[Q];
    int top = -1;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char w[100000];
            scanf("%s", w);
            stack[++top].text = strdup(s);
            int wlen = strlen(w);
            strcpy(s + len, w);
            len += wlen;
        }
        else if (type == 2) {
            int k;
            scanf("%d", &k);
            stack[++top].text = strdup(s);
            len -= k;
            s[len] = '\0';
        }
        else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", s[k - 1]);
        }
        else if (type == 4) {
            free(s);
            s = stack[top].text;
            len = strlen(s);
            top--;
        }
    }

    return 0;
}
