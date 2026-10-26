long long dfs(int i, int j, int** grid, int m, int n) {
    // boundry check karega  (  boundry pe nahi check kregea )
    if (i < 0 || j < 0 || i >= m || j >= n)
        return 0;

    if (grid[i][j] == 0)
        return 0;
//conitnuty check karega yee 
    long long sum = grid[i][j];
    grid[i][j] = 0;

    sum += dfs(i - 1, j, grid, m, n);
    sum += dfs(i + 1, j, grid, m, n);
    sum += dfs(i, j - 1, grid, m, n);
    sum += dfs(i, j + 1, grid, m, n);

    return sum;
}

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize;
    int n = gridColSize[0];
    int count = 0;
// treverse
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) {
                long long sum = dfs(i, j, grid, m, n);

                if (sum % k == 0)
                    count++;
            }
        }
    }

    return count;
}