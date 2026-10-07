/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

char **ans;
int ansSize;
char *temp;
char *str;

void backtrack(int i, int left, int right, int balance, int pos) {

    if (str[i] == '\0') {

        if (left == 0 && right == 0 && balance == 0) {

            temp[pos] = '\0';

            // check duplicate
            for (int j = 0; j < ansSize; j++) {
                if (strcmp(ans[j], temp) == 0) {
                    return;
                }
            }

            ans[ansSize] = malloc((pos + 1) * sizeof(char));
            strcpy(ans[ansSize], temp);

            ansSize++;
        }

        return;
    }

    // '('
    if (str[i] == '(') {

        // remove
        if (left > 0) {
            backtrack(i + 1, left - 1, right, balance, pos);
        }

        // keep
        temp[pos] = '(';

        backtrack(i + 1, left, right, balance + 1, pos + 1);
    }

    // ')'
    else if (str[i] == ')') {

        // remove
        if (right > 0) {
            backtrack(i + 1, left, right - 1, balance, pos);
        }

        // keep
        if (balance > 0) {

            temp[pos] = ')';

            backtrack(i + 1, left, right, balance - 1, pos + 1);
        }
    }

    // letter
    else {

        temp[pos] = str[i];

        backtrack(i + 1, left, right, balance, pos + 1);
    }
}


char** removeInvalidParentheses(char* s, int* returnSize) {

    int n = strlen(s);

    int left = 0;
    int right = 0;

    // minimum removals find karo
    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            left++;
        }
        else if (s[i] == ')') {

            if (left > 0) {
                left--;
            }
            else {
                right++;
            }
        }
    }

    ans = malloc(10000 * sizeof(char*));
    temp = malloc((n + 1) * sizeof(char));

    str = s;
    ansSize = 0;

    backtrack(0, left, right, 0, 0);

    *returnSize = ansSize;

    free(temp);

    return ans;
}