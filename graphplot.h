#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include <QWidget>
#include "MixedSimple2DGraph.h"
#include "generatedatathread.h"

namespace Ui {
class GraphPlot;
}

class GraphPlot : public QWidget
{
    Q_OBJECT

public:
    explicit GraphPlot(QWidget *parent = 0);
    ~GraphPlot();
signals:
    void stopSignal();

private:
    Ui::GraphPlot *ui;
    MixedSimple2DGraph::Data data;
    MixedSimple2DGraph graph;
    QThread * thread;
    GenerateDataThread *obj;

private slots:
    void start();
    void pause();
    void stop();
    void buildGraph(MixedSimple2DGraph::Data *_data);
};

#endif // GRAPHPLOT_H
