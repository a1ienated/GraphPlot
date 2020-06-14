#include "MixedSimple2DGraph.h"

MixedSimple2DGraph::MixedSimple2DGraph(QString x_axis_name, QString y_axis_name)
{
    configure_plot_view(x_axis_name, y_axis_name);
}

void MixedSimple2DGraph::build(MixedSimple2DGraph::Data data)
{
    clearGraphs();
    add_graph_data_to_plot(data, 0);
    graph(0)->setLineStyle(QCPGraph::lsNone);
    graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    replot();
}

void MixedSimple2DGraph::build(QVector<MixedSimple2DGraph::Data> data)
{
    clearGraphs();
    add_graph_mixed_data_to_plot(data);
    replot();
}

void MixedSimple2DGraph::configure_plot_view(QString x_axis_name, QString y_axis_name)
{
    legend->setVisible(true);
    legend->setFont(QFont("Helvetica",9));

    xAxis->setLabel(x_axis_name);
    yAxis2->setLabel(y_axis_name);

    xAxis2->setLabelFont(QFont("Helvetica",9));
    yAxis2->setLabelFont(QFont("Helvetica",9));

    // configure right and top axis to show ticks but no labels:
    xAxis2->setVisible(true);
    xAxis2->setTickLabels(false);
    yAxis2->setVisible(true);
    yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(xAxis, SIGNAL(rangeChanged(QCPRange)), xAxis2, SLOT(setRange(QCPRange)));
    connect(yAxis, SIGNAL(rangeChanged(QCPRange)), yAxis2, SLOT(setRange(QCPRange)));

    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MixedSimple2DGraph::add_graph_data_to_plot(MixedSimple2DGraph::Data graph_data, int graphNum)
{
    //добавление нового графика и настройка его внешнего вида
    addGraph();

    Qt::GlobalColor clr = get_unique_graph_color(graphNum);
    graph(graphNum)->setPen(QPen(clr));
    graph(graphNum)->setName(graph_data.name);
    graph(graphNum)->setData(graph_data.x, graph_data.y);// pass data points to graphs:
    graph(graphNum)->rescaleAxes();// let the ranges scale themselves
}

void MixedSimple2DGraph::add_graph_mixed_data_to_plot(QVector<MixedSimple2DGraph::Data> mixed_graph_data)
{
    //добавление данных на график
    for (int graphNum = 0; graphNum < mixed_graph_data.count(); graphNum++) {
        Data current_data = mixed_graph_data.at(graphNum);
        add_graph_data_to_plot(current_data, graphNum);
    }
}

Qt::GlobalColor MixedSimple2DGraph::get_unique_graph_color(quint16 graph_num)
{
    //рассчитано максимум на 10 графиков (больше будет неуместно)
    switch (graph_num) {
    case 0:
        return Qt::blue;
        break;
    case 1:
        return Qt::red;
        break;
    case 2:
        return Qt::green;
        break;
    case 3:
        return Qt::black;
        break;
    case 4:
        return Qt::gray;
        break;
    case 5:
        return Qt::magenta;
        break;
    case 6:
        return Qt::darkRed;
        break;
    case 7:
        return Qt::darkGreen;
        break;
    case 8:
        return Qt::darkBlue;
        break;
    case 9:
        return Qt::yellow;
        break;
    default:
        return Qt::darkGray;
        break;
    }
}
