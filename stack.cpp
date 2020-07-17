//容器适配器

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//实现一个最小栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        _min.push(INT_MAX);
    }
    
    void push(int x) 
    {
        //只要是压栈，先将元素保存到_elem中
        _elem.push(x);
        //将数据与_min栈顶进行比较，取最小值
         _min.push(min(_min.top(),x));
    }
    
    void pop() {
        //同时删除两个栈的栈顶元素
        _min.pop();
        _elem.pop();
    }
    
    int top() {
        return _elem.top();
    }
    
    int getMin() {
        return _min.top();
    }

private:
    //保存栈中的元素
    std::stack<int> _elem;

    //保存栈的最小值
    std::stack<int> _min;
};

//栈的压入弹出序列
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        stack<int> s;
        int i = 0,j = 0;
        while(i < pushV.size()){
            if(pushV[i] != popV[j]){
                s.push(pushV[i]);
                i += 1;
            }else{
                ++i,++j;
                while(!s.empty() && s.top() == popV[j]){
                    s.pop();
                    j++;
                }
            }
        }
        return s.empty();
    }
private:

};

//逆波兰表达式求值
class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int right,left;

        for(auto i : tokens)
        {
            if(i == "+" || i == "-"|| i == "*"|| i == "/"){
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();

                if(i == "+")
                    s.push(left + right);
                if(i == "-")
                    s.push(left - right);

                if(i == "*")
                    s.push(left * right);

                if(i == "/")
                    s.push(left / right);
            }else{
                s.push(atoi(i.c_str()));
            }           
        }
        return s.top();
    }
};