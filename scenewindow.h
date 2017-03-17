#ifndef SCENEWINDOW_H
#define SCENEWINDOW_H

#include <QWidget>
#include <QBoxLayout>
#include <QFile>
#include <QTextStream>

class SceneWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWindow(QString scenename, QWidget *parent = 0);
    void openScene(QString scenename);
    void clear(QLayout *layout);

private:
    // Forward declare the nested parser class
    class Parser;
    Parser *p;
};

#endif // SCENEWINDOW_H
