class Solution
{
public:
    int a[205][205], sum[205][205];
    int ans;
    int m, n;
    int current[205];
    int left[205] , right[205];
    inline void maxz(int &a, int b) {
        if(a < b) a = b;
    }
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                a[i][j] = matrix[i][j] - '0';
            }
        }
        // for(int i = 1; i <= m; i++)
        // {
        //     for(int j = 1; j <= n; j++)
        //     {
        //         sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        //     }
        // }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 1) current[j]++;
                else current[j] = 0;
            }
            memset(left , 0 , sizeof left);
            memset(right , 0 , sizeof right);
            for(int i = 0; i < n; i++) maxz(ans, current[i]);
            stack<int> st;
            for(int i = 0; i < n; i++)
            {
                if(st.empty())
                {
                    st.push(i);
                    left[i] = i - 1;
                    continue;
                }
                else
                {
                    while(!st.empty() && current[st.top()] >= current[i]) st.pop();
                    if(st.empty()) left[i] = -1;
                    else left[i] = st.top();
                    st.push(i);
                }
            }
            while(!st.empty()) st.pop();
            for(int i = n - 1; i >= 0; i--)
            {
                if(st.empty())
                {
                    st.push(i);
                    right[i] = i + 1;
                    continue;
                }
                else
                {
                    while(!st.empty() && current[st.top()] >= current[i]) st.pop();
                    if(st.empty()) right[i] = n;
                    else right[i] = st.top();
                    st.push(i);
                }
            }
            for(int i = 0; i < n; i++) maxz(ans, current[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
