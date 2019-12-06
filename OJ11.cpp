//在线OJ11-----牛客

//1.变态跳台阶

class Solution {
public:
    int jumpFloorII(int number) {
        if(number < 2)
            return 1;
        else
            return 2 * jumpFloorII(number - 1);
    }
};

//2.快到碗里来

#include<iostream>

using namespace std;

int main(){
    double n,r;
    while(cin >> n >> r){
        if(n > 2 * 3.14 * r)
            cout << "No" <<endl;
        else
            cout << "Yes" <<endl;
    }
}
