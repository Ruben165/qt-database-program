#include "insertitem.h"
#include <QDebug>

insertItem::insertItem(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

void insertItem::on_buttonBox_accepted() {
    accept();
}

// 2540124633 - Lie Reubensto
