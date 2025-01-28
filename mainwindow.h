#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QSqlDatabase>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    QSqlDatabase m_db;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool loadDatabase();
    bool createTable();
    void displayData();
    void insertData(const QString& name, int qty, int price);
    void deleteData(int id);

private slots:
    void on_actionInsert_triggered();
    void on_actionDelete_triggered();
    void on_actionExit_triggered();
};
#endif // MAINWINDOW_H

// 2540124633 - Lie Reubensto
