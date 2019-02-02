//
//
#include "Box.h"
#include "Line.h"

int Line::mem_size=0;
int Line::mem_sum=0;

Line::Line() {
}

Line::~Line() {
}

int Line::isjustice() {
    int ret=0;
    int sum=0;

    for(int i=0;i<mem_size;i++)
        sum += mem_box[i]->getnum();
    if(sum == mem_sum)
        ret = 1;

    return ret;
}


int Line::init(int psize) {
    mem_size=psize;
    mem_sum=(psize *psize) * (psize * psize +1)/2/psize;
    mem_box.resize(psize);
    return 1;
}


