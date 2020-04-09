#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>

#include <mainwindow.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    static bool done_ = false;


    QApplication a(argc, argv);
    MainWindow w;

    w.setStyleSheet("QMainWindow {background: 'white';}");
    w.show();

    std::thread data_thread([&w]() {
        using namespace std::chrono;

        // This is a shitty hack.
        // Need to determine if handling data outside the main Qt class is appropriate.
        std::this_thread::sleep_for(milliseconds(100));

        auto start = steady_clock::now();

        while (!done_)
        {
            auto end = steady_clock::now();
            auto time_s = static_cast<double>(duration_cast<milliseconds>(end - start).count()) / 1000.;

            w.updateGraph(time_s, std::sin(time_s), 0);
            w.updateGraph(time_s, std::sin(time_s * 2), 1);

            std::this_thread::sleep_for(milliseconds(10));
        }
    });

    // Qt only lets us call this blocking GUI function from the main thread
    a.exec();
    done_ = true;
    data_thread.join();

    return 0;
}
