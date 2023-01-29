#include<math.h>
class Solution {
public:
    long long reverse(long long x) {
        long long xcp=x;
        long long rev=0;
        long long scs;
        long long i=1;
        long long somu=0;
        while (i==1) {
            if(pow(10,somu)<=abs(x)) {somu++;}
            else {break;}
        }
        scs=somu;
        if(xcp>0) {
            while(x>0) {
                rev+=x%10*pow(10,scs-1);
                scs--;
                x/=10;
            }
        }
        else if(xcp==0) {
            rev=0;
        }
        else if(xcp<0) {
            xcp=-xcp;
            x=-x;
            while(x>0) {
                rev+=x%10*pow(10,scs-1);
                scs--;
                x/=10;
            }
            rev=-rev;
        }
    if(0-pow(2,31)<=rev && rev<=pow(2,31)-1) {return rev;}
        else {return 0;}
    }
};