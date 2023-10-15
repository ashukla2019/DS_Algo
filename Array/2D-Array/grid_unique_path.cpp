Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell 
you can either only move to the rightward direction or the downward direction.
Ex:
Input Format: m = 2, n= 2
Output: 2  
---------------------------------------------------------------------------------------------------
 Recursion:
  
  #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int countPaths(int i,int j,int n,int m)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
       return countPaths(0,0,m,n);
    }
};
int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}
Time Complexity: The time comp[lexity of this recursive solution is exponential.
Space Complexity: As we are using stack space for recursion so the space complexity will also be exponential.
  ------------------------------------------------------------------------------------------------------------------------
  Solution 2: Dynamic Programming Solution:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
    }
};
int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths(3,7);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}
Time Complexity: The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
Space Complexity: As we are using extra space for the dummy matrix the space complexity will also be O(n*m).
-----------------------------------------------------------------------------------------------------------------------------------
Solution 3: Combinatorics Solution

Intuition: If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.

From start to reach the end we need a certain number of rightward directions and a certain number of downward directions. So we can figure out we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.
Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.
Approach: The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1   

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};
int main()
{
    Solution obj;
    int totalCount= obj.uniquePaths(2,3);
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
}
Time Complexity: The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.
Space Complexity: As we are not using any extra space the space complexity of the solution will be  O(1).


