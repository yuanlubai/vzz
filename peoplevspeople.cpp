#include "peoplevspeople.h"
#include<QMouseEvent>
#include<QMessageBox>

PeopleVsPeople::PeopleVsPeople()
{

}

void PeopleVsPeople::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton) {
        return;
    }
    click(ev->pos());
}

void PeopleVsPeople::click(QPoint pt)
{
    // 看有没有点中象棋
    // 将pt转化成象棋的行列值
    // 判断这个行列值上面有没有棋子
    int row, col;
    if(QpointToRowCol(pt,row,col)&&chess[row][col]==0){
        placeTheChess(row,col);
        if(isWin(row,col))
        {
            //placethechess会更改当前的一方
            if(side==2)
            {
                QMessageBox message(QMessageBox::NoIcon, "比赛结束", "黑方胜");
                message.exec();
            }
            else if(side==1)
            {
                QMessageBox message(QMessageBox::NoIcon, "比赛结束", "白方胜");
                message.exec();
            }
            clearChess();
            return;
        }
        side=(side==1)?2:1;
        update();
    }
}


