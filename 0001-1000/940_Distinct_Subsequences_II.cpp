/*
Problem Number: 940
Problem Name: Distinct Subsequences II

LeetCode Link:
https://leetcode.com/problems/distinct-subsequences-ii/

Difficulty: Hard

Topics:
Dynamic Programming, String

Approach:
We need to count the number of distinct non-empty
subsequences of string s.

The main difficulty is handling duplicate subsequences
created when the same character appears multiple times.

Steps:

1. Let dp[i] represent the number of distinct subsequences
   (including the empty subsequence) that can be formed using
   the first i characters of s.

2. Initially:

   dp[0] = 1

   because the empty string is one subsequence.

3. For every character s[i-1], we have two choices:

   - Do not include the current character.
   - Include the current character in every existing
     subsequence.

   Therefore, without considering duplicates:

   dp[i] = 2 * dp[i - 1]

4. However, if the current character has appeared before,
   some subsequences are duplicated.

   last[c] stores the value of dp from before the previous
   occurrence of character c.

   These duplicated subsequences must be removed:

   dp[i] = 2 * dp[i - 1] - last[c]

5. After processing the current character, update:

   last[c] = dp[i - 1]

   because all subsequences that existed before the current
   character can now be extended using this character.

6. All calculations are performed modulo 10^9 + 7.

7. dp includes the empty subsequence, but the problem asks
   for non-empty subsequences.

   Therefore, subtract 1 from the final result.

Time Complexity:
O(n)

Space Complexity:
O(n)

where:
n = length of s
*/

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        // dp[i] = number of distinct subsequences (including empty)
        // using the first i characters.
        vector<long long> dp(s.size() + 1);
        dp[0] = 1; // empty subsequence
        
        // Last contribution of each character
        vector<long long> last(26, 0);
        
        for (int i = 1; i <= s.size(); i++) {
            int c = s[i - 1] - 'a';
            
            // Every previous subsequence can either:
            // 1. Not take s[i-1]
            // 2. Take s[i-1]
            //
            // But last[c] represents subsequences that would
            // be duplicated by adding this character again.
            dp[i] = (2 * dp[i - 1] - last[c] + MOD) % MOD;
            
            // Before the current occurrence, dp[i-1] subsequences
            // become the new set ending with character c.
            last[c] = dp[i - 1];
        }
        
        // Remove the empty subsequence
        return (dp[s.size()] - 1 + MOD) % MOD;
    }
};
