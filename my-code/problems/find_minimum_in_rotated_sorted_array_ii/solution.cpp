class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mi = nums[n - 1];
        int i = n - 1;
        while(i - 1 >= 0 && nums[i - 1] <= nums[i]) {
            mi = nums[i - 1];
            i--;
        }
        return mi;
    }
};