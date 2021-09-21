
//内存池子，参考c++高级进阶教程写法
template<int ObjectSize,int NumOfObjects = 20>
class Mempool {
private:
    const int MemBlockSize;//每个内存块的大小
    const int ItemSize;//每个内存结点大小
    struct _FreeNode {
        _FreeNode* pNext;
        char data[ObjectSize];
    };
    struct _MemBlock {
        _MemBlock *pNext;
        _FreeNode data[NumOfObjects];
    };
    _MemBlock* pMemBlockHeader;
    _FreeNode* pFreeNodeHeader;
private:
    Mempool() : ItemSize(ObjectSize + sizeof(_FreeNode*)),
        MemBlockSize(sizeof(_MemBlock*) + NumOfObjects * (ObjectSize + sizeof(_FreeNode*))){
            pMemBlockHeader = NULL;
            pFreeNodeHeader = NULL;
        }
    ~Mempool() {
        _MemBlock *ptr;
        while(pMemBlockHeader) {
            ptr = pMemBlockHeader->pNext;
            delete pMemBlockHeader;
            pMemBlockHeader = ptr;
        }
    }
    void * malloc();
    void free(void*);
};

template<nt ObjectSize,int NumOfObjects>
void * Mempool<ObjectSize,NumOfObjects>::malloc() {
    if(pFreeNodeHeader == NULL) {
        _MemBlock *pNewBlock = new _MemBlock;
        pNewBlock->data[0].pNext = NULL;
        for(int i = 1;i < NumOfObjects;++i) {
            pNewBlock->data[i].pNext = &pNewBlock->data[i-1];
        }
        pFreeNodeHeader=&pNewBlock->data[NumOfObjects-1];
        pNewBlock->pNext = pMemBlockHeader;
        pMemBlockHeader = pNewBlock;
    }
    void * pFreeNode =pFreeNodeHeader;
    pFreeNodeHeader = pFreeNodeHeader->pNext;
    return pFreeNode;
}

template<nt ObjectSize,int NumOfObjects>
void Mempool<ObjectSize,NumOfObjects>::free(void *p) {
    _FreeNode *pNode = (_FreeNode*)p;
    pNode->pNext = pFreeNodeHeader;
    pFreeNodeHeader = pNode;
}
//end of mempool.h

/*
#include <iostream>
#include "mempool.h"

using namespace std;
class ActualClass {
    static int count;
    int num[10];
public:
    ActualClass() {
        count++;
        for(int i = 0;i < 10;++i) {
            num[i] = coiunt + i;
        }
    }
    void show() {
        cout << this << ":";
        for(int i =0i < 1-=0;++i) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    void * operator new (size_t size);
    void operator delete (void * p);
};
class MemoryPool {
    static Mempool<sizeof(ActualClass),2> mp;
    friend class ActualClass;
};

void * ActualClass::operator new (size_t size) {
    return theMemoryPoll::mp.malloc();
}

void ActualClass::operator delete (void *p) {
    theMemoryPoll.free(p);
}

MemPoll<sizeof(ActualClass),2> theMemoryPoll::mp;
int ActualClass::count;

int main() {
    ActualClass *pq = new ActualClass;
    p1->show();
    ActualClass p2 = new ActualClass;
    p2->show();

    delete p1;
    p1 = new ActualClass;
    p1->show();
    ActualClass *p3 = new ActualClass;
    p3->show();
    delete p1;
    delete p2;
    delete p3;
}

*/