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

    std::string reqNiv() const;
    std::string reqImmatriculation() const;
    int reqNbSieges() const;


private:
    Ui::DialogueVehiculeClass ui;

private slots:
	void validerVehicule();
};

#endif // DIALOGUEVEHICULE_H
