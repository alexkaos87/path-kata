#pragma once

namespace path::kata
{
class Point
{
public:
    Point(int x, int y);

    [[nodiscard]] int GetX() const;

    [[nodiscard]] int GetY() const;

    [[nodiscard]] bool operator<(const Point& point) const;

    [[nodiscard]] bool operator==(const Point& point) const;

private:
    const int m_x{ 0 };
    const int m_y{ 0 };
};

}