/*
Problem Number: 32
Problem Name: Longest Valid Parentheses

LeetCode Link:
https://leetcode.com/problems/longest-valid-parentheses/

Difficulty: Hard

Topics:
String, Stack, Dynamic Programming

Approach:
We need to find the length of the longest substring
containing valid and correctly matched parentheses.

Steps:

1. Use a stack to store indices of unmatched opening
   parentheses.

2. Push -1 initially as a base index. This helps calculate
   the length of a valid substring starting from index 0.

3. Traverse the string from left to right.

4. If the current character is '(':
   - Push its index onto the stack.

5. If the current character is ')':
   - Pop the top index because we are trying to match it
     with an opening parenthesis.
   - If the stack becomes empty:
       Push the current index as the new base index.
       This means the current ')' cannot be part of any
       valid substring extending beyond this position.
   - Otherwise:
       The current valid substring length is:
       current index - index at the top of the stack.
       Update maxlen with the maximum value.

6. Return maxlen after processing the complete string.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = length of s
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);

        int maxlen=0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxlen = max(maxlen, i-st.top());
                }
            }
        }
        return maxlen;
    }
};
