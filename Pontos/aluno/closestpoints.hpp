#ifndef CLOSESTPOINTS_HPP
#define CLOSESTPOINTS_HPP

#include <QPointF>

#include <utility>
#include <vector>

class ClosestPointsSolver
{
public:
    static std::pair<QPointF, QPointF> solveFor(std::vector<QPointF> points);
};

#endif // CLOSESTPOINTS_HPP
