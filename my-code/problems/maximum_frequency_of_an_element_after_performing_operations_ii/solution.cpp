class Solution {
public:
map<long long , long long> mp;
    void maxz(long long &a , long long b) {
        if(a < b ) a = b;
    }
    int maxFrequency(vector<int>& vec, int k, int solan) {
        vector<long long> vt(vec.size());
        for(int i = 0;i < vec.size();i++) vt[i] = vec[i];
        long long n = vt.size();
        long long ans = 0;
        sort(vt.begin() , vt.end());
        for(auto x : vt) mp[x]++;
        for(auto p : mp) maxz(ans , p.second);
        for(long long i = 0;i < n;i++) {
            long long pivot = upper_bound(vt.begin() , vt.end() , vt[i] + 2 * k) - vt.begin();
            pivot--;
            long long times = pivot - i + 1 - mp[vt[i] + k];
            times = min(times , (long long)solan);
            maxz(ans , times);
        }
        for(long long i = 0;i < n;i++) {
            long long pivot1 = lower_bound(vt.begin() , vt.end() , vt[i] - k) - vt.begin();
            long long pivot2 = upper_bound(vt.begin() , vt.end() , vt[i] + k) - vt.begin();
            pivot2--;
            long long times = pivot2 - pivot1 + 1 - mp[vt[i]];
            times = min(times , (long long)solan);
            maxz(ans , times + mp[vt[i]]);
        }
        return ans;
    }
};