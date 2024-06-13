#ifndef NmapThread_H
#define NmapThread_H

#include <QThread>
#include <QString>
#include <QProcess>
#include <QDebug>

class NmapThread : public QThread {
    Q_OBJECT
public:
    NmapThread(QObject *parent);
    void run() override;
signals:
    void nmapReady(const QString&);
};

#endif // NmapThread_H
