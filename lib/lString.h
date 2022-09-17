#ifndef __LSTRING_H__
#define __LSTRING_H__
class lString{
public:
    lString();
    lString(const char *);
    lString(const lString & Dt);
    ~lString();
private:
    char *StrDt;
    int Num;
    bool temp;
public:
    bool isTemp(){return temp;};
    void RemoveTemp(){
        if(temp== false){
            if(StrDt) free(StrDt);
            Num = -1;
        }
    };
    void NoTemp(){temp = false;};
    void Temp(){temp = true;};
public:
    void Init();
    void Init(int n);
    void Init(const char *);
    void Init(const lString & Dt);
    void Init(lString & Dt);
    void Remove();
    const char* GetStr()const;
    char* GetStr2(){return StrDt;};
    int GetSize()const;
    int GetSize2(){return Num;};
    bool operator ==(const char *);
    bool operator ==(const lString &);
    void Add(const char);
};
#endif