//
//
#ifndef Line_h
#define Line_h

#include <vector>
#include "Box.h"

// class Box;

using namespace std;

class Line  {
public:
    Line();
    virtual ~Line();
    virtual int isjustice();
    virtual int setbox(Box * pbox,int ppos);
    virtual int init(int psize);
    virtual Box * getbox(int pindex);
    virtual int getsize();
protected:
    vector <Box *> mem_box;

private:
    Line(const Line &right);
    const Line &operator=(const Line &right);
    static int mem_size;
    static int mem_sum;
};

inline int Line::setbox(Box *pbox,int ppos)  {
    mem_box[ppos]=pbox;
    return 1;
}

inline Box * Line::getbox(int pindex)  {
    return mem_box[pindex];
}

inline int Line::getsize()  {
    return mem_size;
}

#endif


