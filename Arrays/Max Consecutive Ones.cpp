https://leetcode.com/problems/max-consecutive-ones/description/

/*
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int onecount=0;
        int maxone=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                onecount++;
                if(onecount>maxone){
                    maxone=onecount;
                }
            }else{
                onecount=0;
            }
        }
        return maxone;
    }
};
