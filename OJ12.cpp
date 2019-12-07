//在线OJ12-----牛客

//1.不用加减乘除做加法

class Solution {
public:
    int Add(int num1, int num2)
    {
        if(num2 == 0)
            return num1;
        return Add(num1 ^ num2, (num1 & num2) << 1);
    }
};

//2.三角形

#include<iostream>

using namespace std;

int main(){
    double a,b,c;
    while(cin >> a >> b >> c){
        if(a+b>c && a+c>b && b+c>a)
            cout << "Yes" <<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
