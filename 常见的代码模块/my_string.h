#pragma once 
#include <string>

class MyString {
public:
    MyString() : data_(new char[1]) {
        *data_ = '\0';
    }
    MyString(const char * str) :data_(new char[strlen(str) - 1]) {
        
    }
private:
    char * data_;    
}