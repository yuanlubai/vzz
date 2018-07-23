#ifndef GAMETYPE_H
#define GAMETYPE_H

#include <QWidget>

namespace Ui {
class GameType;
}

class GameType : public QWidget
{
    Q_OBJECT

public:
    explicit GameType(QWidget *parent = 0);
    ~GameType();

private slots:
    void on_pushButton_pvsp_clicked();

    void on_pushButton_pvsc_clicked();

private:
    Ui::GameType *ui;
};

#endif // GAMETYPE_H
