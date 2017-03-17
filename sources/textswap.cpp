#include "textswap.h"

// Constructors

TextSwap::TextSwap(QStringList items,
                   QWidget *parent) :
    SwapItem(items[0], parent),
    items(items),
    i(0)
{}

// Swaps to the next piece of text
void TextSwap::swap()
{
    i++;
    if (i < items.size()){
        // Simply change text to next item
        this->setText(items[i]);
        this->clearFocus();
    }

    if (i == items.size() - 1) {
        // Last item - change style script to match background
        this->setStyleSheet("border: 0px; "
                            "padding: 0px; "
                            "margin: 0px; ");
    }
    this->updateGeometry();
}
