class Solution {
public:
int a[10];
    string getPermutation(int n, int k) {
        for(int i = 1;i <= n;i++) a[i] = i;
        for(int i = 1;i < k;i++) next_permutation(a + 1 , a + n + 1);
        string str;
        for(int i = 1;i <= n;i++) str.push_back((char)(a[i] + '0'));
        return str;
    }
};