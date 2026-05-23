class Solution {
public:
int dp[205][205];
int m , n;
int dx[2] = {0 , -1} , dy[2] = {-1 , 0};
    int bfs(vector<vector<int>>& a) {
        queue<pair<int , int>> q;
        q.push({m - 1 , n - 1});
        pair<int , int> x;
        int fi , se;
        int newx , newy;
        int xx;
        while(!q.empty()) {
            x = q.front();
            q.pop();
            fi = x.first , se = x.second;
            for(int i = 0;i <= 1;i++) {
                if(fi + dx[i] >= 0 && se + dy[i] >= 0) {
                    newx = fi + dx[i] , newy = se + dy[i];
                    xx = max(dp[fi][se] - a[newx][newy] , 1);
                    if(dp[newx][newy] > xx) { 
                        dp[newx][newy] = xx;
                        q.push({newx , newy});
                    }
                }
            }
        }
        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& a) {
        m = a.size();
        n = a[0].size();
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) dp[i][j] = 1000111000;
        }
        dp[m - 1][n - 1] = max(1 , 1 - a[m - 1][n - 1]);
        return bfs(a);
    }
};