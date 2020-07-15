#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string>

using namespace std;
typedef int DataType;

class Vector{
    public:
        Vector()
            :_first(nullptr)
            ,_finish(nullptr)
            ,_endofstorage(nullptr)
        {}

        ~Vector()
        {
            if(_first)
            {
                delete[] _first;
                _first = _finish = _endofstorage = nullptr;
            }
        }

        size_t _size() const
        {
            return _finish - _first;
        }

        size_t _capacity() const{
            return _endofstorage - _first;
        }

        Vector(const Vector& v)
        {
            //只开辟了_size的空间
            _first = new DataType[v._size()];
            _finish = _first + v._size();
            _endofstorage = _first + _size();

            memcpy(_first,v._first,sizeof(DataType)*v._size());
        }

        Vector& operator=(Vector v)
        {
            swap(this->_first,v._first);
            swap(this->_finish,v._finish);
            swap(this->_endofstorage,v._endofstorage);

            return *this;
        }

        void _revers(size_t n)
        {
            if(n > _capacity())
            {
                _expand(n);
            }
        }

        void _resize(size_t n,DataType value)
        {
            if(n < _size())
            {
                _finish = _first + n;
            }
            else
            {
                if(n > _capacity())
                {
                    _expand(n);
                }
                DataType* end = _first + n;
                while(_finish < end)
                {
                    *_finish = value;
                    ++_finish;
                }
            }

        }

        DataType& operator[](size_t pos)
        {
            return _first[pos];
        }

        void _push_back(DataType n)
        {
            _insert(_size(),n);
            // if(_finish == _endofstorage)
            // {
            //     size_t newcapacity = _capacity() > 0 ? _capacity()*2 : 3;
            //     _expand(newcapacity);
            // }
            // *_finish = n;
            // _finish++;
        }

        void _pop_back()
        {
            assert(_finish > _first);
            --_finish;
        }

        void _insert(size_t pos,DataType n)
        {
            assert(pos >= 0 && pos <= _size());
            size_t size = _size();
            if(_finish == _endofstorage)
            {
                size_t newcapacity = _capacity() > 0 ? _capacity()*2 : 3;
                _expand(newcapacity);
            }
            for(int i = size;i > pos;i--)
            {
                _first[i] = _first[i - 1];
            }
            _first[pos] = n;
            ++_finish;
            
        }

        void _erase(size_t pos)
        {
            assert(pos >= 0 && pos <= _size());
            size_t size = _size();
            for(int i = pos;i < size;i++)
            {
                _first[i] = _first[i+1];
            }
            --_finish;
        }

        size_t _find(DataType n)
        {
            size_t size = _size();
            for(int i = 0;i < size;i++)
            {
                if(_first[i] == n)
                    return i;
            }
        }
    private:
        void _expand(size_t n)
        {
            if(n > _capacity())
            {
                size_t size = _size();
                DataType* tmp = new DataType[n];
                memcpy(tmp,_first,size*sizeof(DataType));

                delete[] _first;
                _first = tmp;
                _finish = _first + size;
                _endofstorage = _first + n;
            }
        }
    protected:
        DataType* _first;   //指向顺序表的第一个位置
        DataType* _finish;  //指向顺序表中最后一个数据的下一个位置
        DataType* _endofstorage;    //指向表的容量的最大位置的下一个位置
};

int main(){
    Vector v;
    v._push_back(1);
    v._push_back(2);
    v._push_back(3);

    for(size_t i = 0;i < v._size();i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}
