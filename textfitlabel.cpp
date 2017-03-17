#include "textfitlabel.h"

TextFitLabel::TextFitLabel(QString text,
                           QWidget *parent) :
    QLabel(text, parent)
{}

QSize TextFitLabel::sizeHint() const
{
    QFont f = this->font();
    QFontMetrics m(f);
    return QSize(m.width(this->text()), m.height());
}

QSize TextFitLabel::minimumSizeHint() const
{
    return sizeHint();
}
