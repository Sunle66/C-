//在线oj

//1.二进制插入
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        m = m << j;
        return m ^ n;
    }
};

//2.查找组成一个偶数的两个最近素数
#include<iostream>

using namespace std;
bool _sushu(int n){
    if(n == 1||n == 2)
        return true;
    else{
        for(int i = 2;i < n;i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
}

int main(){
    int n;
    while(cin >> n){
        int num1,num2;
        if(n == 2)
            return n;
        for(int i = 1;i < n/2;i++){
            if(_sushu(i)&&_sushu(n - i)){
                if(num1 < i){
                    num1 = i;
                    num2 = n - i;
                }
            }
        }
        cout<< num1 << "\n" << num2<<endl;
    }
    return 0;
}
