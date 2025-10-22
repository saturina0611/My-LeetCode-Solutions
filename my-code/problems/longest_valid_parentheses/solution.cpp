class Solution {
public:

vector<pair<int , int>> vt;
    int longestValidParentheses2(string s) {
        stack<pair<int , char>> st;
        int currsum = 0;
        int ans = 0;
        for(int i = 0;i < s.size();i++) {
            char c = s[i];
            if(st.empty()) {
                if(c == '(') {
                    st.push({i , c});
                    currsum++;
                }
            }
            else {
                if(c == '(') {
                    st.push({i , c});
                    currsum++;
                }
                else {
                    if(currsum > 0) {
                        if(1) {
                            int id = st.top().first;
                            ans = max(ans , i - id + 1);
                            
                            currsum--;
                            
                            st.pop();
                            if(st.empty()) {
                                ans = max(ans , i - id + 1);
                                if(vt.size() == 0) {
                                    vt.push_back({id , i});
                                }
                                else {
                                    auto it = vt.end();
                                    it--;
                                    if(it->second + 1 == id) {
                                        it->second = i;
                                        ans = max(ans , it->second - it->first + 1);
                                    }
                                    else vt.push_back({id , i});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        stack<pair<int , char>> st;
        int currsum = 0;
        int ans = 0;
        for(int i = 0;i < s.size();i++) {
            char c = s[i];
            if(st.empty()) {
                if(c == '(') {
                    st.push({i , c});
                    currsum++;
                }
            }
            else {
                if(c == '(') {
                    st.push({i , c});
                    currsum++;
                }
                else {
                    if(currsum > 0) {
                        if(1) {
                            int id = st.top().first;
                            ans = max(ans , i - id + 1);
                            
                            currsum--;
                            
                            st.pop();
                            if(st.empty()) {
                                ans = max(ans , i - id + 1);
                                if(vt.size() == 0) {
                                    vt.push_back({id , i});
                                }
                                else {
                                    auto it = vt.end();
                                    it--;
                                    if(it->second + 1 == id) {
                                        it->second = i;
                                        ans = max(ans , it->second - it->first + 1);
                                    }
                                    else vt.push_back({id , i});
                                }
                            }
                        }
                    }
                }
            }
        }
        reverse(s.begin() , s.end());
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        cout << s << '\n';
        ans = max(ans , longestValidParentheses2(s));
        return ans;
    }
};