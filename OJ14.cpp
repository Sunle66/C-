//在线OJ14-----牛客

//1.求正数数组的最小不可组成和
class Solution {
public:
    /**
     *    正数数组中的最小不可组成和
     *    输入：正数数组arr
     *    返回：正数数组中的最小不可组成和
     */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0；
        int min = arr[0];
        for (int i = 0; i < len; ++i){
            sum = sum + arr[i];
            if (arr[i] < min)
                min = arr[i];
        }

        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; ++i){
            for (int j = sum; j >= arr[i]; --j){
                if (dp[j - arr[i]] + arr[i] > dp[j])
                    dp[j] = dp[j - arr[i]] + arr[i];
            }
        }
        for (int i = min; i <= sum; ++i){
            if (i != dp[i])
                return i;
        }
        return sum + 1;
    }
};

//2.有假币
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        for(int i = 0;;i++){
            if(pow(3,i) >= n){
                cout << i <<endl;
                break;
            }
        }
    }
    return 0;
}
