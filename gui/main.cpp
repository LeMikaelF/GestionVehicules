#include "Gui.h"

#include <QtGui>
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QTextCodec* codec=QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
    QApplication a(argc, argv);
    Gui w;
    w.show();
    return a.exec();
}
