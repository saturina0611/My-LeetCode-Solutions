class Solution {
public:
int ans , n;
int left[(int)1e5 + 5] , right[(int)1e5 + 5];
    inline void maxz(int &a , int b) {
        if(a < b) a = b;
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        for(int i = 0;i < n;i++) maxz(ans , heights[i]);
        stack<int> st;
        for(int i = 0;i < n;i++) {
            if(st.empty()) {
                st.push(i);
                left[i] = i - 1;
                continue;
            }
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                if(st.empty()) left[i] = -1;
                else left[i] = st.top();
                st.push(i);
            }
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1;i >= 0;i--) {
            if(st.empty()) {
                st.push(i);
                right[i] = i + 1;
                continue;
            }
            else {
                while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
                if(st.empty()) right[i] = n;
                else right[i] = st.top();
                st.push(i);
            }
        }
        for(int i = 0;i < n;i++) maxz(ans , heights[i] * (right[i] - left[i] - 1));
        return ans;
    }
};