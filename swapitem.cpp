#include "swapitem.h"

SwapItem::SwapItem(QString text,
                   QWidget *parent) :
    QPushButton(text, parent)
{
    // Set the style
    this->setStyleSheet("* { border: 0px; "
                        "padding: 0px; "
                        "color: #00cc00; }"
                        "*:hover { text-decoration: underline; }");
    this->setFlat(true);

    // Connect swap() to the button press
    connect(this, SIGNAL (released()), this, SLOT(swap()));
}

// Overload the sizeHint function so the button's borders
// match its inner text.
QSize SwapItem::sizeHint() const
{
    QFont f = this->font();
    QFontMetrics m(f);
    return QSize(m.width(this->text()), m.height());
}

QSize SwapItem::minimumSizeHint() const
{
    return sizeHint();
}
