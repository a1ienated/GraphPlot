#include "generatedatathread.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <QTime>

GenerateDataThread::GenerateDataThread()
{
    data = new MixedSimple2DGraph::Data;
    data->name = "Graph";

    connect(&timer, &QTimer::timeout, this, &GenerateDataThread::createData);
    wake();
}

void GenerateDataThread::pause()
{
    timer.stop();
}

void GenerateDataThread::wake()
{
    if(!timer.isActive())
        timer.start(msec);
}

void GenerateDataThread::createData()
{
    qDebug() << QString::number(QTime::currentTime().second()) <<  "GenerateDataThread: " << (int)QThread::currentThreadId();
    srand(time(0));

    y += rand() % 50 + 1;
    x += rand() % 50 + 1;
    data->y.append(y);
    data->x.append(x);

    emit createDataSignal(data);
}

