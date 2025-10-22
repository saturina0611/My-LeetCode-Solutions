
class Solution {
public:

set<int> st;
    inline bool solve(vector<vector<int>> &a , int times) {
        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                if(a[i][j] == 0) {
                    bool s[10];
                    memset(s , 1 , sizeof s);
                    for(int k = 0;k < 9;k++) {
                        s[a[i][k]] = 0;
                        s[a[k][j]] = 0;
                    }
                    int i2 = i , j2 = j;
                    i2 -= i2 % 3;
                    j2 -= j2 % 3;
                    for(int k = i2;k < i2 + 3;k++) {
                        for(int l = j2;l < j2 + 3;l++) s[a[k][l]] = 0;
                    }
                    int cnt = 0;
                    for(int k = 1;k <= 9;k++) if(s[k]) cnt++;
                    if(cnt == 0) return 0;
                    for(int k = 1;k <= 9;k++) {
                        if(s[k] == 0) continue;
                        a[i][j] = k;
                        bool e = solve(a , times + 1);
                        if(e) return 1;
                        else {
                            a[i][j] = 0;
                        }
                    }
                    if(a[i][j] == 0) return 0;
                }
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> a(10 , vector<int> (10 , 0));

        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                if(board[i][j] == '.') a[i][j] = 0;
                else a[i][j] = board[i][j] - '0';
            }
        }
        solve(a , 0);
        for(int i = 0;i < 9;i++) {
            for(int j = 0;j < 9;j++) {
                board[i][j] = (char)(a[i][j] + '0');
            }
        }
    }
};