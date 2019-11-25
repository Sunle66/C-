//在线oj

//1.参数解析
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Split(const string &str){
    string tmp = "";
    vector<string> vec;
    bool flag = false;
    for(int i = 0;i < str.size();i++){
        if(str[i] == '"')
            flag = false;
        else if(str[i] == ' ' && flag == true){
            vec.push_back(tmp);
            tmp = "";
        }else{
            tmp = tmp + str[i];
            flag = true;
        }
    }
    vec.push_back(tmp);
    cout << vec.size() << endl;
    for(auto i : vec)
        cout << i << endl;
    return 0;
}

int main(){
    string str;
    while(getline(cin,str)){
        Split(str);
    }
    return 0;
}

//2.跳石板

#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
bool InSpect(const int &n){
    for(int i = 2;i <= n;i++){
        if(n % i == 0)
            return true;
    }
    return false;
}

int main(){
    int N,M;
    vector<int> vec(M+1,INT_MAX);
    while(cin >> N >> M){
        if(N == M)
            return 0;
        if(InSpect(N) == false)
            return -1;
        for(int i=N;i<=M;i++){
            if(vec[i] == INT_MAX){
                continue;
            }
            for(int j=2;(j*j)<=i;j++){
                if(i % j == 0){
                    if(i+j <= M){
                        vec[i+j] = min(vec[i]+1,vec[i+j]);
                    }
                    if(i+(i/j) <= M){
                        vec[i+(i/j)] = min(vec[i]+1,vec[i+(i/j)]);
                    }
                }
            }
        }
        cout<<steps[M]<<endl;
    }
}
