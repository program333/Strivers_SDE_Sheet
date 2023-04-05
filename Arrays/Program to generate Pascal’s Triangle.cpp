https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};



/*
Input Format: N = 5

Result:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.
*/

// C++ program for Pascal’s Triangle
// A O(n^2) time and O(1) extra space
// function for Pascal's Triangle
#include <bits/stdc++.h>

using namespace std;
void printPascal(int n)
{
	
for (int line = 1; line <= n; line++)
{
	int C = 1; // used to represent C(line, i)
	for (int i = 1; i <= line; i++)
	{
		
		// The first value in a line is always 1
		cout<< C<<" ";
		C = C * (line - i) / i;
	}
	cout<<"\n";
}
}

// Driver code
int main()
{
	int n = 5;
	printPascal(n);
	return 0;
}

/*
Time Complexity: O(n2)
Auxiliary Space: O(1)
*/
