/*
Problem Number: 20
Problem Name: Valid Parentheses

LeetCode Link:
https://leetcode.com/problems/valid-parentheses/

Difficulty: Easy

Topics:
String, Stack

Approach:
We need to determine whether the input string contains
valid and correctly matched parentheses.

Steps:

1. Use a stack to store opening brackets:
   '(', '[', '{'.

2. Traverse the string character by character.

3. If the current character is an opening bracket,
   push it onto the stack.

4. If the current character is a closing bracket:
   - If the stack is empty, there is no corresponding
     opening bracket, so return false.
   - Check whether the top of the stack is the matching
     opening bracket.
   - If it does not match, return false.
   - Otherwise, remove the opening bracket using pop().

5. After processing the entire string, the stack must be
   empty.

   If it is empty:
       All brackets were correctly matched.

   Otherwise:
       Some opening brackets were left unmatched.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = length of s
*/

class Solution {
public:
    bool isValid(string s) {
        // stack
        stack<char> st;

        for(char ch : s){
            // open
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                //check match
                if((ch == ')' && st.top() != '(') ||
                   (ch == '}' && st.top() != '{') ||
                   (ch == ']' && st.top() != '['))
                   {
                    return false;
                   }
                   st.pop();
            }
        }
        return st.empty();
    }
};
