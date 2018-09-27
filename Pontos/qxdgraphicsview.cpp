#include "qxdgraphicsview.hpp"

#include <QGraphicsItem>

void QxdGraphicsView::mousePressEvent(QMouseEvent *event)
{
    // OBS Verifica se já existe ponto no local clicado.
    //     Se sim, realiza o comportamento padrão. Se não, cria o ponto.

    // TODO Só realizar este comportamento se estiver em modo de inserção
    QGraphicsScene *currentScene = scene();;
    if(event->button() == Qt::LeftButton && currentScene && itemAt(event->pos()) == nullptr) {
        QPointF scenePos = mapToScene(event->pos());
        QGraphicsItem *newPoint = currentScene->addEllipse(
                    -MainWindowController::pointWidth/2.0,
                    -MainWindowController::pointWidth/2.0,
                    MainWindowController::pointWidth,
                    MainWindowController::pointWidth,
                    MainWindowController::pointNoContour,
                    MainWindowController::pointFill
                    );
        newPoint->setFlag(QGraphicsItem::ItemIgnoresTransformations, true);
        newPoint->setPos(scenePos);

        return;
    }

    QGraphicsView::mousePressEvent(event);
}
