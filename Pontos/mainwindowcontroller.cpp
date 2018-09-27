#include "mainwindowcontroller.hpp"
#include "ui_mainwindow.h"

#include <QShortcut>
#include <QGraphicsEllipseItem>

const QPen   MainWindowController::pointNoContour{Qt::NoPen};
const QPen   MainWindowController::pointContour{Qt::black, 3};
const QBrush MainWindowController::pointNoFill{Qt::NoBrush};
const QBrush MainWindowController::pointFill{Qt::red};
const qreal  MainWindowController::pointWidth{10};

MainWindowController::MainWindowController(MainWindow &mainWindow, QObject *parent)
    : QObject{parent}
    , mainWindow{mainWindow}
{
    auto ui = mainWindow.ui;

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);

}

std::vector<QPointF> MainWindowController::getAllPoints() const
{
    const auto allItems = scene.items();
    std::vector<QPointF> allPoints;

    allPoints.reserve(static_cast<size_t>(allItems.size()));

    for(QGraphicsItem *item : allItems) {
        allPoints.push_back(item->pos());
    }

    return allPoints;
}

void MainWindowController::highlightPoint(const QPointF &point)
{
    QGraphicsEllipseItem *item = qgraphicsitem_cast<QGraphicsEllipseItem*>(
                scene.itemAt(point, mainWindow.ui->graphicsView->transform())
                );

    if(item) {
        item->setPen(MainWindowController::pointContour);
        item->setBrush(MainWindowController::pointNoFill);
    }
}
