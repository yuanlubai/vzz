#include "board.h"
#include<QPainter>//绘制棋盘需要
#include<QMouseEvent>
#include<QDebug>
#include<QMessageBox>

Board::Board()
{
    clearChess();
    chessRadius=20;//设置棋子大小
    setMinimumSize(chessRadius*15*2+1,chessRadius*15*2+1);//窗口大小
    startSetting(1);//白先下棋子


}

void Board::startSetting(int _firstSide)
{
    firstSide=_firstSide;//设置先下一方
    side=_firstSide;//设置当前一方
    update();//qt的东西，自动绘制棋盘
}

void Board::placeTheChess(int row, int col)
{
    if(row<1||row>15||col<1||col>15)
        return;
    if(chess[row][col]!=0)
        return;
    chess[row][col]=side;

}

void Board::clearChess()
{
    for(int i=1;i<=15;i++)//棋盘清空
        for(int j=1;j<=15;j++)
            chess[i][j]=0;
}

bool Board::isWin(int row, int col)
{
    int dx[8]={0,1,1,1,0,-1,-1,-1};
    int dy[8]={1,1,0,-1,-1,-1,0,1};

    int currentSide=chess[row][col];

    int cnt,r,c,i;
    for(i=0;i<8;i++){
        int dir=i;
        cnt=0;
        r=row;
        c=col;
        while(chess[r][c]==currentSide){
            cnt++;
            r+=dy[dir];
            c+=dx[dir];
        }

        if(cnt>4){

            return true;
        }


    }
    return false;
}

void Board::paintEvent(QPaintEvent *)
{
    DrawBackground();//背景
    int r = height() / (15*2);//半径
    chessRadius=r;
    point=QPoint(chessRadius+1,chessRadius+1);
    QPainter p(this);
    p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    drawPlate(p);
    drawChess(p);

}

void Board::DrawBackground()
{
    QPalette p = this->palette();
    p.setColor(QPalette::Window, QColor(0, 255, 255));
    this->setPalette(p);
}

void Board::drawPlate(QPainter &p)
{
    // 绘制横线15条
    for (int i = 1; i <= 15; ++i) {
        if (i == 1 || i == 15) {
            p.setPen(QPen(Qt::darkBlue, 3, Qt::SolidLine));
        }
        else {
            p.setPen(QPen(Qt::darkBlue, 1, Qt::SolidLine));
        }
        p.drawLine(center(i, 1), center(i, 15));
    }

    // 绘制竖线15条
    for (int i = 1; i <=15; ++i) {
        p.setPen(QPen(Qt::darkBlue, 3, Qt::SolidLine));
        p.drawLine(center(1, i), center(15, i));
    }
}

void Board::drawChess(QPainter &p)
{
    QColor color;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(chess[i][j]==1){//白棋
                color=Qt::white;
                p.setBrush(Qt::white);
                p.setPen(QPen(QBrush(color), 2));
                p.drawEllipse(cell(i,j));
            }
            else if(chess[i][j]==2){//黑棋
                color=Qt::black;
                p.setBrush(Qt::black);
                p.setPen(QPen(QBrush(color), 2));
                p.drawEllipse(cell(i,j));
            }
        }

    }
}

QPoint Board::center(int row, int col)
{
    QPoint pt(chessRadius * (col-1) * 2, chessRadius * (row-1) * 2);
    return pt + point;
}

QPoint Board::topLeft(int row, int col)
{
    return center(row, col) - QPoint(chessRadius, chessRadius);
}

QRect Board::cell(int row, int col)
{
    return QRect(topLeft(row, col), QSize(chessRadius * 2 - 1, chessRadius * 2 - 1));
}

bool Board::QpointToRowCol(QPoint pt, int &row, int &col)
{
    row = pt.y() / (2 * chessRadius)+1 ;
    col = pt.x() / (2 * chessRadius)+1 ;

    QPoint c = center(row, col);
    int dx = c.x() - pt.x();
    int dy = c.y() - pt.y();
    int dist = dx * dx + dy * dy; // 离鼠标矩形左上顶点的距离
    if (dist < chessRadius * chessRadius) {
        return true;
    }

    row += 1;
    c = center(row, col);
    dx = c.x() - pt.x();
    dy = c.y() - pt.y();
    dist = dx * dx + dy * dy; // 离鼠标矩形左下顶点的距离
    if (dist < chessRadius * chessRadius) {
        return true;
    }

    row -= 1;
    col += 1;
    c = center(row, col);
    dx = c.x() - pt.x();
    dy = c.y() - pt.y();
    dist = dx * dx + dy * dy; // 离鼠标矩形右上顶点的距离
    if (dist < chessRadius * chessRadius) {
        return true;
    }

    row += 1;
    c = center(row, col);
    dx = c.x() - pt.x();
    dy = c.y() - pt.y();
    dist = dx * dx + dy * dy; // 离鼠标矩形右下顶点的距离
    if (dist < chessRadius * chessRadius) {
        return true;
    }

    return false;
}

