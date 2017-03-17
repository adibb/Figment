#ifndef TEXTFITLABEL_H
#define TEXTFITLABEL_H

#include <QLabel>
#include <QSize>
#include <QFontMetrics> // for bounding

class TextFitLabel : public QLabel
{
public:
    TextFitLabel(QString text,
                 QWidget *parent = Q_NULLPTR);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
};

#endif // TEXTFITLABEL_H
