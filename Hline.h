//
//
#ifndef Hline_h
#define Hline_h

#include "Line.h"

class Hline : public Line  {
public:
    Hline();
    virtual ~Hline();
    virtual int setnextline(Hline * pline);
    virtual int gonext();
    virtual int standby();

private:
    Hline(const Hline &right);
    const Hline &operator=(const Hline &right);
    Hline * mem_nextline;
};

inline int Hline::setnextline(Hline * pline)  {
    mem_nextline=pline;
    return 1;
}


#endif


