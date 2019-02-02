//
//
#ifndef Appli_h
#define Appli_h

#include "Hline.h"
#include "Nummgr.h"
#include "Box.h"
#include "Line.h"
#include "Mahou.h"

class Appli {
public:
    Appli();
    virtual ~Appli();
    virtual int init(int pnum);
    virtual int go();
    virtual void put();

private:
    Appli(const Appli &right);
    const Appli & operator=(const Appli &right);

    Mahou * mem_mahou;
    vector <Line *> mem_vlines;
    Nummgr * mem_nummgr;
    vector <Box *> mem_boxes;
    vector <Hline *> mem_hlines;
};

#endif


