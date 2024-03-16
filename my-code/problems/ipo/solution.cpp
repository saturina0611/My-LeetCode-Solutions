class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        cin.tie(0)->sync_with_stdio(0);
        int n = p.size();
        vector<int> id(n);
        iota(id.begin() , id.end() , 0);
        sort(id.begin() , id.end() , [&](auto x,auto y) {
            return make_pair(c[x] , -p[x]) < make_pair(c[y] , -p[y]);
        });
        long long W = w;
        priority_queue<int> pq;
        for(auto &i : id) {
            while(pq.size() && c[i] > W && k) {
                W += pq.top();
                pq.pop();
                k--;
            }
            if(c[i] > W || !k) break;
            pq.push(p[i]);
        }
        while(pq.size() && k--) {
            W += pq.top();
            pq.pop();
        }
        return W;
    }
};