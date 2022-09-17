#ifndef __LPTRLIST_H__
#define __LPTRLIST_H__
#include <stdlib.h>
typedef struct _BLOCK{
    _BLOCK *nPrev;
    _BLOCK *nNext;
    void *Data;
}BLOCK;
class lPTRList{
public:
    lPTRList();
    ~lPTRList();
public:
    BLOCK *pHead;
    BLOCK *pTail;
    BLOCK *pFind;
    int Num;
public:
    void Init();
    void RemoveAll(bool Check);
    BLOCK* NewBlock(void *);
    void AddTail(void *);
    void AddHead(void *);
    void* GetAt(int n);
    void* GetAt(void *);
};
#endif