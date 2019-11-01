#include<iostream>
#include<vector>
#include<memory>
using namespace std;
//异常的规范
//int Fun(int a,int b)throw(char*,int,自定义类型)

//在任何时候抛出任何异常
int Fun(int a,int b)
{
    if(b == 0){
        throw "aohduh";
    }
    return a/b;
}

void test(){
    int a,b;
    cin>>a>>b;
    int* arr = new int[100];
    try{
        Fun(a,b);
    }
    catch(const int a){
        cout<< a <<endl;
    }
    catch(...){
        cout<<"delete[] arr"<<endl;
        delete[] arr;
        throw;  //异常的重新抛出
    }
    cout<<"delete[]"<<endl;
    delete[] arr;
}

int main(){
    try{
//        int* pi = new int{0x3fffffff};
        vector<int> v;
        v.at(1);
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"未知异常"<<endl;
    }
    return 0;
}

int main(){
    try{
        test();
    }
    catch(const int a){
        cout<<a<<endl;
    }
    catch(const char* str){
        cout<< str <<endl;
    }
    catch(...){
        cout<< "..." <<endl;
    }
    cout<<"main()"<<endl;

    return 0;

}


//RAII  构造函数私有化
//      析构函数释放

//实现智能指针：
//      1.实现RAII
//      2.实现指针的功能
template <class T>  //
class SharedPtr {
public:
    SharedPtr(T* ptr)
        :_ptr(ptr)
        ,_refcount(new int(1))
    {}
    //c++98
    //拷贝： 管理权转移 ---> 解决拷贝问题
    //auto_ptr标准库  禁止使用  出现指针悬空的问题

    //c++11     unique_ptr: 通过防拷贝解决指针悬空的问题
    //          shared_ptr: 支持拷贝    支持赋值  通过引用基数来解决二次释放的问题
    SharedPtr(SharedPtr<T>& ap)
    :_ptr(ap._ptr)
    ,_refcount(ap._refcount)
    {
        ++(*_refcount);
    }
    ~SharedPtr(){
        if(--(*_refcount)== 0){
            delete _ptr;
            delete _refcount;
            _ptr = nullptr;
            _refcount = nullptr;
        }
    }

    T& operator*(){
        return *_ptr;
    }

    T& operator->(){
        return _ptr;
    }
private:
    T* _ptr;
    int* _refcount;
};
