#define pii pair<int , int> 
class Solution {
public:
bool mark[20][20] , markcol[20] , markrow[20];
int answer;
vector<pii> vt;
vector<vector<string>> ans;
string str;
int n;
    void backtrack(int x) {
        if(x > n) {
            answer++;
            return;
        }
        for(int i = 1;i <= n;i++) {
            if(mark[x][i] == 0 && markrow[x] == 0 && markcol[i] == 0) {
                mark[x][i] = 1;
                //vt.push_back({x , i});
                markrow[x] = 1;
                markcol[i] = 1;
                vector<pii> newmark;
                for(int j = -10;j <= 10;j++) {
                    if(x + j >= 1 && x + j <= n && i + j >= 1 && i + j <= n && mark[x + j][i + j] == 0) {
                        newmark.push_back({x + j , i + j});
                        mark[x + j][i + j] = 1;
                    }

                    if(x - j >= 1 && x - j <= n && i + j >= 1 && i + j <= n && mark[x - j][i + j] == 0) {
                        newmark.push_back({x - j , i + j});
                        mark[x - j][i + j] = 1;
                    }
                }
                backtrack(x + 1);
                //vt.pop_back();
                mark[x][i] = 0;
                markrow[x] = 0;
                markcol[i] = 0;
                for(auto p : newmark) {
                    mark[p.first][p.second] = 0;
                }
            }
        }
    }
    void solve() {
        backtrack(1);
        // for(auto &x : answer) {
        //     vector<string> output(n , str);
        //     for(auto p : x) {
        //         output[p.first - 1][p.second - 1] = 'Q';
        //     }
        //     ans.push_back(output);
        // }
    }
    int totalNQueens(int N) {
        n = N;
        solve();
        return answer;
    }
};