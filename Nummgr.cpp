//
//
#include "Nummgr.h"

Nummgr::Nummgr() : mem_max(0) {
}

Nummgr::~Nummgr() {
}

int Nummgr::init(int pmax) {
    mem_max=pmax;
    mem_numlist.resize(mem_max);
    for(int i=0;i<mem_max;i++)
        mem_numlist[i]=0;
    return pmax;
}

