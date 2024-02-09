Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to 
set its entire column and row to 0 and then return the matrix.
Examples 1:
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
 
Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0  
------------------------------------------------------------------------------------
/*
Time complexity: O(n2)
Space complexity: O(n)
*/  
void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();//row
        int m=mat[0].size();//col
        vector<int> row(n);
        vector<int> col(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){ //marking the whole row as 0
            if(row[i]==1){
                for(int j=0;j<m;j++){
                    mat[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){ //marking the whole column as 0
            if(col[j]==1){
                for(int i=0;i<n;i++){
                    mat[i][j]=0;
                }
            }
        }
    }
