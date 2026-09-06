class Solution {
public:
unsigned int dp[1005][1005];
    int numDistinct(string s, string t) {
        s = "#" + s;
        t = "#" + t;
        int m = s.size() - 1;
        int n = t.size() - 1;
        dp[0][0] = 1;
        for(int i = 0;i <= m;i++) dp[i][0] = 1;
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= m;i++) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            
        }
        return (int)dp[m][n];
    }
};