class Solution {
public:
    int lengthOfLastWord(string s) {
        long long dem=0;
        long long n=s.length();
        long long i=n-1;
        while(i>=0) {
            if(s[i]==' ') {i--;}
            else break;
        }
        while(i>=0) {
            if(s[i]!=' ') {i--;dem++;}
            else break;
        }
        return dem;
    }
};