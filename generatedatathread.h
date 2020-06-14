#ifndef GENERATEDATATHREAD_H
#define GENERATEDATATHREAD_H
#include <QThread>
#include "MixedSimple2DGraph.h"
#include <QTimer>

class GenerateDataThread : public QObject
{
    Q_OBJECT

public:
    GenerateDataThread();
    void pause();
    void wake();

signals:
    void createDataSignal(MixedSimple2DGraph::Data *data);

private slots:
    void createData();

private:
    MixedSimple2DGraph::Data *data;
    QTimer timer;
    static const quint32 msec = 100;
    quint32 y;
    quint32 x;
};

#endif // GENERATEDATATHREAD_H
