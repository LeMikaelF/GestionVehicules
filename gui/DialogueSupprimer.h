#ifndef DIALOGUESUPPRIMER_H
#define DIALOGUESUPPRIMER_H

#include <QtGui/QDialog>
#include "ui_DialogueSupprimer.h"

class DialogueSupprimer : public QDialog
{
    Q_OBJECT

public:
    DialogueSupprimer(QWidget *parent = 0);
    ~DialogueSupprimer();

private:
    Ui::DialogueSupprimerClass ui;
};

#endif // DIALOGUESUPPRIMER_H
