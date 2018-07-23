#ifndef PEOPLEVSPEOPLE_H
#define PEOPLEVSPEOPLE_H
#include"board.h"

class PeopleVsPeople :public Board
{
public:
    PeopleVsPeople();
    virtual void mouseReleaseEvent(QMouseEvent *ev); // 鼠标点击象棋并释放鼠标时候触发
    void click(QPoint pt);

};

#endif // PEOPLEVSPEOPLE_H
