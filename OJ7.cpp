//在线OJ7-----牛客

//1.洗牌
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T, n, k;
    cin >> T;
    while (T--){
        cin >> n >> k;
        int num = 2 * n;
        vector<int> tab(num);
        for(int i = 0; i < num; ++i)
            cin >> tab[i];
        while (k--){
            vector<int> n1(tab.begin(), tab.end());
            for (int i = 0; i < n; ++i){
                tab[2 * i] = n1[i];
                tab[2 * i + 1] = n1[i + n];
            }
        }
        for(int i = 0; i < num - 1; ++i)
            cout << tab[i] << " ";
        cout << tab[num - 1] << endl;
    }
    return 0;
}

//2.MP3光标位置
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str;
    while(cin>>n>>str){
        int num = 1;
        int first = 1;
        if(n <= 4){
            for(int i = 0;i < str.size();i++){
                if( num == 1 && str[i] == 'U' )
                    num=n;
                else if(num == n && str[i] == 'D' )
                    num = 1;
                else if(str[i] == 'U')
                    num--;
                else
                    num++;
            }
            for(int i = 1;i <= n-1;i++)
                cout << i <<' ';
            cout << n << endl;
            cout << num << endl;
        }else{
            for(int i = 0;i < str.size();i++){
                if(first==1 && num == 1 && str[i] == 'U'){
                    first=n-3;
                    num = n;
                }else if(first == n-3 && num == n && str[i] == 'D' ){
                    first = 1;
                    num = 1;
                }else if(first != 1&&num == first&&str[i] == 'U'){
                    first--;
                    num--;
                }else if(first != n-3&&num == first + 3&&str[i] == 'D'){
                    first++;
                    num++;
                }else if(str[i] == 'U')
                    num--;
                else
                    num++;
            }
            for(int i = first;i < first + 3;i++)
                cout << i <<' ';
            cout << first + 3 << endl;
            cout << num << endl;
        }
    }
    return 0;
}
