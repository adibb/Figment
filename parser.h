/*
 * Parses the passed lines based on the internal
 * functions. Essentially a state machine. Nested
 * within the SceneWindow class, as it should never
 * have reason to be instantiated outside it and
 * takes care of circular dependency issues.
 *
 * TODO: Figure out a better way to handle feature
 * parsing. This will explode if too many are added.
 */

#ifndef PARSER_H
#define PARSER_H

#include <QLayout>
#include <QString>
#include "scenewindow.h"
#include "textfitlabel.h"
#include "textswap.h"
#include "sceneswap.h"

class SceneWindow::Parser
{
    // Enum type specific to the parser -
    // simple state machine
    enum State{
        TEXT, SWAP, TSWAP, SSWAP
    };

public:
    Parser(SceneWindow *stage);
    void parseLine(QString input,
                   QLayout *target);

private:
    enum State s;
    SceneWindow *stage;
};

#endif // PARSER_H
