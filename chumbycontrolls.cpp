#include "chumbycontrolls.h"
#include <QDebug>

ChumbyControlls::ChumbyControlls(QObject *parent) :
    QObject(parent)
{
}

void ChumbyControlls::setBrightness(int percent)
{
    qDebug() << "Setting brightness to " << percent;
}
