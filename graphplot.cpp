#include "graphplot.h"
#include "ui_graphplot.h"
#include <QDebug>
#include <QThread>

GraphPlot::GraphPlot(QWidget *parent) : QWidget(parent), ui(new Ui::GraphPlot),
    graph("x", "y")
{
    ui->setupUi(this);
    thread = nullptr;
    obj = nullptr;

    graph.build(data);
    ui->verticalLayout->addWidget(&graph);

    connect(ui->pushButton_start, &QPushButton::clicked, this, &GraphPlot::start);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &GraphPlot::stop);
    connect(ui->pushButton_pause, &QPushButton::clicked, this, &GraphPlot::pause);

    qDebug() <<  "GraphPlot: " << (int)QThread::currentThreadId();
}

GraphPlot::~GraphPlot()
{
    delete ui;
}

void GraphPlot::start()
{
    if(thread == nullptr)
    {
        thread = new QThread;
        obj = new GenerateDataThread();
        obj->moveToThread(thread);

        connect(obj, &GenerateDataThread::createDataSignal, this, &GraphPlot::buildGraph);
        connect(this, &GraphPlot::stopSignal, thread, &QThread::quit);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
    }
    else if(thread->isRunning())
        obj->wake();
}

void GraphPlot::pause()
{
    if(thread != nullptr)
        obj->pause();
}

void GraphPlot::stop()
{
    emit stopSignal();
    buildGraph(&data);
    thread = nullptr;
    delete obj;
}

void GraphPlot::buildGraph(MixedSimple2DGraph::Data *_data)
{
    graph.build(*_data);
}
