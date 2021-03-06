//在线OJ8-----牛客

//1.小易的升级之路
#include<vector>
#include<iostream>
using namespace std;
int GCD(int a, int b){
    int c;
    while (c = a % b){
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int n, power;
    vector<int> num;

    while (cin >> n >> power){
        num.resize(n);
        for (int i = 0; i < n; i++)
            cin >> num[i];
        for (int k = 0; k < n; k++){
            if (num[k] < power)
                power += num[k];
            else
                power += GCD(power, num[k]);
        }
        cout << power << endl;
    }
    return 0;

}
//2.找出字符串中第一个只出现一次的字符
#include <string>
#include <iostream>
using namespace std;
int main() {
    string s;
    while(cin>>s){
        int hashtable[256] = {0};
        for(auto& e : s)
            hashtable[e]++;
        int i;
        for(i = 0; i < s.size(); i++){
            if(hashtable[s[i]] == 1){
                cout<<s[i]<<endl;
                break;
            }
        }
        if(i >= s.size())
            cout<<-1<<endl;
    }
    return 0;
}
