https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/
https://takeuforward.org/data-structure/minimum-insertions-deletions-to-convert-string-dp-30/

#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2) {
    
    int n=s1.size();
    int m=s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}

int canYouMake(string str1, string str2){
    
    int n = str1.size();
    int m = str2.size();
    
    int k = lcs(str1,str2);
    
    return (n-k)+(m-k);
}

int main() {

  string str1= "abcd";
  string str2= "anc";
                                 
  cout<<"The Minimum operations required to convert str1 to str2: "<<
  canYouMake(str1,str2);
}
/*
Output:

The Minimum operations required to convert str1 to str2: 3

Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size (N*M). Stack Space is eliminated.
*/


// Dynamic Programming C++ implementation to find
// minimum number of deletions and insertions
// using memoization technique
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

// Returns length of longest common subsequence
int lcs(string& s1, string& s2, int i, int j)
{
	if (i == 0 || j == 0) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (s1[i - 1] == s2[j - 1]) {
		return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1);
	}
	else {
		return dp[i][j] = max(lcs(s1, s2, i, j - 1),
							lcs(s1, s2, i - 1, j));
	}
}

// function to find minimum number
// of deletions and insertions
void printMinDelAndInsert(string str1, string str2)
{
	int m = str1.size();
	int n = str2.size();

	dp[m][n];

	// initialising dp array as -1
	memset(dp, -1, sizeof(dp));

	int len = lcs(str1, str2, m, n);

	cout << "Minimum number of deletions = " << (m - len)
		<< endl;

	cout << "Minimum number of insertions = " << (n - len)
		<< endl;
}

// driver code
int main()
{
	string str1 = "heap";
	string str2 = "pea";

	// Function Call
	printMinDelAndInsert(str1, str2);

	return 0;
}

/*
Output
Minimum number of deletions = 2
Minimum number of insertions = 1
Time Complexity: O(m * n)
Auxiliary Space: O(m * n)
*/
