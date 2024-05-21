
Program to generate Pascal’s Triangle
Problem Statement: This problem has 3 variations. They are stated below:
Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
--------------------------------------------------------------------------------  
vector<vector<int>> generate(int numRows) 
     {
        vector<vector<int>> ans(numRows);
        
        for(int i = 0 ; i < numRows ; i++)
        {
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            
            for(int j = 1 ; j < i ; j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];    
            }
        }
        
        return ans;
    }
