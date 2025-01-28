#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "Drivers: " << QSqlDatabase::drivers(); // Check Available Drivers
    w.show();
    return a.exec();
}

// 2540124633 - Lie Reubensto
