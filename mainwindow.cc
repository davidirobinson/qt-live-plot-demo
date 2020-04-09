#include <mainwindow.h>
#include <./ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    setWindowTitle("Graph Test");
    setupGraphs();
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::setLabels(QCustomPlot *plot, QString title, QString axis)
{
    plot->plotLayout()->removeAt(0);
    plot->plotLayout()->addElement(0, 0, new QCPTextElement(plot, title, QFont("sans", 12, QFont::Bold)));
    plot->yAxis->setLabel(axis);
    plot->xAxis->setLabel("Time (s)");
}

void MainWindow::setupGraphs()
{
    //
    // Graph 1
    //
    ui_->graph_1->addGraph(); // blue line
    ui_->graph_1->graph(0)->setPen(QPen(QColor(40, 110, 255),4));
    ui_->graph_1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui_->graph_1->xAxis->setTicker(timeTicker);
    ui_->graph_1->axisRect()->setupFullAxesBox();

    ui_->graph_1->plotLayout()->insertRow(0);
    setLabels(ui_->graph_1, "Graph 1", "Some Quantity");

    //
    // Graph 2
    //
    ui_->graph_2->addGraph(); // red line
    ui_->graph_2->graph(0)->setPen(QPen(QColor(255, 40, 40),4));
    ui_->graph_2->graph(0)->setBrush(QBrush(QColor(255, 0, 0, 20)));

    timeTicker->setTimeFormat("%h:%m:%s");
    ui_->graph_2->xAxis->setTicker(timeTicker);
    ui_->graph_2->axisRect()->setupFullAxesBox();

    ui_->graph_2->plotLayout()->insertRow(0);
    setLabels(ui_->graph_2, "Graph 2", "Another Quantity");
}

void MainWindow::updateGraph(double time_s, double data, unsigned graph_idx, unsigned plot_idx)
{
    if (graph_idx == 0)
    {
        ui_->graph_1->graph(plot_idx)->addData(time_s, data);
        ui_->graph_1->graph(0)->rescaleValueAxis();
        ui_->graph_1->xAxis->setRange(time_s, 8, Qt::AlignRight);
        ui_->graph_1->replot();
    }
    else if (graph_idx == 1)
    {
        ui_->graph_2->graph(plot_idx)->addData(time_s, data);
        ui_->graph_2->graph(0)->rescaleValueAxis();
        ui_->graph_2->xAxis->setRange(time_s, 8, Qt::AlignRight);
        ui_->graph_2->replot();
    }
}
