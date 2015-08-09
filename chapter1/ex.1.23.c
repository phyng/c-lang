#include <stdio.h>

// 移除所有注释
/* 包括单行
    和多行 */

#define MAX 10000
#define SLASH '/'
#define ASTERISK '*'
#define BACKSLASH '\\'
#define S_QUOTE '\''
#define D_QUOTE '"'

#define OUT 0
#define IN_S_QUOTE 1
#define IN_D_QUOTE 2
#define IN_S_ESCAPE 3
#define IN_D_ESCAPE 4
#define IN_COMMENT 5
#define IN_INLINE_COMENT 6

// test inline comment

/* test multiple comment

*/

void print_line(char line[]) {
    int i;
    for (i = 0; line[i] != '\0'; ++i) {
        putchar(line[i]);
    }
}

main () {
    int c;
    char s[MAX];
    char result[MAX];
    int i = 0;
    int j = 0;
    int prev = '\0';
    int prev_2 = '\0';
    int state = OUT;
    int prev_state = OUT;
    while ((c = getchar()) != EOF) {
        s[i] = c;

        switch (state) {
            case OUT:
                if (c == '\'') {
                    state = IN_S_QUOTE;
                }
                else if (c == '"') {
                    state = IN_D_QUOTE;
                }
                else if (c == '/' && prev == '/') {
                    state = IN_INLINE_COMENT;
                }
                else if (c == '*' && prev == '/'){
                    state = IN_COMMENT;
                }
                break;
            case IN_S_QUOTE:
                if (c == '\\') {
                    state = IN_S_ESCAPE;
                }
                else if (c == '\'') {
                    state = OUT;
                }
                break;
            case IN_D_QUOTE:
                if (c == '\\') {
                    state = IN_D_ESCAPE;
                }
                else if (c == '\"') {
                    state = OUT;
                }
                break;
            case IN_S_ESCAPE:
                state = IN_S_QUOTE;
                break;
            case IN_D_ESCAPE:
                state = IN_D_QUOTE;
                break;
            case IN_INLINE_COMENT:
                if (c == '\n') {
                    state = OUT;
                }
                break;
            case IN_COMMENT:
                if (c == '/' && prev == '*') {
                    state = OUT;
                }
                break;
        }


        switch (state) {
            case IN_INLINE_COMENT:
                if (prev_state != IN_INLINE_COMENT) {
                    --j;
                }
                break;
            case IN_COMMENT:
                if (prev_state != IN_COMMENT) {
                    --j;
                }
                break;
            default:
                if (prev_state == IN_COMMENT) {
                    --j;
                }
                else {
                    result[j] = c;
                    ++j;
                }
                break;
        }

        prev_2 = prev;
        prev = c;
        prev_state = state;
        ++i;
    }
    result[j] = '\0';
    printf("========== OUT ==========\n");
    print_line(result);

}
