#ifndef DIALOGUEVEHICULE_H
#define DIALOGUEVEHICULE_H

#include <QtGui/QDialog>
#include "ui_DialogueVehicule.h"

class DialogueVehicule : public QDialog
{
    Q_OBJECT

public:
    DialogueVehicule(QWidget *parent = 0);
    ~DialogueVehicule();

private:
    Ui::DialogueVehiculeClass ui;
};

#endif // DIALOGUEVEHICULE_H
