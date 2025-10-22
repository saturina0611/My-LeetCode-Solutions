class Solution {
public:
    void nextPermutation(vector<int>& vt) {
        int n = vt.size();
        int pivot = -1;
        for(int i = n - 1;i > 0;i--) {
            if(vt[i - 1] < vt[i]) {
                pivot = i - 1;
                break;
            }
        }
        
        if(pivot == -1) {
            reverse(vt.begin() , vt.end());
            return;
        }
        int pivot2 = pivot + 1;
        for(int i = n - 1;i > pivot;i--) {
            if(vt[i] > vt[pivot]) {
                pivot2 = i;
                break;
            }
        }
        cout << pivot << ' ' << pivot2;
        swap(vt[pivot] , vt[pivot2]);
        reverse(vt.begin() + pivot + 1 , vt.end());
    }
};