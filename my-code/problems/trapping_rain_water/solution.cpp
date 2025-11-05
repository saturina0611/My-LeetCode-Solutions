class Solution
{
public:
    vector<int> sum;
    int maxleft[(int)1e5 + 5] , maxright[(int)1e5 + 5];
    int ans = 0;
    int trap(vector<int>& height)
    {
        int n = height.size();
        maxleft[0] = 0;
        for(int i = 1;i < n;i++) {
            maxleft[i] = max(height[i - 1] , maxleft[i - 1]);
        }
        maxright[n - 1] = 0;
        for(int i = n - 2;i >= 0;i--) {
            maxright[i] = max(height[i + 1] , maxright[i + 1]);
        }
        for(int i = 0;i < n;i++) {
            int x = min(maxleft[i] , maxright[i]);
            if(x > height[i]) ans += x - height[i];
        }
        return ans;

    }
};
