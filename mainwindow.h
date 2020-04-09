#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateGraph(double time_s, double data, unsigned graph_idx, unsigned plot_idx = 0);

private:
    void setLabels(QCustomPlot *plot, QString title, QString axis);
    void setupGraphs();

    Ui::MainWindow *ui_;
};

#endif // MAINWINDOW_H
