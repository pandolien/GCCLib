#ifndef __LTOKEN_H__
#define __LTOKEN_H__
#include <stdlib.h>
#include "lPTRList.h"
#include "lString.h"
class lToken{
public:
    lToken();
    lToken(const lString*);
    ~lToken();
private:
    lString* Data;
    lPTRList SqurtList;
public:
    void Init(const lString*);
    void RemoveAll();
    void squrt(char);
    void* operator[](int n);
};
#endif