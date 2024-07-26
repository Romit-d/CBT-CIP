#include "fclaculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FClaculator w;
    w.show();
    return a.exec();
}
