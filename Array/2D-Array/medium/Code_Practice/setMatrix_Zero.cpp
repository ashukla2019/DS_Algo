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
