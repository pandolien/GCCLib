#include "lPTRList.h"
lPTRList::lPTRList(){
    Init();
}
lPTRList::~lPTRList(){
    RemoveAll(true);
}
void lPTRList::Init(){
    pHead = NULL;
    pTail = NULL;
    pFind = NULL;
    Num = 0;
}
void lPTRList::RemoveAll(bool Check){
    if(pHead == NULL || pTail == NULL)return;
    Num = 0;
    while(true){
        BLOCK *pTep = pHead->nNext;
        if(Check){if(pHead->Data) free(pHead);}
        else pHead->Data = NULL;
        free(pHead);
        if(pTep == NULL) break;
    }
}
BLOCK * lPTRList::NewBlock(void *D){
    BLOCK* New = (BLOCK*)malloc(sizeof(BLOCK));
    New->nNext = NULL;
    New->nPrev = NULL;
    New->Data = D;
    return New;
}
void lPTRList::AddTail(void *D){
    BLOCK* New = NewBlock(D);
    if(pHead == NULL) pHead = New;
    if(pTail){
        pTail->nNext = New;
        New->nPrev = pTail;
    }
    pTail = New;
    Num +=1;
}
void lPTRList::AddHead(void *D){
    BLOCK* New = NewBlock(D);
    if(pTail== NULL) pTail = New;
    if(pHead){
        pHead->nPrev = New;
        New->nNext = pHead;
    }
    pHead = New;
    Num+=1;
}
void* lPTRList::GetAt(int i){
    if(pTail == NULL || pHead == NULL) return NULL;
    if(i  >= Num) return NULL;
    if(i < 0) return NULL;
    if(i == 0) return pHead->Data;
    if(i == Num-1) return pTail->Data;
    pFind = pHead;
    int cnt = 1;
    while(1){
        pFind = pFind->nNext;
        if(pFind == NULL)return NULL;
        if(i == cnt) return pFind->Data;
        cnt+=1;
    }
    return NULL;
}
void* lPTRList::GetAt(void*D){
    if(pTail == NULL || pHead == NULL) return NULL;
    pFind = pHead;
    while(1){
        if(pFind == NULL) return NULL;
        if(pFind->Data == D) return pFind->Data;
        pFind = pFind->nNext; 
    }
    return NULL;
}