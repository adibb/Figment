#include "sceneswap.h"

SceneSwap::SceneSwap(QString text,
                     QString filename,
                     SceneWindow *window,
                     QWidget *parent) :
    SwapItem(text, parent),
    filename(filename),
    window(window)
{}

void SceneSwap::swap()
{
    window->openScene(filename);
}
