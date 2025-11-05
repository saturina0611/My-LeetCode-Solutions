class Solution {
public:
bool seen[(int)1e5 + 5];
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        memset(seen , 0 , sizeof seen);
        for(auto x : nums) {
            if(x <= n + 1 && x >= 1) seen[x] = 1;
        }
        for(int i = 1;i <= n + 1;i++) if(!seen[i]) return i;
        return 0;
    }
};