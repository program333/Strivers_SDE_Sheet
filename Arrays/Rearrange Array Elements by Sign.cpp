https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p,ne,r;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                p.push_back(nums[i]);
            }else{
                ne.push_back(nums[i]);
            }
        }

        int pl=p.size();
        int nl = ne.size();

        for(int i=0;i<pl && i<nl; i++){
           
               r.push_back(p[i]);
          

          
                 r.push_back(ne[i]);
          
        }
       return r; 
    }
};
