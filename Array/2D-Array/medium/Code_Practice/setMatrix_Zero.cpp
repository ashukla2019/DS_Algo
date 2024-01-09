/*
Time complexity: O(n2)
Space complexity: O(n)
*/  
void setZeroes(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row;
        vector<int>col;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==0)
                {
                    // mark ith index of row wih 1:
                    row.push_back(i);
                    // mark jth index of col wih 1:
                    col.push_back(j);
                }
            }
        }
       for(auto it: row)
       {
           for(int i=0; i<m; i++)
           {
               matrix[it][i]=0;
           }
       }

       for(auto it: col)
       {
           for(int i=0; i<n; i++)
           {
               matrix[i][it]=0;
           }
       }
        
    }
