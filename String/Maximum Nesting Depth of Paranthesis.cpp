https://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string/

class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for (char& c: s) {
            if (c == '(')
                res = max(res, ++cur);
            if (c == ')')
                cur--;
        }
        return res;
    }
};

// A C++ program to find the maximum depth of nested
// parenthesis in a given expression
#include <iostream>
using namespace std;

// function takes a string and returns the
// maximum depth nested parenthesis
int maxDepth(string S)
{
	int current_max = 0; // current count
	int max = 0; // overall maximum count
	int n = S.length();

	// Traverse the input string
	for (int i = 0; i < n; i++)
	{
		if (S[i] == '(')
		{
			current_max++;

			// update max if required
			if (current_max > max)
				max = current_max;
		}
		else if (S[i] == ')')
		{
			if (current_max > 0)
				current_max--;
			else
				return -1;
		}
	}

	// finally check for unbalanced string
	if (current_max != 0)
		return -1;

	return max;
}

// Driver program
int main()
{
	string s = "( ((X)) (((Y))) )";
	cout << maxDepth(s);
	return 0;
}


/*
Output
4
Time Complexity: O(n) where n is number of elements in given string. As, we are using a loop to traverse N times so it will cost us O(N) time.
Auxiliary Space: O(1), as we are not using any extra space.
*/
