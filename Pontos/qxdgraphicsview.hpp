#ifndef QXDGRAPHICSVIEW_HPP
#define QXDGRAPHICSVIEW_HPP

#include "mainwindowcontroller.hpp"

#include <QMouseEvent>
#include <QGraphicsView>

class QxdGraphicsView final : public QGraphicsView
{
public:
    using QGraphicsView::QGraphicsView;

private:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // QXDGRAPHICSVIEW_HPP
