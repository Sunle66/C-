//在线OJ15-----牛客

//1.最难的问题
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        for(int i = 0;i < s.size();i++){
            if(s[i] >= 'V' && s[i] <= 'Z')
                cout << s[i] - 21;
            else
                cout << s[i] + 5;
        }
    }
    return 0;
}


//2.因子个数
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int prime[100005];
void prime_table()
{
    int i,j;
    for(i=2; i<100005; i++)
        if(prime[i]==0)
            for(j=2*i; j<100005; j+=i)
                prime[j] = 1;
}
int main()
{
    int n,t=0;
    int a[20000];
    prime_table();
    for(int i=2; i<100005; i++)
        if(prime[i]==0)
        {
            a[t]=i;
            t++;
        }
    while(~scanf("%d",&n))
    {
        int cnt=0,i=0;
        while(n!=1)
        {
            if(n%a[i]!=0)
                i++;
            else if(n%a[i]==0)
            {
                while(n%a[i]==0)
                    n/=a[i];
                cnt++;
            }
        }
        printf("%d\n",cnt);

    }
}
