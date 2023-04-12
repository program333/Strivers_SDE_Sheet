https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

/*
Follow the below steps to Implement the idea:

Create a DP vector of size n+1 and value -1 and variables pick and not pick. 
Create a recursive function 
If n < 0 possible stolen value is 0.
If n = 0 possible stolen value is hval[0].
If DP[n] != -1 possible stolen value is DP[n].
Set pick as pick = hval[n] +  maxLoot(hval, n-2, DP) 
Set not pick as notPick = maxLoot(hval, n-1, DP).
Set Dp[n] = max(pick, notPick) and return DP[n].
*/

// CPP program to find the maximum stolen value
#include <bits/stdc++.h>
using namespace std;

// calculate the maximum stolen value
int maxLoot(int *hval, int n, vector<int> &dp){

// base case
if(n < 0){
		return 0 ;
}
	
if(n == 0){
		return hval[0] ;
}
// If the subproblem is already solved
// then return its value
if(dp[n] != -1 ){
		return dp[n] ;
}

//if current element is pick then previous cannot be picked
int pick = hval[n] + maxLoot(hval, n-2, dp) ;
//if current element is not picked then previous element is picked
int notPick = maxLoot(hval, n-1, dp) ;

// return max of picked and not picked
return dp[n] = max(pick, notPick) ;

}

// Driver to test above code
int main()
{
	int hval[] = {6, 7, 1, 3, 8, 2, 4};
	int n = sizeof(hval)/sizeof(hval[0]);
	// Initialize a dp vector
	vector<int> dp(n+1, -1) ;
	cout << "Maximum loot possible : "
		<< maxLoot(hval, n-1, dp);
	return 0;
}

/*
Output
Maximum loot possible : 19
Time Complexity: O(n). Only one traversal of the original array is needed. So the time complexity is O(n)
Space Complexity: O(n). Recursive stack space is required of size n, so space complexity is O(n).
*/
