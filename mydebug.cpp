#include "mydebug.h"
#include <QDebug>
#include <QGraphicsWebView>

MyDebug::MyDebug(QObject *parent) :
    QObject(parent)
{

}

MyDebug::MyDebug(QGraphicsWebView *parent) :
    QObject(parent)
{
    connect(parent, SIGNAL(loadStarted()), SLOT(webpagestartload()));
    connect(parent, SIGNAL(loadFinished(bool)), SLOT(webpageloaded(bool)));
    connect(parent, SIGNAL(loadProgress(int)), SLOT(webpageprogress(int)));
}


void MyDebug::webpagestartload() {
    qDebug() << "Starting to load web page";
}

void MyDebug::webpageloaded(bool ok) {
    qDebug() << "Web page loaded" << ok;
}

void MyDebug::webpageprogress(int x) {
    qDebug() << "Web page loading: " << x;
}

void MyDebug::test() {
    qDebug() << "Hi";
}
