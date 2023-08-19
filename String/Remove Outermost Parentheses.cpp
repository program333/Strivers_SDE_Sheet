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

/*
Complexity
Time complexity:
The time complexity of this solution is O(n), where n is the length of the input string. This is because each character in the string is processed once and the push and pop operations on the stack take O(1) time each.

Space complexity:
The space complexity of this solution is O(n), where n is the length of the input string. This is because the maximum size of the stack is n/2 (if all the parentheses are opening parentheses), and in the worst case, the result string can also have a size of n/2.
*/
