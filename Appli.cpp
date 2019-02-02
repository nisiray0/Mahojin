//
//
#include <stdio.h>
#include "Hline.h"
#include "Appli.h"

Appli::Appli() : mem_mahou(0),mem_nummgr(0) {
// Appli::Appli() : mem_mahou(NULL),mem_nummgr(NULL) {
}

Appli::~Appli() {
    int size;

    size=mem_mahou->getsize();
    delete mem_nummgr;
    for(int i=0;i<size;i++) {
        delete mem_vlines[i];
        delete mem_hlines[i];
    }
   
    for(int i=0;i<size*size;i++)  
        delete mem_boxes[i];

    delete mem_mahou;
}

int Appli::init(int pnum) {
    Line *pline;
    Hline *phline;
    Box *pbox;

    mem_nummgr=new Nummgr;
    mem_nummgr->init(pnum*pnum);
    mem_mahou=new Mahou;
    mem_mahou->init(pnum);

    for(int i=0;i<pnum;i++)  {
        phline=new Hline;
        phline->init(pnum);
        mem_hlines.push_back(phline);
        mem_mahou->sethline(phline,i);
    }

    for(int i=0;i<pnum;i++) {
        pline=new Line;
        pline->init(pnum);
        mem_vlines.push_back(pline);
        mem_mahou->setvline(pline,i);
    }

    for(int i=0;i<pnum;i++)  {
        for(int j=0;j<pnum;j++)  {
            pbox=new Box;
            mem_boxes.push_back(pbox);
            mem_mahou->setbox(j,i,pbox);
            mem_vlines[i]->setbox(pbox,j);
            mem_hlines[j]->setbox(pbox,i);
            pbox->setnummgr(mem_nummgr);
        }
    }

    for(int i=0;i<pnum -1;i++)
        mem_hlines[i]->setnextline(mem_hlines[i+1]);
    
    mem_hlines[pnum-1]->setnextline(0);
    // mem_hlines[pnum-1]->setnextline(NULL);

    for(int i=0;i<pnum;i++)  {
        for(int j=0;j<pnum-1;j++)
            mem_hlines[i]->getbox(j)->setnextbox(mem_hlines[i]->getbox(j+1));
        mem_hlines[i]->getbox(pnum-1)->setnextbox(0);
        // mem_hlines[i]->getbox(pnum-1)->setnextbox(NULL);
    }

    mem_mahou->standby();
    return 1;
}

int Appli::go() {
    int mahounum;
    int notend;
    
    mahounum=0;
    notend=mem_mahou->go();
    
    while(notend)  {
        if(mem_mahou->judge() == 1) {
            mahounum++;
            put();
        }
        notend=mem_mahou->go();
    }

    printf("\n魔方陣の数は%d個",mahounum);
    return mahounum;
}




void Appli::put() {
    for(int x=0;x<mem_mahou->getsize();x++) {
        for(int y=0;y<mem_mahou->getsize();y++)
            printf("%d ",mem_mahou->getnum(x,y));
        puts("");
    }
    puts("");
}

