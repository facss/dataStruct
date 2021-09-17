//vector的简单实现

#pragma once 

namespace MySTL {
template <typename T>
class vector {
public:
    typedef T* iterator;
    typedef T*  reserve_iterator;
public:
    vector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}
    vector(size_t n ,const T&value) {
        _start = new T[n];
        //向空间中存放n个值为value的元素

    }
    
private:
    T * _start; //实际存储的size开始位置    
    T * _finish;//实际的存储size末尾位置 
    T * _end_of_storage;//容量位置，一般来说storage是大于等于finish
};
}