/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land)
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the
grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

*/


int dfs(vector<vector<int>>&grid,int i,int j,int n,int m)
{
//checking corner cases for moving in 4 direction up down left right
	if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1)
	{
		grid[i][j]=0;//updating grid value
		//counting all the island  
		return 1+ dfs(grid,i+1,j,n,m)+dfs(grid,i-1,j,n,m)+dfs(grid,i,j+1,n,m)+dfs(grid,i,j-1,n,m);
		
	}
	return 0;
}
    
    
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
        
	int max_area=0;
	int n=grid.size();
	int m=grid[0].size();
	//moving every point of grid  and updating its value when you travelled
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==1)
			{
				int count=dfs(grid,i,j,n,m);
				//finding maximum area
				max_area=max(max_area,count);
			}
		}
	}
	return max_area;
}