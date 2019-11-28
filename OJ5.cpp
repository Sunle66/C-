//在线OJ5-----牛客

//1.统计每个月兔子的总数

#include<iostream>

using namespace std;
int _month_count(int m){
    int num;
    if(m < 3)
        num = 1;
    else
        num = _month_count(m-1)+_month_count(m-2);
    return num;
}
int main(){
    int param;
    while(cin>>param){
        cout << _month_count(param) << endl;
    }
    return 0;
}

//2.字符串通配符

#include <iostream>
#include <string>
using namespace std;

bool _match(const char* pat,const char *str)
{
    if (*pat == '\0' && *str == '\0')
        return true;
    if (*pat == '\0' || *str == '\0')
        return false;

    if (*pat == '?')
        return _match(pat + 1, str + 1);
    else if (*pat == '*')
        return _match(pat + 1, str)
        || _match(pat + 1, str + 1)
        || _match(pat, str + 1);
    else if (*pat == *str)
        return _match(pat + 1, str + 1);

    return false;
}
int main(void)
{
    string pat, str;
    while (cin >> pat >> str)
    {
        bool ret = _match(pat.c_str(), str.c_str());
        if (ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
