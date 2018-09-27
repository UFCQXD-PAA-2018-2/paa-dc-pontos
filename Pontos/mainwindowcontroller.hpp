#ifndef MAINWINDOWCONTROLLER_HPP
#define MAINWINDOWCONTROLLER_HPP

#include "mainwindow.hpp"

#include <QGraphicsScene>
#include <QObject>
#include <QBrush>
#include <QPen>

#include <vector>

class MainWindowController final : public QObject
{
    Q_OBJECT
public:
    explicit MainWindowController(MainWindow &mainWindow, QObject *parent = nullptr);

    std::vector<QPointF> getAllPoints() const;

    void highlightPoint(QPointF const &point);

    static const QPen   pointNoContour;
    static const QPen   pointContour;
    static const QBrush pointNoFill;
    static const QBrush pointFill;
    static const qreal  pointWidth;

private:
    MainWindow &mainWindow;

    QGraphicsScene scene;

signals:

public slots:
};

#endif // MAINWINDOWCONTROLLER_HPP
