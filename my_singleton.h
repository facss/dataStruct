#pragma once
#include <iostream>

template<typename T>

class Singleton {
public:
    static T & get_instance() {
        static T instance;
        return instance;
    }    
    virtual ~Singleton() {
        std::cout << "desctructor called." << endl;
    }
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton&) = delete;
protected:
    Singleton() {
        std::cout << "constructor called." << endl;
    }
}