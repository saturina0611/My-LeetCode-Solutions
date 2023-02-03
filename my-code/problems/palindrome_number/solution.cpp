class Solution {
public:
    bool isPalindrome(int x) {
        string xx=to_string(x);
        string xxx=xx;
        reverse(xx.begin(),xx.end());
        if(xx==xxx) {
            return true;
        }
        else {
            return false;
        }
    }
};