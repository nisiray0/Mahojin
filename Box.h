//
//
#ifndef Box_h
#define Box_h

#include "Nummgr.h"

class Box  {
public:
    Box();
    virtual ~Box();
    virtual int setnummgr(Nummgr *pnummgr);
    virtual int setnextbox(Box *pbox);
    virtual int gonext();
    virtual int nextnum();
    virtual int standby();
    virtual const int getnum() const;
    virtual void setnum(const int value);

private:
    Box(const Box &right);
    const Box &operator=(const Box &right);
    int mem_num;
    Nummgr *mem_nummgr;
    Box * mem_nextbox;
};

inline const int Box::getnum() const {
    return mem_num;
}

inline void Box::setnum(const int value)  {
    mem_num=value;
}

inline int Box::setnummgr(Nummgr * pnummgr)  {
    mem_nummgr=pnummgr;
    return 1;
}

inline int Box::setnextbox(Box *pbox)  {
    mem_nextbox=pbox;
    return 1;
}

#endif

