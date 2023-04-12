https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/
https://takeuforward.org/data-structure/longest-palindromic-subsequence-dp-28/

// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence
// in seq
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

// Returns the length of the longest palindromic subsequence
// in seq
int lps(string& s1, string& s2, int n1, int n2)
{
	if (n1 == 0 || n2 == 0) {
		return 0;
	}
	if (dp[n1][n2] != -1) {
		return dp[n1][n2];
	}
	if (s1[n1 - 1] == s2[n2 - 1]) {
		return dp[n1][n2] = 1 + lps(s1, s2, n1 - 1, n2 - 1);
	}
	else {
		return dp[n1][n2] = max(lps(s1, s2, n1 - 1, n2),
								lps(s1, s2, n1, n2 - 1));
	}
}

/* Driver program to test above functions */
int main()
{
	string seq = "GEEKSFORGEEKS";
	int n = seq.size();
	dp[n][n];
	memset(dp, -1, sizeof(dp));
	string s2 = seq;
	reverse(s2.begin(), s2.end());
	cout << "The length of the LPS is "
		<< lps(s2, seq, n, n) << endl;
	return 0;
}
/*
Output
The length of the LPS is 5
Time Complexity: O(n2)
Auxiliary Space: O(n2)
*/



// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
	return 1;

// Base Case 2: If there are only 2
// characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
	return 2;

// If the first and last characters match
if (seq[i] == seq[j])
	return lps (seq, i+1, j-1) + 2;

// If the first and last characters do not match
return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKSFORGEEKS";
	int n = strlen(seq);
	cout << "The length of the LPS is "
		<< lps(seq, 0, n-1);
	return 0;
}

/*
Time complexity: The time complexity of the above algorithm is exponential O(2^n), where ‘n’ is the length of the input sequence.

Space complexity: The space complexity of the above algorithm is O(n^2) as we are using a 2D array to store the subproblems solutions.
*/
