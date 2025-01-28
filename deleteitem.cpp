#include "deleteitem.h"

deleteItem::deleteItem(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
}

QString deleteItem::getID() {
    return lineEditDeleteID->text();
}

// 2540124633 - Lie Reubensto
