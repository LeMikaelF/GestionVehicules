#ifndef DIALOGUECAMION_H
#define DIALOGUECAMION_H

#include <QtGui/QDialog>
#include "ui_DialogueCamion.h"

class DialogueCamion : public QDialog
{
    Q_OBJECT

public:
    DialogueCamion(QWidget *parent = 0);
    ~DialogueCamion();

private:
    Ui::DialogueCamionClass ui;
};

#endif // DIALOGUECAMION_H
