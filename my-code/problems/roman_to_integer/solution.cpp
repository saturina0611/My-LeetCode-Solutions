class Solution {
public:
    int convert(char &k) {
    int so;
    switch(k) {
        case 'I': {so=1;break;}
        case 'V': {so=5;break;}
        case 'X': {so=10;break;}
        case 'L': {so=50;break;}
        case 'C': {so=100;break;}
        case 'D': {so=500;break;}
        case 'M': {so=1000;break;}
    }
    return so;
}
    int romanToInt(string s) {
        long long so=0;
    for(int i=1;i<s.length();i++) {
        if(convert(s[i])>convert(s[i-1])) {
            so-=convert(s[i-1]);
        }
        else {
            so+=convert(s[i-1]);
        }
    }
    so+=convert(s[s.length()-1]);
    return so;
    }
};