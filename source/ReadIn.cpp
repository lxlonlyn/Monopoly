/*******************************************
用来更加严格地读入数据
*******************************************/
#include <iostream>
#include <string>
using namespace std;

//读入数字：无效返回-239239239
int ReadNum() {
    int res = 0, len, f = 1;
    string s; 
    getline(cin, s); len = s.length();
    for (int i = 0; i < len; ++i) {
        if (f == 1 && s[i] == '-') f = -1;
        else if (s[i] >= '0' && s[i] <= '9') {
            res = (res << 1) + (res << 3) + s[i] - '0';
        }
        else{
            return -239239239;
        }
    }
    return res * f;
}