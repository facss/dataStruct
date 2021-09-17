#pragma once

template <typename T>

class SharedPtr {
public:
    SharedPtr() : m_ref_cout(NULL) {}

private:
    int * m_ref_count;        
}
