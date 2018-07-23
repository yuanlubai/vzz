#include <QApplication>
#include"gametype.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    GameType g;
    g.show();
    return app.exec();
}

