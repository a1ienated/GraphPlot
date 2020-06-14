#ifndef MIXEDSIMPLE2DGRAPH_H
#define MIXEDSIMPLE2DGRAPH_H

#include "qcustomplot.h"

/*!
 * \brief The MixedSimple2DGraph class
 * \author Щетинин Николай
 * \date 10.2018
 *
 * Класс представляет собой модернизированную (упрощенную) версию QCustomPlot. Он позволяет быстро построить несколько 2D графиков на одном.
 * Все настройки QCustomPlot для данного функционала уже включены в методы класса - осталось только передать данные.
 */

class QCP_LIB_DECL MixedSimple2DGraph : public QCustomPlot
{
    Q_OBJECT
public:
    struct Data ///<Данные для графика
    {
        QVector<double> x; ///< Данные для оси X
        QVector<double> y; ///< Данные для оси Y
        QString name;      ///< Название графика в общей легенде
    };

    ///В конструктор можно передать название формы графика и названия осей абсцисс и ординат
    MixedSimple2DGraph(QString x_axis_name = "", QString y_axis_name = "");

    ///Построить графики по данным
    void build(MixedSimple2DGraph::Data data);
    void build(QVector<MixedSimple2DGraph::Data> data);

private:
    ///Настройка внешнего вида графика
    void configure_plot_view(QString x_axis_name, QString y_axis_name);

    ///Добавление данных
    void add_graph_data_to_plot(MixedSimple2DGraph::Data graph_data, int graphNum);
    void add_graph_mixed_data_to_plot(QVector<MixedSimple2DGraph::Data> mixed_graph_data);

    ///Получение уникального цвета для графика
    Qt::GlobalColor get_unique_graph_color(quint16 graph_num);
};

#endif // MIXEDSIMPLE2DGRAPH_H
