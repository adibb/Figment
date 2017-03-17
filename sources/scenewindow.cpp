/*
 * SceneWindow implementation file. Note that including
 * both the header files lets us divvy the implementation
 * up into seperate cpp files.
 */
#include "scenewindow.h"
#include "parser.h"

SceneWindow::SceneWindow(QString scenename,
                         QWidget *parent) :
    QWidget(parent),
    p(new Parser(this))
{
    this->setSizePolicy(QSizePolicy::MinimumExpanding,
                        QSizePolicy::Fixed);
    openScene(scenename);
}

void SceneWindow::openScene(QString scenename)
{
    // Get the file
    QFile *scene = new QFile("scenes/" + scenename);

    // Hide to work on opening the new scene
    this->hide();

    // Clear out the old scene
    QLayout *old = this->layout();
    if (old)
    {
        clear(old);
        delete old;
    }

    // Prepare the y axis to add lines to
    QBoxLayout *y_axis = new QBoxLayout(QBoxLayout::TopToBottom);
    y_axis->setSizeConstraint(QLayout::SetFixedSize);

    if(scene->open(QFile::ReadOnly | QFile::Text)){
        // File opened as a text file and read-only
        QTextStream in(scene);

        // Read lines into the y-axis
        while(!in.atEnd()){
            QBoxLayout *row = new QBoxLayout(QBoxLayout::LeftToRight);

            // Prevent the row from justifying all its elements
            row->setMargin(0);
            row->setSpacing(0);
            row->setAlignment(Qt::AlignLeft);

            QString line = in.readLine();
            p->parseLine(line, row);

            y_axis->addLayout(row);
        }

        this->setLayout(y_axis);

    } else {
        // Couldn't open the file - usually a bad filename
        QLabel *feedback = new QLabel("COULD NOT FIND " + scene->fileName());
        y_axis->addWidget(feedback);
    }

    this->adjustSize();
    this->show();
}

// Modified from StackOverflow
void SceneWindow::clear(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)))
    {
        if (item->layout())
        {
            clear(item->layout());
        }

        else if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}
