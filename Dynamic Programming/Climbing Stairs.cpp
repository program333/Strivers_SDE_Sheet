https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
https://www.geeksforgeeks.org/count-ways-reach-nth-stair/


// C++ program to count number of ways to reach Nth stair
#include <bits/stdc++.h>
using namespace std;

// A simple recursive program to find N'th fibonacci number
int fib(int n, int dp[])
{
	if (n <= 1)
		return dp[n] = 1;

	if (dp[n] != -1) {
		return dp[n];
	}
	dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
	return dp[n];
}

// Returns number of ways to reach s'th stair
int countWays(int n)
{
	int dp[n + 1];
	memset(dp, -1, sizeof dp);
	fib(n, dp);
	return dp[n];
}

// Driver C
int main()
{
	int n = 4;
	cout << "Number of ways = " << countWays(n);
	return 0;
}
/*
Output
Number of ways = 5
Complexity Analysis:

Time Complexity: O(n)

Auxiliary Space: O(n)
*/
