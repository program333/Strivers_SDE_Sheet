https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/

#include<bits/stdc++.h>

using namespace std;
int maxSubArray(vector < int > & nums, vector < int > & subarray) {
  int max_sum = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    int curr_sum = 0;
    for (int j = i; j < nums.size(); j++) {
      curr_sum += nums[j];
      if (curr_sum > max_sum) {
        subarray.clear();
        max_sum = curr_sum;
        subarray.push_back(i);
        subarray.push_back(j);
      }
    }
  }
  return max_sum;
}

int main() {
  vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
  vector < int > subarray;
  int lon = maxSubArray(arr, subarray);
  cout << "The longest subarray with maximum sum is " << lon << endl;
  cout << "The subarray is " << endl;
  for (int i = subarray[0]; i <= subarray[1]; i++) {
    cout << arr[i] << " ";
  }

}
/*
Output:

The longest subarray with maximum sum is 6
The subarray is
4 -1 2 1

Time Complexity: O(N^2) 

Space Complexity: O(1)

*/


https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

// C++ program to print largest contiguous array sum
#include <iostream>  
using namespace std;
// Function that finds the largest sum contiguous array  
int maxSubArraySum(int a[], int size)  
{  
    int current_sum = 0, maximum_sum =0,start = 0, end = 0, s = 0;;  
   
    for (int i = 0; i < size; i++)  
    {  
        current_sum = current_sum + a[i];  
        if (current_sum > maximum_sum){  
           maximum_sum = current_sum; 
           start = s;
           end = i;
        }
   
        if (current_sum < 0)  {
           current_sum = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << maximum_sum
         << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end << endl;
         
    return maximum_sum;  
}  
// main method  
int main()  
{  
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a)/sizeof(a[0]);  
    maxSubArraySum(a, n);  
 
    return 0;  
}  
/*
Time Complexity: O(N), where N = size of the array.
Reason: We are using a single loop running N times.

Space Complexity: O(1) as we are not using any extra space.
*/
