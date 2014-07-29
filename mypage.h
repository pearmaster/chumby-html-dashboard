#ifndef MYPAGE_H
#define MYPAGE_H

#include <QObject>
#include <QWebPage>

class MyPage : public QWebPage
{
    Q_OBJECT
public:
    explicit MyPage(QObject *parent = 0);
    
protected:
    void javaScriptConsoleMessage( const QString & message, int lineNumber, const QString & sourceID );

signals:
    
public slots:
    void cleanup(void);
    
};

#endif // MYPAGE_H
