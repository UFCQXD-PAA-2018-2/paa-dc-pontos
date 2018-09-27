#include "mainwindowcontroller.hpp"
#include "ui_mainwindow.h"

#include <QShortcut>
#include <QGraphicsItem>

const QPen   MainWindowController::pointNoContour{Qt::NoPen};
const QPen   MainWindowController::pointContour{Qt::black, 2};
const QBrush MainWindowController::pointFill{Qt::red};
const qreal  MainWindowController::pointWidth{10};

MainWindowController::MainWindowController(MainWindow &mainWindow, QObject *parent)
    : QObject{parent}
    , mainWindow{mainWindow}
{
    mainWindow.ui->graphicsView->setScene(&scene);

//    scene.addEllipse(-15/2.0, -15/2.0, 15, 15, Qt::NoPen, Qt::red)->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);

//    mainWindow.ui->graphicsView->scale(3,3);

//    auto item = scene.itemAt(0,0,mainWindow.ui->graphicsView->transform());
//    if(item) item->setOpacity(0.5);

}
