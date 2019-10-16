#include "stdafx.h"
#include "Point.h"

namespace path::kata
{
Point::Point(const int x, const int y) :
    m_x(x),
    m_y(y)
{}

int Point::GetX() const
{
    return m_x;
}

int Point::GetY() const
{
    return m_y;
}

bool Point::operator<(const Point& point) const
{
    return m_x < point.m_x && m_y < point.m_y;
}

bool Point::operator==(const Point& point) const
{
    return m_x == point.m_x && m_y == point.m_y;
}
}
