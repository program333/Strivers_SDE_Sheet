https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
     bool check(vector<int>& nums) {
        
        int size = nums.size();
        int count = 0;

        for(int x=0; x<size; x++)
        {   
            if(nums[x] > nums[(x+1)%size])
                count ++;
        }
        return (count <= 1);
    }
};
