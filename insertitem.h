#ifndef INSERTITEM_H
#define INSERTITEM_H

#include "ui_insertitem.h"

class insertItem : public QDialog, public Ui::insertItem
{
    Q_OBJECT

public:
    explicit insertItem(QWidget *parent = nullptr);

private slots:
    void on_buttonBox_accepted();
};

#endif // INSERTITEM_H

// 2540124633 - Lie Reubensto
