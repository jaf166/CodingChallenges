/*
 Given a string s, return the longest palindromic substring in s.
*/

class Solution {    
public:
    string longestPalindrome(string s) {
        
        if (s.empty())
            return "";
        
        int maxLeft = 0;
        int maxLength = 1;
        
        for (int i = 1; i < s.size(); i++){
            
            // searches for starting left and right ends of duplicate characters
            int j = i;
            while (j - 1 >= 0 and s[i] == s[j - 1])
                j--;
                
            int tempLeft = j;
            int tempRight = i;
                            
            // searches for largest palindrome with starting left and right ends
            while (tempLeft - 1 >= 0 and tempRight + 1 < s.size() and s[tempLeft - 1] == s[tempRight + 1]) {
                tempLeft--;
                tempRight++;
            }

            if ( (tempRight - tempLeft + 1) > maxLength){
                maxLeft = tempLeft;
                maxLength = tempRight - tempLeft + 1;
            }

        }
        
        return s.substr(maxLeft, maxLength);
    }
};

