#include "numbersort.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumberSort w;
    w.show();
    return a.exec();
}
