#include<iostream>
#include<memory>

using namespace std;

//unique_ptr实现原理：  
//      简单粗暴的防拷贝

template<class T>
class UniquePtr{
    public:
        UniquePtr(T* ptr = nullptr)
            :_ptr(ptr)
        {}

        ~UniquePtr(){
            if(_ptr)
                delete _ptr;
        }

        T& operator*(){
            return *_ptr;
        }

        T& operator->(){
            return _ptr;
        }

    private:
        UniquePtr(UniquePtr<T> const &) = delete;
        UniquePtr& operator=(UniquePtr<t> const &) = delete;

        T* _ptr;
};