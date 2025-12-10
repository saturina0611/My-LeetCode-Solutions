class Solution {
public:
    unordered_map<string , bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(n != s2.size()) return 0;
        if(s1 == s2) return 1;
        if(n == 1) return 0;
        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end()) return mp[key];
        for(int i = 1;i < n;i++) {
            //without swap
            bool withoutswap = (isScramble(s1.substr(0 , i) , s2.substr(0 , i)) && isScramble(s1.substr(i) , s2.substr(i)));
            if(withoutswap) return 1;
            //swap
            bool swap = (isScramble(s1.substr(0 , i) , s2.substr(n - i)) && isScramble(s1.substr(i) , s2.substr(0 , n - i)));
            if(swap) return 1;

        }
        return mp[key] = 0;
    }
};