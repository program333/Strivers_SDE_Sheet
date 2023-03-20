
https://www.geeksforgeeks.org/number-nges-right/

// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find number of next
// greater elements on the right of
// a given element
int nextGreaterElements(vector<int>& a, int index)
{
	int count = 0, N = a.size();
	for (int i = index + 1; i < N; i++)
		if (a[i] > a[index])
			count++;

	return count;
}

// Driver's code
int main()
{

	vector<int> a = { 3, 4, 2, 7, 5, 8, 10, 6 };
	int Q = 2;
	vector<int> queries = { 0, 5 };

	for (int i = 0; i < Q; i++)
		// Function call
		cout << nextGreaterElements(a, queries[i]) << " ";

	return 0;
}

/*
Output
6 1 
Time Complexity: O(NQ), and O(N) to answer a single query
Auxiliary space: O(1) 
*/



class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
    
     vector<int>v;
     for(int i=0;i<queries;i++){
         int count=0;
       for (int j = indices[i]+1; j < n; j++)
          if (arr[j] > arr[indices[i]]){
            count++;
          }
         v.push_back(count);
       
     }
     return v;
    
    }

};
