//在线oj --- 牛客

//1.iNOC产品部----w完全数计算
#include<iostream>

using namespace std;

int count(int n){
    int per = 0;
    if(n <= 0||n > 500000)
        return -1;
    else{
        for(int i = 2;i<= n;i++){
            int num = 0;
            for(int j = 1;j != i;j++){
                if(i % j == 0)
                    num = num + j;
            }
            if(num == i)
                per += 1;
        }
        return per;
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << count(n)<<endl;
    }
    return 0;
}

//2.扑克牌

#include<iostream>
#include<string>
#include<algorithm>

int main(){
    string board;
    while(getline(cin,board)){
        //直接找王炸，有王炸z直接输出
        if(board.find("joker JOKER") != -1)
            cout<<"joker JOKER"<<endl;
        else{
            int split = board.find("-");
            //将两副扑克牌进行分割
            string str1,str2;
            str1 = board.substr(0,split);
            str2 = board.substr(split + 1);
            //获取空格次数，牌数 = 次数 + 1
            int s1 = count(str1.begin(),str1.end(),' ') + 1;
            int s2 = count(str2.begin(),str2.end(),' ') + 1;

            //拿到第一张牌
            string f1 = str1.substr(0,str1.find(' '));
            string f2 = str2.substr(0,str2.find(' '));
            string str = "345678910JQKA2jokerJOKER";
            //拿牌数进行比较
            if(s1 == s2){
                //牌数相等时，第一张牌大即为大牌
                if(f1 > f2)
                    cout << str1 << endl;
                else
                    cout << str2 <<endl;
            }else{
                //牌数不相同时，说明类型不同，只有炸弹可以和其他牌进行比较
                //其他类型都是错误的
                if(s1 == 4)
                    cout << str1 <<endl;
                else if(str2 == 4)
                    cout <<str2 <<endl;
                else
                    cout <<"ERROR"<<endl;
            }
        }
    }
    return 0;
}
