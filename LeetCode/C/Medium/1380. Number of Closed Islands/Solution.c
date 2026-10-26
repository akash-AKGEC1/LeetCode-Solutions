void dfs(int i, int j, int** grid, int n, int m){
    if(i<0 || j<0 ||i>=n||j>=m){
        return ;
    }
     if (grid[i][j] == 1)
      return;
   
    grid[i][j]=1;
    // dfs call karege bgl me left side  ke liye 
    dfs(i-1,j,grid,n,m);
    //  dfs call karee right side ke liye ahar to nahi chali gayi  

     dfs(i+1,j,grid,n,m);
     // dfs call karenge upper to nahi nikal agyii 

      dfs(i,j-1,grid,n,m);
// dfs ko call karege kahni niche to nahi nikal rahne 
       dfs(i,j+1,grid,n,m);
}
int closedIsland(int** grid, int gridSize, int* gridColSize) {
    int n=gridSize;
    int m = gridColSize[0];
    int count = 0 ; 
    // vertical  check karega 
    for(int i= 0; i< n ;i++){
        dfs(i,0,grid,n,n);
        dfs(i,m-1,grid,n,m);
    }
    // horizontal check karega 
    for(int j=0;j<m;j++){
        dfs(0,j,grid,n,m);
        dfs(n-1,j,grid,n,m);
    }
    //treverse karenge 
    for(int i = 1 ; i<n;i++){
        for(int j = 1 ; j<m;j++){
            if(grid [i][j]==0)
            count ++;
            dfs (i,j,grid,n,m);
        }
    }
    return count ; 
}