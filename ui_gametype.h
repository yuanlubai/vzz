/********************************************************************************
** Form generated from reading UI file 'gametype.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETYPE_H
#define UI_GAMETYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameType
{
public:
    QPushButton *pushButton_pvsp;
    QPushButton *pushButton_pvsc;

    void setupUi(QWidget *GameType)
    {
        if (GameType->objectName().isEmpty())
            GameType->setObjectName(QStringLiteral("GameType"));
        GameType->resize(405, 283);
        GameType->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        pushButton_pvsp = new QPushButton(GameType);
        pushButton_pvsp->setObjectName(QStringLiteral("pushButton_pvsp"));
        pushButton_pvsp->setGeometry(QRect(40, 50, 311, 91));
        pushButton_pvsp->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 0);\n"
"font: 16pt \"Agency FB\";"));
        pushButton_pvsc = new QPushButton(GameType);
        pushButton_pvsc->setObjectName(QStringLiteral("pushButton_pvsc"));
        pushButton_pvsc->setGeometry(QRect(40, 170, 311, 81));
        pushButton_pvsc->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 0);\n"
"font: 18pt \"Agency FB\";"));

        retranslateUi(GameType);

        QMetaObject::connectSlotsByName(GameType);
    } // setupUi

    void retranslateUi(QWidget *GameType)
    {
        GameType->setWindowTitle(QApplication::translate("GameType", "Form", Q_NULLPTR));
        pushButton_pvsp->setText(QApplication::translate("GameType", "\344\272\272\344\272\272\345\257\271\346\210\230", Q_NULLPTR));
        pushButton_pvsc->setText(QApplication::translate("GameType", "\344\272\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameType: public Ui_GameType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETYPE_H
