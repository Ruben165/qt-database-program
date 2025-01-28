#ifndef DELETEITEM_H
#define DELETEITEM_H

#include "ui_deleteitem.h"
#include <QDialog>

class deleteItem : public QDialog, private Ui::deleteItem
{
    Q_OBJECT

public:
    explicit deleteItem(QWidget *parent = nullptr);
    QString getID();
};

#endif // DELETEITEM_H

// 2540124633 - Lie Reubensto
