#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qDebug()<<"第一次用github，我只是想看看";

    return a.exec();
}
