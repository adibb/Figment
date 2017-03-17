#include "mainwindow.h"
#include "scenewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Start up the scene showing window
    SceneWindow *stage = new SceneWindow("start.txt", &w);

    w.setCentralWidget(stage);

    // TODO: Ensure the scene appears in the center of the window.

    return a.exec();
}
