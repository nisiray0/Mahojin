//
//
//
#ifndef Nummgr_h
#define Nummgr_h

#include <vector>

using namespace std;

class Nummgr {
public:
    Nummgr();
    virtual ~Nummgr();
    virtual int isused(int pnum);
    virtual int getmax();
    virtual int usenum(int pnum);
    virtual int delnum(int pnum);
    virtual int init(int pamx);
private:
    Nummgr(const Nummgr &right);
    const Nummgr &operator=(const Nummgr &right);
    vector <int> mem_numlist;
    int mem_max;
};

inline int Nummgr::isused(int pnum)  {
    return mem_numlist[pnum -1];
}

inline int Nummgr::usenum(int pnum)  {
    mem_numlist[pnum-1]=1;
    return pnum;
}

inline int Nummgr::delnum(int pnum)  {
    mem_numlist[pnum-1]=0;
    return pnum;
}

inline int Nummgr::getmax()  {
    return mem_max;
}

#endif

