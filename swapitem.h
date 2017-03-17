/*
 * Abstract class for swap-items.
 *
 * TODO: Add getters and setters for the style;
 * one of the most likely things an author would
 * want to tweak.
 */

#ifndef SWAPITEM_H
#define SWAPITEM_H

#include <QPushButton>
#include <QSizePolicy>
#include <QFontMetrics> // for bounding

class SwapItem : public QPushButton
{
    Q_OBJECT

public:
    SwapItem(QString text,
             QWidget *parent = Q_NULLPTR);
    QSize sizeHint() const;
    QSize minimumSizeHint() const;

private slots:
    virtual void swap() = 0;
};

#endif // SWAPITEM_H
