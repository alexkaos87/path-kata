#pragma once

#include "Point.h"

namespace path::kata
{
class Segment 
{
public:
    Segment(const Point& origin, const Point& dest);

    [[nodiscard]] double GetDistance() const;

    [[nodiscard]] const Point& From() const;

    [[nodiscard]] const Point& To() const;

    [[nodiscard]] bool operator<(const Segment& segment) const;

    [[nodiscard]] bool operator==(const Segment& segment) const;

private:
    const Point m_origin;
    const Point m_dest;
};
}