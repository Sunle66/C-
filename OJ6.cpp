//在线OJ6-----牛客

//1.字符串反转
#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        for(int i = str.size()-1;i >= 0;i--){
            cout << str[i];
        }
    }
    return 0;
}

//2.公共字串

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1,str2;
    int dis=0,t=0;
    string tmp;
    while(cin>>str1>>str2)
    {
        int len=str1.length();
        for(int i=len;i>1;i--)
        {
            for(int j=0;j<len;j++)
            {
                if(i+j<=len)
                {
                    tmp=str1.substr(j,i);
                    t=str2.find(tmp);
                    if(t!=-1&&tmp.length()>dis)
                        dis=tmp.length();

                }
            }
        }
        cout<<dis<<endl;
    }

    return 0;
}


