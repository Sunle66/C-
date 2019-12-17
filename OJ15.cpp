//二叉树节点的最大距离问题 ---> 牛客

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long MAX=0;
long height(vector<vector<long>> &tree, long &node)
{
    if (node==0)
        return 0;
   
    long left = height(tree, tree[node][0]);
    long right = height(tree, tree[node][1]);
   
    MAX = (left+right+1)>MAX?(left+right+1):MAX;
    
    return 1+max(left,right);
}

int main(){
    
    long num,root;
    cin>>num>>root;
    long far,lch,rch;
    vector<vector<long>> tree(500001,{0,0});
    for (long i=0; i<num; i++)
    {
        cin>>far>>lch>>rch;
        tree[far][0]=lch;
        tree[far][1]=rch;
    }
    
    height(tree, root);
    cout<<MAX;
    
    return 0;
}