#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lString.h"
lString::lString(){
    Init();
}
lString::lString(const char *Dt){
    StrDt = NULL;
    Num = -1;
    Init(Dt);
    Temp();
}
lString::lString(const lString & Dt){
    StrDt = NULL;
    Num = -1;
    Init(Dt);
    Temp();
}
lString::~lString(){
    Remove();
}
void lString::Init(){
    StrDt = NULL;
    Num = -1;
    Temp();
}
void lString::Init(int n){
    Remove();
    StrDt = (char*)malloc(sizeof(char)*n);
    Num = n;
}
void lString::Init(const char *Dt){
    Remove();
    int N = strlen(Dt);
    StrDt = (char*)malloc(sizeof(char)*N);
    memmove(StrDt,Dt,sizeof(char)*N);
    Num = N;
}
void lString::Init(const lString &Dt){
    Remove();
    Num = Dt.GetSize();
    StrDt = (char*)malloc(sizeof(char)*Num);
    memmove(StrDt,Dt.GetStr(),sizeof(char)*Num);
}
void lString::Init(lString &Dt){
    Remove();
    Num = Dt.GetSize();
    StrDt = (char*)malloc(sizeof(char)*Num);
    memmove(StrDt,Dt.GetStr(),sizeof(char)*Num);
}
void lString::Remove(){
    if(isTemp())
        if(StrDt){
            free(StrDt);
            Num = -1;
        }
}
const char* lString::GetStr() const{
    return StrDt;
}
int lString::GetSize()const{return Num;}
bool lString::operator==(const char *Dt){
    int N = strlen(Dt);
    if(Num != N)return false;
    const char *thisDt = GetStr();
    for(int i= 0;i< Num;i++){
        if(thisDt[i]!= Dt[i]) return false;
    }
    return true;
}
bool lString::operator==(const lString &Dt){
    if(Dt.GetSize() != Num) return false;
    const char *StringDt = Dt.GetStr();
    for(int i = 0;i< Num;i++){
         if(StrDt[i] !=StringDt[i]) return false;
    }
    return true;
}
void lString::Add(const char D){
    if(Num == -1) Num = 0;
    char *Dt = (char*)malloc(sizeof(char)*Num+2);
    if(StrDt)memmove(Dt,StrDt,sizeof(char)*Num);
    Dt[Num] = D;
    Dt[Num+1] = '\0';
    if(StrDt) free(StrDt);
    StrDt = Dt;
    Num+=1;
}
