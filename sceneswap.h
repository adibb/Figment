/*
 * Push button masquerading as a link. Shifts
 * the scene on activation.
 */

#ifndef SCENESWAP_H
#define SCENESWAP_H

#include "scenewindow.h"
#include "swapitem.h"

class SceneSwap : public SwapItem
{
    Q_OBJECT

public:
    SceneSwap(QString text,
              QString filename,
              SceneWindow *window,
              QWidget *parent = Q_NULLPTR);

private slots:
    void swap();

private:
    const QString filename;
    SceneWindow *window;
};

#endif // SCENESWAP_H
