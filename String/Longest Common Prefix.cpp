https://leetcode.com/problems/longest-common-prefix/description/
https://www.geeksforgeeks.org/longest-common-prefix-using-sorting/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        if(n==0){
            return "";
        }
        string common="";
        sort(strs.begin(),strs.end());

        string a=strs[0];
        string b=strs[n-1];

        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]){
                common+=a[i];
            }else{
                break;
            }
        }
        return common;
        
    }
};
