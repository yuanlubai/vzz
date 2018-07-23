#include "gametype.h"
#include "ui_gametype.h"
#include"peoplevspeople.h"
#include"peoplevscomputer.h"
GameType::GameType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameType)
{
    ui->setupUi(this);
}

GameType::~GameType()
{
    delete ui;
}

void GameType::on_pushButton_pvsp_clicked()
{
    PeopleVsPeople * pvsp= new PeopleVsPeople();
   // this->hide();
    pvsp->show();
   // this->show();
}

void GameType::on_pushButton_pvsc_clicked()
{
    PeopleVsComputer* pvsc= new PeopleVsComputer();
   // this->hide();
    pvsc->show();
  //  this->show();
}
