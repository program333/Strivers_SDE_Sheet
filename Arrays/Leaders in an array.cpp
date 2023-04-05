https://www.geeksforgeeks.org/leaders-in-an-array/
https://takeuforward.org/data-structure/leaders-in-an-array/


#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeadersBruteForce(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}
/*

Output:

22 12 6

Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.
Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.

*/



#include <bits/stdc++.h>
using namespace std;
	
/* C++ Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
	/* create stack to store leaders*/
	stack<int> sk;
	sk.push(arr[size-1]);
	
	for (int i = size-2; i >= 0; i--)
	{
		if(arr[i] >= sk.top())
		{		
			sk.push(arr[i]);
		}
	}
	
	/* print stack elements*/
	/* run loop till stack is not empty*/
	while(!sk.empty()){	
		cout<<sk.top()<<" ";
		sk.pop();
	}
}
	
/* Driver program to test above function*/
int main()
{
	int arr[] = {16, 17, 4, 3, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	printLeaders(arr, n);
	return 0;
}

/*
Output
17 5 2 
Time complexity: O(n)
Auxiliary space: O(n)
*/
