/*
 * Swaps text in and out in place. Eye candy, but
 * surprisingly effective for the purposes of
 * storytelling.
 */

#ifndef TEXTSWAP_H
#define TEXTSWAP_H

#include "swapitem.h"

class TextSwap : public SwapItem
{
    Q_OBJECT

public:
    TextSwap(QStringList items,
             QWidget *parent = Q_NULLPTR);

private slots:
    void swap();

private:
    const QStringList items;
    int i;
};

#endif // TEXTSWAP_H
