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
    const std::string reqNiv() const;
    const std::string reqImmatriculation() const;
    int reqPoids() const;
    int reqNbEssieux() const;
private:
    Ui::DialogueCamionClass ui;
private slots:
	void validerCamion();
};

#endif // DIALOGUECAMION_H
