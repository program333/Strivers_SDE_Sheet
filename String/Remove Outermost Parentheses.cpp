https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
       string removeOuterParentheses(string S) {
        stack<char>s;
        string res="";
        for(char c:S){
            if(c=='('){
                if(s.size()>0){
                    res+=c;
                }
                s.push(c);
            }
            else{
                s.pop();
                if(s.size()>0){
                    res+=c;
                }
            }
        }
        return res;
    }
};
