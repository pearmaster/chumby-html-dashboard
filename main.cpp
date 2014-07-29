#include <QApplication>
#include "html5applicationviewer.h"
#include "chumbycontrolls.h"
#include <QDebug>
#include <mydebug.h>
#include <mypage.h>
#include <QGraphicsWebView>
#include <QScopedPointer>
#include <QWebFrame>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Html5ApplicationViewer viewer;
    viewer.setOrientation(Html5ApplicationViewer::ScreenOrientationAuto);
    viewer.showFullScreen();
    viewer.webView()->setPage(new MyPage);
    QWebSettings *settings = viewer.webView()->page()->settings();
    settings->enablePersistentStorage("/mnt/usb/webcache");
    settings->setMaximumPagesInCache(1);
    settings->setObjectCacheCapacities(0, 0, 0);
    QWebFrame *frame = viewer.webView()->page()->mainFrame();
    QScopedPointer<ChumbyControlls> chum(new ChumbyControlls());
    frame->addToJavaScriptWindowObject("chumby", chum.data());
    viewer.loadUrl(QUrl(app.arguments().at(1)));
    qDebug() << "Running application";
    MyDebug *mdb = new MyDebug(viewer.webView());
    mdb->test();
    return app.exec();
}
