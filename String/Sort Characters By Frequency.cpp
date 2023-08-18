https://leetcode.com/problems/sort-characters-by-frequency/
/*
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/
class Solution {
public:
     static bool cmp(pair<char,int>&a,pair<char,int>&b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        for(char ch:s)  mp[ch]++;
        vector<pair<char,int>>res;
        for(auto it:mp) res.push_back(it);
        sort(res.begin(),res.end(),cmp);
        string out="";
        for(auto it:res){
            int tmp = it.second;
            while(tmp--){
                out+=it.first;
            }
        }
        return out;
    }
};
