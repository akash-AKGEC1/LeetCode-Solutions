/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char** result = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        result[i] = malloc((n + 1) * sizeof(char));

        for (int j = 0; j < n; j++) {
            if (j == 0 || i == m - 1) {
                result[i][j] = '.';
            } else {
                result[i][j] = '#';
            }
        }

        result[i][n] = '\0';
    }

    *returnSize = m;
    return result;
}