//在线OJ8-----牛客

//1.微信红包

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(),gifts.end());
        int num = 0;
        for(int i = 0;i < n;i++){
            if(gifts[i] == gifts[n / 2])
                num++;
        }
        if(num > n / 2)
            return gifts[n / 2];
        return 0;
    }
};

//2.计算字符串的距离
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int calStringDistance(string str1,string str2){
    int len1 = str1.size();
    int len2 = str2.size();
    if(str1.empty() || str2.empty())
        return max(len1,len2);

    vector< vector<int> > vec(len1+1,vector<int>(len2+1,0));

    for(int i = 1;i <= len2;i++)
        vec[0][i] = i;
    for(int j = 1;j <= len1;j++)
        vec[j][0] = j;
    for (int i=1; i <= len1; ++i) {
        for (int j=1; j <= len2; ++j) {
            int one = vec[i-1][j] + 1;
            int two = vec[i][j-1] + 1;
            int three = vec[i-1][j-1];
            if(str1[i-1] != str2[j-1])
                three += 1;
            vec[i][j] = min(min(one,two),three);
        }
    }
    return vec[len1][len2];
}

int main(){
    string str1,str2;
    while(cin >> str1 >> str2){
        cout<<calStringDistance(str1,str2)<<endl;;
    }
    return 0;
}
