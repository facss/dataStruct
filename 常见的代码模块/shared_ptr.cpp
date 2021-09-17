//智能指针，引用计数法
#pragma once

template <typename T>   
class SharedPtr {
public:
//------------------------构造函数-----------------------------
    //默认构造函数
    SharedPtr(): m_ref_count(nullptr),m_pointer(nullptr) {}
    //构造函数,已有对象进行初始化
    SharedPtr(T * target) : m_ref_count(nullptr), m_pointer(target) {
        addReference();
    }
//------------------------拷贝构造函数------------------------
    SharedPtr(const SharedPtr& copy) : m_ref_count(copy.m_ref_count), m_pointer(copy.m_pointer) {
        addReference();
    }
//-------------------------析构函数---------------------------
    virtual ~SharedPtr() {
        removeReference();
    }
//---------------------赋值运算符重载函数----------------------
    SharedPtr& operator=(const SharedPtr& that) {
        if(this != &that) {
            removeReference();
            this->m_pointer = that.m_pointer;
            this->m_ref_count = that.m_ref_count;
            addRefence();
        }
        return this;
    }
//////////////////////////////////////////////////////////////////////////////////
//---------------------指针解引用-----------------------------------
    T& operator->() const {
        return m_pointer;
    }
//---------------------获得引用计数------------------------------
    int GetReference() const {
        if(m_ref_count) {
            return m_ref_count;
        } else {
            return -1;
        }
    }
protected:    
//----------------------新增引用计数------------------------
     //当为nullpter时，创建引用计数资源，并初始化为1，否则，引用计数加1。
    void addReference() {
        if(m_ref_count) {
            (*m_ref_count)++;
        } else {
            m_ref_count = new int(0);
            *m_ref_count = 1;
        }
    }
//---------------------回收引用计数------------------------------
    //引用计数减一，当变为0时，释放所有资源
    void removeReference() {
        if(m_ref_count) {
            (*m_ref_count)--;
            if(*m_ref_count == 0) {
                delete m_ref_count;delete m_pointer;
                m_pointer = 0;m_ref_count = 0;
            }
        }
    }
private:
    int * m_pointer;
    int * m_ref_count;        //引用计数,这里最好在堆中
}
