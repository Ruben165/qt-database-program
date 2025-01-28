#include "mainwindow.h"
#include "insertitem.h"
#include "deleteitem.h"
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    // Please Change the DB path according to your configuration. You don't have to make the DB manually first.
    QString path_db = ".\\Point_of_Sale.db";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path_db);

    if(m_db.open()) {
        qDebug() << "Successfully Connected with the Database!";
        createTable();
    } else {
        qDebug() << "Failed!";
        m_db.lastError();
    }

    displayData();
}

MainWindow::~MainWindow() {
    if(m_db.isOpen()) { m_db.close(); }
}

bool MainWindow::createTable() {
    QSqlQuery query;

    query.prepare("CREATE TABLE IF NOT EXISTS sale ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "name TEXT, "
                  "quantity INTEGER, "
                  "price INTEGER);");

    if(query.exec()) {
        qDebug() << "Table Created Successfully!";
        return true;
    } else {
        qDebug() << "Error Creating Table: " << query.lastError().text();
        return false;
    }
}

void MainWindow::displayData() {
    tableWidgetMain->clear();
    tableWidgetMain->setRowCount(0);

    tableWidgetMain->setColumnCount(4);
    QStringList cols = {"ID", "Name", "Quantity", "Price"};
    tableWidgetMain->setHorizontalHeaderLabels(cols);
    tableWidgetMain->horizontalHeader()->setStretchLastSection(true);
    tableWidgetMain->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery query("SELECT id, name, quantity, price FROM sale");
    int row = 0;

    while(query.next()) {
        tableWidgetMain->insertRow(row);

        QTableWidgetItem *id_item = new QTableWidgetItem(query.value("id").toString());
        QTableWidgetItem *name_item = new QTableWidgetItem(query.value("name").toString());
        QTableWidgetItem *qty_item = new QTableWidgetItem(query.value("quantity").toString());
        QTableWidgetItem *price_item = new QTableWidgetItem(query.value("price").toString());

        id_item->setTextAlignment(Qt::AlignCenter);
        name_item->setTextAlignment(Qt::AlignCenter);
        qty_item->setTextAlignment(Qt::AlignCenter);
        price_item->setTextAlignment(Qt::AlignCenter);

        tableWidgetMain->setItem(row, 0, id_item);
        tableWidgetMain->setItem(row, 1, name_item);
        tableWidgetMain->setItem(row, 2, qty_item);
        tableWidgetMain->setItem(row, 3, price_item);

        row++;
    }
}

void MainWindow::on_actionInsert_triggered() {
    insertItem item;

    item.lineEditName->setFocus(Qt::OtherFocusReason);

    if(item.exec()==QDialog::Accepted){
        QString name= item.lineEditName->text();
        int qty= item.lineEditQty->text().toInt();
        int price= item.lineEditPrice->text().toInt();

        qDebug() << "Name: " << name;
        qDebug() << "Quantity: " << qty;
        qDebug() << "Price: " << price;
        insertData(name, qty, price);
    }

    displayData();
}

void MainWindow::insertData(const QString& name, int qty, int price) {
    QSqlQuery query;

    query.prepare("INSERT INTO sale (name, quantity, price) VALUES (:name, :quantity, :price)");
    query.bindValue(":name", name);
    query.bindValue(":quantity", qty);
    query.bindValue(":price", price);

    if(query.exec()) {
        qDebug() << "Data Inserted Successfully!";
    } else {
        qDebug() << "Insert Failed: " << query.lastError().text();
    }
}

void MainWindow::on_actionDelete_triggered() {
    deleteItem item;

    if(item.exec()==QDialog::Accepted) {
        QString id = item.getID();
        qDebug() << "Deleting Row with ID:" << id;
        deleteData(id.toInt());
    }
}

void MainWindow::deleteData(int id) {
    QSqlQuery query;

    query.prepare("DELETE FROM sale WHERE id = :id");
    query.bindValue(":id", id);

    if(query.exec()) {
        qDebug() << "Row with ID: " << id << "has been deleted successfully!";
    } else {
        qDebug() << "Error Deleting Row:" << query.lastError().text();
    }

    displayData();
}

void MainWindow::on_actionExit_triggered() {
    close();
}

// 2540124633 - Lie Reubensto
