https://takeuforward.org/data-structure/minimum-path-sum-in-triangular-grid-dp-11/
https://www.geeksforgeeks.org/minimum-sum-path-triangle/

#include <bits/stdc++.h>

using namespace std;

int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, 
vector<vector<int> > &dp) {
  
  if(dp[i][j]!=-1)
  return dp[i][j];
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return minimumPathSumUtil(0,0,triangle,n,dp);
    
}

int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}
/*
Output: 14

Time Complexity: O(N*N)

Reason: At max, there will be (half of, due to triangle) N*N calls of recursion.

Space Complexity: O(N) + O(N*N)

Reason: We are using a recursion stack space: O((N), where N is the path length and an external DP Array of size ‘N*N’.
