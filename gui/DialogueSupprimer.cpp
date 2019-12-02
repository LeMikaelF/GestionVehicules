#include "DialogueSupprimer.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace std;

DialogueSupprimer::DialogueSupprimer(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

DialogueSupprimer::~DialogueSupprimer()
{

}

const string DialogueSupprimer::reqNiv() const {
	return ui.lineEditNiv->text().toStdString();
}

void DialogueSupprimer::validerNiv() {
	if(util::validerNiv(ui.lineEditNiv->text().toStdString())) {
		QString msg("Le niv est invalide.");
		QMessageBox(this, "Erreur", msg);
		reject();
	} else {
		accept();
	}
}
