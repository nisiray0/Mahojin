//
//
#ifndef Mahou_h
#define Mahou_h

class Mahou  {
public:
    Mahou();
    virtual ~Mahou();
    virtual int go();
    virtual int init(int pnum);
    virtual int judge();
    virtual int sethline(Hline *pline,int pindex);
    virtual int setvline(Line *pline,int pindex);
    virtual int standby();
    virtual int getnum(int px,int py);
    virtual void setbox(int px,int py,Box *pbox);
    virtual const int getsize() const;

private:
    Mahou(const Mahou &right);
    const Mahou &operator=(const Mahou &right);
    int mem_size;
    int mem_max;

    vector <Line *> mem_vline;
    vector <Hline *> mem_hline;
    vector <Box *> mem_boxes;
};

inline const int Mahou::getsize() const  {
    return mem_size;
}

inline int Mahou::sethline(Hline *pline,int pindex)  {
    mem_hline[pindex]=pline;
    return 1;
}

inline int Mahou::setvline(Line * pline,int pindex)  {
    mem_vline[pindex]=pline;
    return 1;
}

inline int Mahou::getnum(int px,int py)  {
    int ret;

    ret=mem_boxes[px * mem_size + py]->getnum();
    return ret;
}

inline void Mahou::setbox(int px,int py,Box *pbox)  {
    mem_boxes[px * mem_size + py]=pbox;
}


#endif
