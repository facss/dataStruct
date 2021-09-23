#ifndef __MYHEAP_H__
#define __MYHEAP_H__

class MyHeap{
public:
    MyHeap(size_t heap_size);
    ~MyHeap();

    
    //模拟C标准库的malloc函数
    void* malloc(size_t size);

    //模拟C标准库的free函数
    void  free(void* p);

    //判断堆是否处于初始状态，用于debug
    bool  IsInitialStatus();

    //检查空闲块双向链表的合法性，用于debug
    bool  CheckBlkList();

private:

    //用双向链表把所有的空内存块【按地址从小到大】串起来
    struct MemBlock
    {
        MemBlock*     prev_blk;  //前一块
        MemBlock*     next_blk;  //后一块
        size_t        size;      //当前块的长度，不包括MemBlock结构体本身
        unsigned long checksum;  //前三个字段的校验和
    };

    //修改MemBlock结构体的成员后，更新校验和
    void UpdateBlockChecksum(MemBlock* blk);

    //验证校验和判断MemBlock是否有效
    bool IsValidBlock(MemBlock* blk);

    //堆的首地址和长度
    char*     mpHeapBuffer;
    size_t    mHeapSize;

    //指向第一个空闲内存块
    MemBlock* mpFreeBlockHead;
};
#endif


/*
//main函数

#include "MyHeap.h"
#include <vector>
#include <assert.h>


int main()
{
    static const int HEAP_SIZE = 100 * 1024 * 1024;
    static const int RUN_TIMES = 10000;

    MyHeap myHeap(HEAP_SIZE);

    //断言堆处于初始状态
    assert(myHeap.IsInitialStatus());

    std::vector<void*> pointers;
    for (int i = 0; i < RUN_TIMES; i++) {
        //平均每三次循环中，2次分配，一次释放
        int k = rand() % 3;       
        if (k != 0) {
            //随机长度
            int size = rand();
            void* p = myHeap.malloc(size);
            if (p) {
                assert(myHeap.CheckBlkList());
                
                //新分配的内存块填充随机值
                memset(p, rand(), size);
                pointers.push_back(p);
                assert(myHeap.CheckBlkList());
            }
        }
        else
        {
            //随机释放此前分配的内存块
            int pos = rand() % pointers.size();
            void* p = pointers.at(pos);
            pointers.erase(pointers.begin() + pos);
            myHeap.free(p);
            assert(myHeap.CheckBlkList());
        }
    }

    //最后释放全部内存块
    for (size_t i = 0; i < pointers.size(); i++) {
        myHeap.free(pointers.at(i));
    }

    //断言退回到了初始状态
    assert(myHeap.IsInitialStatus());
    return 0;
}
*/