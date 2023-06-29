https://takeuforward.org/data-structure/maximum-product-subarray-in-an-array/

https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxProd=arr[0];
	    int minval=arr[0],maxval=arr[0];
        int n=arr.size();
	    
	    for(int i=1;i<n;i++){
	        if(arr[i]<0){
	            swap(minval,maxval);
	        }
	        
	        minval=min(arr[i],arr[i]*minval);
	        maxval=max(arr[i],arr[i]*maxval);
	        
	        maxProd = max(maxProd,maxval);
	    }
	    
	    return maxProd;
    }
};


#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

/*
Output: The maximum product subarray: 20

Time Complexity: O(N2)

Reason: We are using two nested loops

Space Complexity: O(1)

Reason: No extra data structures are used for computation
*/

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

/*
Output: The maximum product subarray: 20

Time Complexity: O(N)

Reason: A single iteration is used.

Space Complexity: O(1)

Reason: No extra data structure is used for computation
*/
