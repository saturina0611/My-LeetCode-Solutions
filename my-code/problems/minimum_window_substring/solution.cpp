#define pii pair<int , int>
class Solution {
public:
unordered_map<char , int> mp , mp2;
    bool check() {
        for(auto &p : mp) {
            //cout << p.first << ' ' << mp2[p.first] << '\n';
            if(mp2[p.first] < p.second) return 0;
        }
        return 1;
    }
    string minWindow(string s, string t) {
        vector<pii> vt;
        for(auto c : t) mp[c]++;
        int l = 0 , r = -1;
        for(l = 0;l < s.size();l++) {
            if(r < l - 1) r = l - 1 , mp2.clear();
            //cout << l << ' ' << r << '\n';
            while(check() == 0 && r < (int)s.size()) {
                r++;
                if(r == s.size()) break;
                //cout << l << ' ' << r << ' ' << s[r] << '\n';
                mp2[s[r]]++;
                //cout << l << ' ' << r << '\n';
            }
            if(r == s.size()) break;
            if(check()) {
                vt.push_back({l , r});
            }
            mp2[s[l]]--;
        }
        if(vt.size() == 0) {
            string em = "";
            return em;
        }
        pii ans = vt[0];
        for(auto p : vt) if(p.second - p.first + 1 < ans.second - ans.first + 1) ans = p;
        string str;
        for(int i = ans.first ;i <= ans.second;i++) str.push_back(s[i]);
        return str;
    }
};