//在线OJ3-----牛客

//1.超长正整数相加
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string str1,str2,res;
    int post = 0;
    while(cin >> str1 >> str2){
        int len = str1.size() > str2.size() ? str1.size() : str2.size();

        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());

        for(int i = 0;i < len;i++){
            int num1 = i < str1.size() ? str1[i] - '0' : 0;
            int num2 = i < str2.size() ? str2[i] - '0' : 0;
            int val = (num1 + num2 + post) % 10;

            post = (num1 + num2 + post) / 10;
            res.insert(res.begin(), val + '0');
        }
        if(post == 1)
            res.insert(res.begin(),1);
        cout << res << endl;

        res.clear();
        post = 0;
    }
    return 0;
}

//2.iNOC产品部----杨辉三角的变形

#include<iostream>

using namespace std;


int main(){
    int line;
    while(cin >> line){
        if(line <= 2)
            cout << -1 <<endl;
        else if(line % 2 == 1)
            cout << 2 << endl;
        else if(line % 4 == 0)
            cout << 3 << endl;
        else
            cout << 4 << endl;
    }
    return 0;
}
