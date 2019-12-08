//在线OJ13-----牛客

//1.奇数位上是奇数或偶数位上是偶数

class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int even = 0;
        int odd = 1;
        int back = len - 1;
        while(even < len && odd < len){
            if(arr[back] % 2 == 0){
                int tmp = arr[even];
                arr[even] = arr[back];
                arr[back] = tmp;
                even += 2;
            }else{
                int tmp = arr[odd];
                arr[odd] = arr[back];
                arr[back] = tmp;
                odd += 2;
            }

        }
    }
};

//2.猴子分桃

// write your code here cpp
#include<iostream>
#include<math.h>

using namespace std;
int main()
{
    unsigned long n, a, b;
    while(cin >> n){
        if(n == 0)
            break;
        a = pow(5, (double)n);
        b = pow(4, (double)n);

        cout << a - 4 <<" "<< b - 4 + n <<endl;
    }
    return 0;
}
