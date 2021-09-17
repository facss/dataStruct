//简易版本的string，参考陈硕的写法

#pragma once 
#include <string>

class MyString {
public:
    MyString() : data_(new char[1]) {
        *data_ = '\0';
    }
    MyString(const char * str) :data_(new char[strlen(str) + 1]) {
        strcpy(data_,str);
    }
    MyString(const string& rhs):data_(new char[rhs.size() + 1]) {
        strcpy(data_,rhs.c_str());
    }
    MyString(strring && rhs) {
        rhs.data_ = NULL;
    } 
    ~MyString() {
        delete[] data_;
    }

    MyString& operator= (MyString&& rhs) {
        std::swap(rhs);
        return * this;
    }
    size_t size() const {
        return  strlen(data_);
    }

    const char * c_str() {
        return data_;
    }
    void swap(String& rhs) {
        std::swap(data_,rhs.data_);
    }

private:
    char * data_;    
};