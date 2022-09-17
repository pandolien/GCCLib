#include "lToken.h"
lToken::lToken(){
    Data = NULL;
}
lToken::lToken(const lString *Dt){
    Init(Dt);
}
lToken::~lToken(){
    RemoveAll();
}
void lToken::Init(const lString *Dt){
    Data = (lString*)Dt;
}
void lToken::RemoveAll(){
    for(int i =0;i< SqurtList.Num;i++){
        lString *D = (lString*)SqurtList.GetAt(i);
        D->Remove();
    }
    SqurtList.RemoveAll(true);
    Data = NULL;
}
void lToken::squrt(char D){
    char *Dt = Data->GetStr2();
    int Max = Data->GetSize2();
    lString *Save = (lString*)malloc(sizeof(lString));
    Save->Init("");
    Save->Temp();
    for(int i = 0;i< Max;i++){
        if(Dt[i] == D){
            SqurtList.AddTail(Save);
            Save = NULL;
            Save = (lString*)malloc(sizeof(lString));
            Save->Init();
            continue;
        }
        Save->Add(Dt[i]);
    }
    SqurtList.AddTail(Save);
}
void* lToken::operator[](int n){
    return SqurtList.GetAt(n);
}