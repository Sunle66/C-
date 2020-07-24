#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

//单例模式
//个类只能创建一个对象，即单例模式，该模式可以保证系统中该类只有一个实例，并提供一个访问它的全
//局访问点，该实例被所有程序模块共享

//饿汉模式
class Singleton{
    public:
        static Singleton* GetInstance(){
            return &m_instance;
        }
    private:
        //构造函数私有化
        Singleton(){};

        /*c++98防拷贝
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
        */

        //c++11
        Singleton(Singleton const&) = delete;
        Singleton& operator=(Singleton const&);

        static Singleton m_instance;
};
Singleton Singleton::m_instance;

//懒汉模式

class _Singleton{

    private:
        _Singleton(){};

        _Singleton(_Singleton const&) = delete;
        _Singleton& operator=(_Singleton const&);

        static _Singleton* m_pInstance;     //单例对象指针
        static mutex m_mtx;                 //互斥锁

    public:
        static _Singleton* GetInstance(){
            if(nullptr == m_pInstance){
                m_mtx.lock();
                if(nullptr == m_pInstance)
                    m_pInstance = new _Singleton();
                m_mtx.unlock();
            }
            return m_pInstance;
        }

        //实现一个内嵌垃圾回收类
        class CGarbo{
            public:
                ~CGarbo(){
                    if(_Singleton::m_pInstance)
                        delete _Singleton::m_pInstance;
                }
        };
        
        //定义一个静态成员变量，程序结束时，系统会自动调用他的析构函数而释放单例对象
        static CGarbo Garbo;
};
