#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

struct Node;
typedef int elementType;
typedef struct Node : ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;
void delete(elementType x, list l);


struct Node
{
    elementType element;
    struct Node * next;
};

#endif