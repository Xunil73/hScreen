#ifndef MYNMAPVIEW_H
#define MYNMAPVIEW_H

#include <QThread>
#include <QString>
#include <QProcess>
#include <QDebug>

class MyNmapView : public QThread {
    Q_OBJECT
public:
    MyNmapView(QObject *parent);
    void run() override;
signals:
    void nmapReady(const QString&);
};

#endif // MYNMAPVIEW_H
