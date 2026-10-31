#define MOD 1000000007

int uniquePaths(int** grid, int gridSize, int* gridColSize) {

    int m = gridSize;
    int n = gridColSize[0];

    int stride = n + 1;
    int size = (m + 1) * (n + 1);

    int *right = calloc(size, sizeof(int));
    int *down = calloc(size, sizeof(int));

    for (int i = m - 1; i >= 0; i--) {

        for (int j = n - 1; j >= 0; j--) {

            int idx = i * stride + j;

            int ways;

            // Destination
            if (i == m - 1 && j == n - 1) {
                ways = 1;
            }
            else {
                ways = (right[idx + 1] +
                        down[idx + stride]) % MOD;
            }

            if (grid[i][j] == 0) {

                right[idx] = ways;
                down[idx] = ways;

            }
            else {

                // Entered from right -> reflect down
                right[idx] = down[idx + stride];

                // Entered from down -> reflect right
                down[idx] = right[idx + 1];

            }
        }
    }

    if (m == 1 && n == 1) {
        free(right);
        free(down);
        return 1;
    }

    int ans = (right[1] + down[stride]) % MOD;

    free(right);
    free(down);

    return ans;
}