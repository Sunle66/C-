#include<iostream>

using namespace std;

//
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    //private:
//    int _year;
//    int _month;
//    int _day;
//};
//// 这里会发现运算符重载成全局的就需要成员变量是共有的，那么问题来了，封装性如何保证?
//// 这里其实可以用我们后面学习的友元解决，或者干脆重载成成员函数。
//bool operator==(const Date& d1, const Date& d2)
//{
//    return d1._year == d2._year
//        && d1._month == d2._month
//        && d1._day == d2._day;
//}
//void Test () {
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    cout<<(d1 == d2)<<endl;
//}
//
//int main(){
//    Test();
//    return 0;
//}
//class A{
//public:
//    int _a;
//};
//
//int main(){
//    A s;
//    s._a = 1;
//
//    A n;
//    n = s;
//
//    cout<<"n._a is : "<<n._a<<endl;
//
//    return 0;
//}
//
//union A{
//    short a;
//    char union_byte[sizeof(short)];
//};
//
//int mian(){
//    A test;
//    test.a = 0x0102;
//    if(test.union_byte[0] == 1 && test.union_byte[1] == 2){
//        cout<<"大端字节序"<<endl;
//    }
//    if(test.union_byte[0] == 2 && test.union_byte[1] == 1){
//        cout<<"小端字节序"<<endl;
//    }
//    else
//        cout<<"未知"<<endl;
//
//    return 0;
//}


//class Rect{
//public:
//    Rect(){
//        p = new int(50);
//    }
//
//    Rect(const Rect& r){
//        width = r.width;
//        height = r.height;
//        p = new int(50);
//        *p = *(r.p);
//    }
//    ~Rect(){
//        assert(p!=NULL);
//        delete p;
//    }
//private:
//    int width;
//    int height;
//    int *p;
//};
//int main(){
//    Rect rect1;
//    Rect rect2(rect1);
//    return 0;
//}
//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    } private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main() {
//    Date d1(2001,29,1);
//    // 这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的。
//    //此时调用浅拷贝完全可以解决拷贝问题，但当加入动态成员变量时，浅拷贝就不能很好的解决问题
//    Date d2(d1);
//    return 0;
//}
//此时调用浅拷贝完全可以解决拷贝问题，但当加入动态成员变量时，浅拷贝就不能很好的解决问题


//class Date{
//public:
//    Date(int year = 1900, int month = 1, int day = 1){
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    Date(const Date& d){
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//
//};

//int main() {
//    Date d1;
//    Date d2(d1);
//    return 0;
//}
//class CDemo {
//public:
//    ~CDemo() { cout << "destructor" << endl; }
//};
//
//void Func(CDemo obj) {
//    cout << "func" << endl;
//}
//
//CDemo d1;
//
//CDemo Test() {
//    cout << "test" << endl;
//    return d1;
//}
//int main() {
//    CDemo d2;
//    Func(d2);
//    Test();
//    cout << "after test" << endl;
//    return 0;
//}
//class CDemo {
//public:
//    ~CDemo() {  //析构函数
//        cout << "Destructor called"<<endl;
//    }
//};
//int main() {
//    CDemo array[2];  //构造函数调用2次
//    CDemo* pTest = new CDemo;  //构造函数调用
//    delete pTest;  //析构函数调用
//    cout << "-----------------------" << endl;
//    pTest = new CDemo[2];  //构造函数调用2次
//    delete[] pTest;  //析构函数调用2次
//    cout << "Main ends." << endl;
//    return 0;
//}
