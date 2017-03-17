#include "parser.h"

SceneWindow::Parser::Parser(SceneWindow *stage) :
    stage(stage)
{}

void SceneWindow::Parser::parseLine(QString input, QLayout *target)
{
    // Ensure the parser always starts looking for text
    s = TEXT;

    // Declare the iterator
    QString::iterator iter;

    // String for recall
    QString aggregate;

    // Other maintenance variables
    QStringList items;
    QString scenename = "";

    // Switch-case state machine
    // TODO: Find a better way to handle this. This will *explode*
    // in complexity as features are added.
    for(iter = input.begin(); iter != input.end(); iter++)
    {
        switch(s)
        {
        case TEXT:
            if(*iter == '{'){
                s = SWAP;
                TextFitLabel *temp = new TextFitLabel(aggregate);
                target->addWidget(temp);
                aggregate = "";
            } else {
                aggregate.append(*iter);
            }
            break;

        case SWAP:
            if(*iter == '|'){
                s = TSWAP;
                items << aggregate;
                aggregate = "";
            } else if (*iter == '@'){
                s = SSWAP;
            } else {
                aggregate.append(*iter);
            }
            break;

        case TSWAP:
            if(*iter == '|'){
                items << aggregate;
                aggregate = "";
            } else if (*iter == '}'){
                items << aggregate;
                TextSwap *temp = new TextSwap(items);
                target->addWidget(temp);
                aggregate = "";
            } else {
                aggregate.append(*iter);
            }
            break;

        case SSWAP:
            if(*iter == '}'){
                scenename = scenename + ".txt";
                SceneSwap *temp = new SceneSwap(aggregate,
                                                scenename,
                                                stage);
                target->addWidget(temp);
                aggregate = "";
                scenename = "";
            } else {
                scenename.append(*iter);
            }
            break;
        }
    }

    // Toss any leftovers in to make sure we don't lose
    // a last line.

    if(!aggregate.isEmpty()){
        TextFitLabel *temp = new TextFitLabel(aggregate);
        target->addWidget(temp);
    }
}
