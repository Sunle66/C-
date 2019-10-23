#include<iostream>
#include<string>
#include<vector>
using namespace std;


//int mian(){
//    vector<int> w;
//    for(int i = 0;i < 10;i++){
//        w.push_back(i);
//        //cout<<w[i]<<endl;
//    }
//
//    w.resize(5);
//    w.resize(10,100);
//    w.resize(12);
//
//    cout<<"w changed:";
//    for(int i = 0;i < w.size();i++){
//        cout<<w[i]<<' ';
//    }
//
//    return 0;
//}
//int main(){
//    size_t e;
//    vector <int> foo;
//    e = foo.capacity();
//    cout<<"making foo grow"<<endl;
//
//    for(int i = 0;i < 100;i++){
//        foo.push_back(1);
//        if(e != foo.capacity()){
//            e = foo.capacity();
//            cout<<"capacity changed: "<<e<<endl;
//        }
//    }
//
//    vector<int> fcc;
//    e = fcc.capacity();
//    fcc.reserve(100);
//    cout<<"making fcc grow: "<<endl;
//
//    for(int i =0;i<100;i++){
//        fcc.push_back(2);
//        if(e != fcc.capacity()){
//            e = fcc.capacity() ;
//            cout<<"capacity changed: "<<e<<endl;
//        }
//    }
//
//    return 0;
//}

//void TestString()
//{
//    string str;
//    str.push_back(' ');     // 在str后插入空格
//    str.append("hello");    // 在str后追加一个字符"hello"
//    str += 'b';             // 在str后追加一个字符'b'
//    str += "it";            // 在str后追加一个字符串"it"
//    cout<<str<<endl;
//    cout<<str.c_str()<<endl; // 以C语言的方式打印字符串
//
//    // 获取file的后缀
//    string file("string.cpp");
//    size_t pos = file.rfind('.');
//    string suffix(file.substr(pos, file.size()-pos));
//    cout << suffix << endl;
//
//    // npos是string里面的一个静态成员变量
//    // static const size_t npos = -1;
//    // 取出url中的域名
//    string url("http://www.cplusplus.com/reference/string/string/find/");
//    cout << url << endl;
//
//    size_t start = url.find("://");
//    if(start == string::npos){
//        cout<<"invalid url"<<endl;
//        return;
//    }
//
//    start += 3;
//    size_t finish = url.find('/',start);
//    string address = url.substr(start,start-finish);
//    cout<<address<<endl;
//
//    //删除url的前缀协议
//    pos = url.find("://");
//    url.erase(0,pos+3);
//    cout<<url<<endl;
//
//}
////利用reserve 提高插入数据的效率，避免增容带来的开销
//void TestPushBack(){
//    string s;
//    size_t sz = s.capacity();
//    cout<<"making s grow: "<<sz<<endl;;
//    for(int i = 0;i < 100;i++){
//        s += 'c';
//        if(sz != s.capacity()){
//            sz = s.capacity();
//            cout<<"capacity changed : "<<sz<<endl;
//        }
//    }
//}
//
//void TestPushBack_p(){
//    string s;
//    s.reserve(100);
//    size_t sz = s.capacity();
//
//    cout<<"making s grow:"<<sz<<endl;
//    for(int i = 0;i < 100;i++){
//        s += 'c';
//        if(sz != s.capacity()){
//            sz = s.capacity();
//            cout<<"capacity changed: "<<sz<<endl;
//        }
//    }
//}
//
//class Solution{
//public:
//    //翻转字符串
//    string reverseString(string s) {
//        if(s.empty())
//            return s;
//
//        size_t start = 0;
//        size_t end = s.size() - 1;
//
//        while(start < end){
//            swap(start, end);
//            ++start;
//            --end;
//        }
//        return s;
//    }
//
//    //找出字符串中第一个只出现一次的字符
//    int firstUniqChar(string s){
//        //统计出每个字符出现的次数
//        int count[256] = {0};
//
//        for(int i = 1;i < s.size();i++){
//            count[s[i]] += 1;
//        }
//        //z按照字符次序从前往后找，找到只出现一次的字符
//        for(int i = 0;i < s.size();i++){
//            if(count[s[i]] == 1)
//                return i;
//        }
//        return -1;
//    }
//
//    //验证一个字符串是否回文
//    bool IsNumberOrLetter(char c)
//    {
//        if ((c >= '0' && c <= '9')||
//            (c >= 'a' && c <= 'z')||
//            (c >= 'A' && c <= 'Z'))
//        {
//            return true;
//        }
//        return false;
//    }
//    bool isPalindrome(string s){
//        if(s.empty())
//            return true;
//
//        size_t begin = 0;
//        size_t end = s.size() - 1;
//        while(begin < end){
//            //从前玩后找一个数字或者字符
//            while(begin != end){
//                if(IsNumberOrLetter(s[begin]))
//                    break;
//                ++begin;
//            }
//
//            //从后往前找一个数字或者字符
//            while(begin < end){
//                if(IsNumberOrLetter(s[end]))
//                    break;
//                --end;
//            }
//
//            if (begin < end){
//                // 检测start和end位置字符是否相等 或者是否不区分大小的相等
//                if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
//                    return false;
//                ++begin;
//                --end;
//            }
//        }
//        return true;
//    }
//
//    //字符串相加
//    string addStrings(string num1, string num2){
//        size_t LSize = num1.size();
//        size_t RSize = num2.size();
//
//
//        // 以长字符串作为外部循环 if(LSize < RSize)
//        {
//            num1.swap(num2);
//            swap(LSize, RSize);
//        }
//        string strRet;
//        strRet.reserve(LSize+1);
//        char cRet = 0;
//        char cstep = 0;
//        for(size_t i = 0; i < LSize; ++i)
//        {
//            cRet = num1[LSize - i - 1] - '0' + cstep;
//            cstep = 0;
//            if(i < RSize)
//            {
//                cRet += num2[RSize - i - 1] - '0';
//            }
//            if(cRet >= 10)
//            {
//                cRet -= 10;
//                cstep = 1; }
//            strRet += cRet + '0';
//        }
//        if(cstep)
//            strRet += '1';
//        reverse(strRet.begin(), strRet.end());
//        return strRet;
//    }
//
//};
//
////求字符串最后一个单词的长度
//void A(){
//    string line;
//    //cin<<line遇到空格就会结束
//    //while(cin<<line)
//    while(getline(cin,line)){
//        size_t pos = line.rfind(' ');
//        cout<< line.size() - pos - 1<<endl;
//    }
//}

//class A{
//public:
//    int _a;
//
//};
//// class B : public A
//class B : virtual public A{
//public:
//    int _b;
//};
//// class C : public A
//class C : virtual public A{
//public:
//    int _c;
//};
//class D : public B, public C{
//public:
//    int _d;
//
//};

//
//int main(){
////    TestString();
//    TestPushBack();
//    TestPushBack_p();
//    return 0;
//
//}

//class String{
//public:
//    String(const char* str = ""){
//        //构造string类对象时，传递nullptr指针被认定为非法
//        if(str == nullptr){
//            assert(false);
//            return;
//        }
//
//        _str = new char[strlen(str) + 1];
//        strcpy(_str,str);
//    }
//
//    ~String(){
//        if(_str){
//            delete[] _str;
//        }
//    }
//private:
//    char* _str;
//};。
//
//int main(){
//    String s1("hello,bit");
//    String s2(s1);
//}
////String类没有显式定义其拷贝构造函数与赋值运算符重载，
////此时编译器会合成默认的，当用s1构 造s2时，编译器会调用默认的拷贝构造。
////最终导致的问题是，s1、s2共用同一块内存空间
////在释放时同一块 空间被释放多次而引起程序崩溃，这种拷贝方式，称为浅拷贝  _str = nullptr;

//class String{
//public:
//    String(const char* str = ""){
//        //构造string类对象时，传递nullptr指针被认定为非法
//        if(str == nullptr){
//            assert(false);
//            return;
//        }
//
//        _str = new char[strlen(str) + 1];
//        strcpy(_str,str);
//    }
//    String(const String& s)
//        :_str(new char[strlen(s._str) + 1])
//    {
//        strcpy(_str,s._str);
//    }
//   // 传统版写法
//    String& operator=(const String& s){
//        if(this != &s){
//            char* pStr = new char[strlen(s._str) + 1];
//            strcpy(pStr,s._str);
//            delete[] s._str;
//            _str = pStr;
//        }
//        return *this;
//    }
//    //现在版写法
////
////    String& operator=(const String& s){
////        swap(_str,s._str);
////        return *this;
////
//    ~String(){
//        if(_str){
//            delete[] _str;
//            _str = nullptr;
//        }
//    }
//private:
//    char* _str;
//};
//
//namespace bit {
//    class String{
//    public:
//        typedef char* Iterator;
//    public:
//        //构造函数
//        String(const char* str = ""){
//            if(str ==nullptr){
//                assert(false);
//                return;
//            }
//
//            _size = strlen(str);
//            _capacity = _size;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//        //拷贝构造
//        String(const String& s)
//        :_size(s._size)
//        ,_capacity(s._capacity)
//        ,_str(new char[s._capacity + 1])
//        {
//            strcpy(_str,s._str);
//        }
//        //赋值操作
//        String& operator=(const String& s){
//            if(this != &s){
//                char* pStr = new char[s._capacity + 1];
//                strcpy(pStr,s._str);
//
//                delete[] s._str;
//                _str = pStr;
//                _size = s._size;
//                _capacity = s._capacity;
//            }
//            return *this;
//        }
//
//        Iterator begin(){
//            return _str;
//        }
//
//        Iterator end(){
//            return _str + _size;
//        }
//        //析构函数
//        ~String(){
//            if(_str){
//                delete[] _str;
//                _str = nullptr;
//            }
//        }
/////////////////////////modify
//        //清理内存空间
//        void Clear(){
//            _size = 0;
//            _str[_size] = '\0';
//        }
//        //尾插一个字符
//        void Push_Back(char c){
//            if(_size == _capacity)
//                Reserve(_capacity*2);
//
//            _str[_size++] = c;
//            _str[_size] = '\0';
//        }
//        //追加n个字符
//        void Append(size_t n,char c){
//            for(size_t i = 0;i < n;i++){
//                Push_Back(c);
//            }
//        }
//        //追加一个字符串
//        void Append(const char* str){
//            for(size_t i = 0;i < strlen(str);i++){
//                Push_Back(str[i]);
//            }
//        }
//        //加一个字符
//        String& operator+=(char c){
//            Push_Back(c);
//            return *this;
//        }
//        //加一个字符串
//        String& operator+=(const char* str){
//            Append(str);
//            return *this;
//        }
//
//        void Swap(String& s){
//            swap(_str,s._str);
//            swap(_size,s._size);
//            swap(_capacity,s._capacity);
//        }
//
//        const char* C_Str()const{
//            return _str;
//        }
//        //在pos位置上插入一个字符，并返回字符的位置
//        String& Insert(size_t pos, char ch){
//            assert(pos < _size);
//            size_t end = _size;
//            if (_size == _capacity){
//                Reserve(_capacity * 2);
//            }
//            for (end = _size; end >= (int)pos; --end){
//                _str[end+1] = _str[end];
//            }
//            _str[pos] = ch;
//            ++_size;
//            _str[_size] = '\0';
//            return *this;
//        }
//        //在pos位置上插入一个字符串，并返回该字符串的位置
//        String& Insert(size_t pos, const char* str){
//            assert(pos <= _size);
//            size_t len = strlen(str);
//            if (len + _size>_capacity){
//                Reserve(len + _size);
//            }
//            for (size_t i = _size + len; i > pos; --i){
//                _str[i] = _str[i - len];
//            }
//            for (size_t j = 0; j < len; ++j){
//                _str[pos+j] = str[j];
//                ++_size;
//            }
//            _str[_size] = '\0';
//            return *this;
//        }
//        //删除pos位置上的元素，并返回该元素的下一个位置
//        String& Erase(size_t pos, size_t len){
//            if (pos + len >= _size - 1){
//                _str[pos] = '\0';
//                _size = pos;
//            }
//            else{
//                strcpy(_str + pos, _str + pos + len);
//            }
//            _size -= len;
//            _str[_size] = '\0';
//            return *this;
//        }
//        //返回ch在string中第一次出现的位置
//        size_t Find(char ch, size_t pos = 0){
//            assert(pos < _size);
//            for (size_t i = pos; i < _size; ++i){
//                if (_str[i] == ch){
//                    return i;
//                }
//            }
//            return 0;
//        }
//
//        //返回str在string中第一次出现的位置
//        size_t Find(const char* str, size_t pos = 0){
//            assert(pos<_size);
//            size_t begin = pos;//源字符串_str的下标从pos位置开始找
//            size_t len = strlen(str);
//            while (begin < _size){
//                size_t i = 0;//控制str的下标从0开始
//                size_t start = begin;
//                while (_str[start] == str[i]){
//                    ++i;
//                    ++start;
//                    if (i == len){
//                        //此时字符串str已经走到末尾了
//                        return begin;
//                    }
//                }
//                ++begin;
//            }
//            return -1;
//        }
//        ///////////////////
//        /////capacity
//        //将有效字符个数改成newSize个，多出的用c填充
//        size_t Size()const{
//            return _size;
//        }
//
//        size_t Capacity()const{
//            return _capacity;
//        }
//
//        bool Empty(){
//            return 0==_size;
//        }
//
//        void Resize(size_t newSize,char c = char()){
//            if(newSize > _size){
//                //如果newSize大于底层空间，则需要重新开辟新的空间
//                if(newSize > _capacity)
//                    Reserve(newSize);
//
//                memset(_str + _size, c,newSize - _size);
//            }
//            _size = newSize;
//            _str[newSize] = '\0';
//        }
//        //为字符串预留空间
//        void Reserve(size_t newCapacity){
//            // 如果新容量大于旧容量，则开辟空间
//            if (newCapacity > _capacity){
//                char* str = new char[newCapacity + 1];
//                strcpy(str, _str);
//
//                // 释放原来旧空间,然后使用新空间
//                delete[] _str;
//                _str = str;
//                _capacity = newCapacity;
//            }
//        }
//
//        ///////////access小标访问
//        char& operator[](size_t index){
//            assert(index < _size);
//            return _str[index];
//        }
//
//        char& operator[](size_t index)const{
//            assert(index < _size);
//            return _str[index];
//        }
//        //判断大小关系
//        bool operator<(const String& s){
//            size_t index1 = 0;
//            size_t index2 = 0;
//            while(index1 < _size && index2 < s._size){
//                if(_str[index1] < s._str[index2]){
//                    return true;
//                }
//                ++index1;
//                ++index2;
//            }
//            return false;
//        }
//
//        bool operator<=(const String& s){
//            return *this < s || *this == s;
//        }
//
//        bool operator>(const String& s){
//            return !(*this < s || *this > s);
//        }
//
//        bool operator>=(const String& s){
//            return !(*this < s);
//        }
//        //判断两个字符串相等
//        bool operator==(const String& s){
//            //判断两个字符串字符个数是否相等
//            if(s._size != _size){
//                return false;
//            }
//            //从第一个字符开始遍历
//            size_t i = 0;
//            while(_str[i] == s._str[i] && i < _size){
//                i++;
//            }
//            if(i == _size && s._str[i] =='\0'){
//                return true;
//            }
//            return false;
//        }
//
//        bool operator!=(const String& s){
//            return !(*this == s);
//        }
//
//
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity;
//    };
//}
//
//void TestBitString1(){
//    bit::String s1("hello");
//    bit::String s2("world");
//    bit::String s3(s2);
//
//    cout<< s1.C_Str() <<endl;
//    cout<< s2.C_Str() <<endl;
//    cout<< s3.C_Str() <<endl;
//
//    //利用迭代器打印s1；
//    bit::String::Iterator it = s1.begin();
//    while(it != s1.end()){
//        cout<< *it << " " ;
//        it++;
//    }
//    cout<<endl;
//    for(auto e : s1){
//        cout<< e <<" ";
//    }
//}
//
//void TestBitString2(){
//    bit::String s("hai");
//
//    s.Push_Back(' ');
//    s.Append(1, 'W');
//    cout<<s.C_Str()<<endl;
//    s.Push_Back(' ');
//    s.Append("nihao");
//    cout<< s.C_Str()<<endl;
//    s.Push_Back(' ');
//    s += "wo";
//    cout<< s.C_Str()<<endl;
//    s.Push_Back(' ');
//    s.Insert(15, "ai");
//    cout<< s.C_Str()<<endl;
//    s.Push_Back(' ');
//    s += "ni";
//    cout<< s.C_Str()<<endl;
//
//    s.Find('W');
//    s.Find("ai");
//
//}
//void TestBitString3(){
//    bit::String s1("hello");
//    s1.Push_Back(' ');
//    s1.Push_Back('w');
//    s1.Push_Back('o');
//    s1.Push_Back('r');
//    s1.Push_Back('l');
//    s1.Push_Back('d');
//    s1.Push_Back(' ');
//    s1.Append("code");
//
//    cout << s1.Size() << endl;
//    cout << s1.Capacity() << endl;
//    s1.Clear();
//    cout << s1.Size() << endl;
//
//}
//
//void TestBitString4(){
//    bit::String s1("aibdbyaad");
//    bit::String s2("andiundni");
//
//    cout << s1[2] << endl;
//    cout << (s1 > s2) << endl;
//    cout << (s1 < s2) << endl;
//    cout << (s1 >= s2) << endl;
//    cout << (s1 <= s2) << endl;
//    cout << (s1 == s2) << endl;
//    cout << (s1 != s2) << endl;
//}
//int main(){
//    //TestBitString1();
//    //TestBitString2();
//    //TestBitString3();
//    TestBitString4();
//    return 0;
//}
//
//class Person{
//public:
//    virtual ~Person(){
//        cout<<"~Person()"<<endl;
//    }
//};
//
//class Student : public Person{
//    ~Student(){
//        cout<<"~Student()"<<endl;
//    }
//};
//
//int main(){
//    Person* p =new Student;
//    delete p;
//
//    return 0;
//}
//
//class Car{
//public:
//    virtual void Drive() = 0;
//};
//class Benz : public Car{
//public:
//    virtual void Drive(){
//        cout<<"benz-舒适"<<endl;
//    }
//};
//
//class BMW : public Car{
//public:
//    virtual void Drive(){
//        cout<<"BMW-操控"<<endl;
//    }
//};
//class Base{
//public:
//    virtual void Func1(){
//        cout<<"Func!()"<<endl;
//    }
//private:
//    int _b = 1;
//};
//
//int main(){
//    int a = 0;
//    static int b = 0;
//    char* p = "hello";
//    int* ptr = new int;
//    Base base;
//
//    printf("栈：%p\n",&a);
//    printf("数据段:%p\n",&b);
//    printf("代码段：%p\n",&p);
//    printf("堆:%p\n",ptr);
//    printf("虚表:%p\n",(int*)&base);
//    return 0;
//}
//
//class Base1 {
//public:
//    virtual void func1() {cout << "Base1::func1" << endl;}
//    virtual void func2() {cout << "Base1::func2" << endl;}
//private:
//    int b1;
//
//};
//class Base2 {
//public:
//    virtual void func1() {cout << "Base2::func1" << endl;}
//    virtual void func2() {cout << "Base2::func2" << endl;}
//private:
//    int b2;
//
//};
//class Derive : public Base1, public Base2 {
//public:
//    virtual void func1() {cout << "Derive::func1" << endl;}
//    virtual void func3() {cout << "Derive::func3" << endl;}
//private:
//    int d1;
//
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//    cout << " 虚表地址>" << vTable << endl; for (int i = 0; vTable[i] != nullptr; ++i) {
//        printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]); VFPTR f = vTable[i];
//        f();
//    }
//    cout<<endl;
//}
//int main(){
//    cout<<sizeof(Base1)<<endl;
//    cout<<sizeof(Base2)<<endl;
//    cout<<sizeof(Derive)<<endl;
//    return 0;
//}
//int main() {
//    Derive d;
//    VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//    PrintVTable(vTableb1);
//    VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d+sizeof(Base1)));
//    PrintVTable(vTableb2);
//    return 0;
//}

//int fun(int a,int b){
//    if(b == 0){
//        throw "daiudiu";
//    }
//    return a/b;
//}
//
//int main(){
//    int a = 10;
//    int b = 0;
//
//    fun(a,b);
//    return 0;
//}
