#include "stdafx.h"
#include "Segment.h"

namespace path::kata
{
Segment::Segment(const Point& origin, const Point& dest) :
    m_origin(origin),
    m_dest(dest)
{
}

double Segment::GetDistance() const
{
    const auto deltaX{ m_origin.GetX() - m_dest.GetX() };
    const auto deltaY{ m_origin.GetY() - m_dest.GetY() };
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

const Point& Segment::From() const
{
    return m_origin;
}

const Point& Segment::To() const
{
    return m_dest;
}

bool Segment::operator<(const Segment& segment) const
{
    return m_origin < segment.m_origin && m_dest < segment.m_dest;
}

bool Segment::operator==(const Segment& segment) const
{
    return m_origin == segment.m_origin && m_dest == segment.m_dest;
}
}
