#include<iostream>
#include<string>
#include<map>
using namespace std;

void Map(){
    map<string,string> m{
        {"hello","嗨"},
        {"hehe","呵呵"},
        {"haha","哈哈"}
    };
//    for(auto it = m.begin();it != m.end();it++){
//        cout<<(*it).first<<"--->"<<it->second<<endl;
//        cout<<(*it).first<<"--->"<<(*it).second<<endl;
//    }

    m["hello"] = "嗨嗨";
    //用pair直接构造键值对进行插入
    m.insert(pair<string,string>("banan","🍌"));
    //用make_pair函数来构造键值对进行插入
    m.insert(make_pair("apple", "🍎"));

    m.insert(m.find("banan"),make_pair("orange","🍊"));

    cout<<m.size()<<endl;

    //cout<<m.find("banana")<<endl;
    for(auto& e:m)
        cout<<e.first<<"--->"<<e.second<<endl;

    auto ret = m.insert(make_pair("peach","桃色"));
    if(ret.second)
        cout<<"<peach,桃色>不在map中，已经插入"<<endl;
    else
        cout<<"键值为peach的元素已经存在："<<ret.first->first<<"-->"
        <<ret.first->second<<"插入失败"<<endl;

    //删除key为apple的元素
    m.erase("apple");
    for(auto& e : m)
        cout<<e.first<<"-->"<<e.second<<endl;

    if(m.count("apple") == 1)
        cout<<"🍎没有被吃"<<endl;
    else
        cout<<"🍎被吃了"<<endl;
}
/*总结：
    1.map中的元素是键值对
    2.map中的key是唯一的，且不能被g修改
    3.默认按照小于的方式对key进行比较
    4.map中的元素如果按照迭代器去进行遍历，可以得到一个有序的序列
    5.map的底层为红黑树，查找效率为log2(n)
    6.支持[]查找，operator[]中实际进行插入查找
 */

void MultiMap(){
    multimap<string,string> m;
    m.insert(make_pair("李逵","黑旋风"));
    m.insert(make_pair("林冲","豹子头"));
    m.insert(make_pair("武松","行者"));

    //尝试插入key相同的元素
    m.insert(make_pair("李逵","铁牛"));

    cout<<m.size()<<endl;
    for(auto& e: m)
        cout<<"<"<<e.first<<"->"<<e.second<<">"<<endl;
    //查看key为李逵的元素有多少
    cout<<m.count("李逵")<<endl;
}

void MultiMap1(){
    multimap<int,int> m;
    for(int i = 0;i < 10;i++)
        m.insert(make_pair(i,i));

    for(auto& e:m)
        cout<<e.first<<"-"<<e.second<<endl;
    cout<<endl;

    //返回m中大于5的第一个元素
    auto it = m.lower_bound(5);
    cout<<it->first<<"->"<<it->second<<endl;

    //返回m中等于5的元素
    it = m.upper_bound(5);
    cout<<it->first<<"->"<<it->second<<endl;

}

class person{
public:
    virtual void Back(int a){
        cout << "基类虚函数" << endl;
    }
};

class student : public person{
public:
    virtual void Back(short a){
        cout << "派生类虚函数" << endl;
    }
};
//
//int main(){
//    //Map();
//    //MultiMap();
//    MultiMap1();
//    return 0;
//}
// 
