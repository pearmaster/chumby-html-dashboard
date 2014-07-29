#include "mypage.h"
#include <QDebug>
#include <QTimer>

class QWebPage;

MyPage::MyPage(QObject *parent) :
    QWebPage(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(cleanup()));
    timer->start(1000*60*10);
}

void MyPage::javaScriptConsoleMessage( const QString & message, int lineNumber, const QString & sourceID )
{
    //do something!
    qDebug() << message << " " << sourceID << ":" << lineNumber;
}

void MyPage::cleanup(void)
{
    this->settings()->clearMemoryCaches();
}
