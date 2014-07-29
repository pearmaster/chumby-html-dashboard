#ifndef CHUMBYCONTROLLS_H
#define CHUMBYCONTROLLS_H

#include <QObject>

class ChumbyControlls : public QObject
{
    Q_OBJECT
public:
    explicit ChumbyControlls(QObject *parent = 0);
    void setBrightness(int percent);

signals:

public slots:

};

#endif // CHUMBYCONTROLLS_H
