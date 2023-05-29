https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/

/*
Efficient Approach: The idea is to use the Kadane’s Algorithm to find the maximum subarray sum and store the starting and ending index of the
subarray having maximum sum and print the subarray from starting index to ending index. Below are the steps:

Initialize 3 variables endIndex to 0, currMax, and globalMax to first value of the input array.
For each element in the array starting from index(say i) 1, update currMax to max(nums[i], nums[i] + currMax) and globalMax and endIndex to i only if currMax > globalMax.
To find the start index, iterate from endIndex in the left direction and keep decrementing the value of globalMax until it becomes 0. The point at which it becomes 0 is the start index.
Now print the subarray between [start, end].
*/



#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& nums) {
       int max_sum=INT_MIN;
       int curr_sum=0;
       int start=0,end=0,s=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
            curr_sum+=nums[i];

            if(curr_sum>max_sum){
                max_sum = curr_sum;
                start = s;
                end = i;
            }

            if(curr_sum<0){
                curr_sum=0;
                s = i+1;
            }
       }
       
       for(int i=start;i<=end;i++){
           cout<<nums[i]<<" ";
       }
       
    }

// Driver Code
int main()
{
	// Given array arr[]
	vector<int> arr
		= { -2, -3, 4, -1, -2, 1, 5, -3 };

	// Function call
	maxSubArray(arr);
	return 0;
}

	

/*
Output
6 -2 -3 1 5 
Time complexity: O(N) 
Auxiliary Space: O(1)
*/
