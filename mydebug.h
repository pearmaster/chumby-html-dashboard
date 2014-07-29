#ifndef MYDEBUG_H
#define MYDEBUG_H

#include <QObject>

class QGraphicsWebView;

class MyDebug : public QObject
{
    Q_OBJECT
public:
    explicit MyDebug(QObject *parent = 0);
    explicit MyDebug(QGraphicsWebView *wv);
    void test(void);
signals:
    
public slots:
    void webpagestartload(void);

    void webpageloaded(bool ok);

    void webpageprogress(int x);
};

#endif // MYDEBUG_H
