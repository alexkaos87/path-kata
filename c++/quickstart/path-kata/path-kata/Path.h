#pragma once

#include "Segment.h"

namespace path::kata
{
class CPath
{
public:
    explicit CPath(const std::vector<Segment>& path);

    [[nodiscard]] std::optional<Point> From() const;
    [[nodiscard]] std::optional<Point> To() const;

    [[nodiscard]] double GetDistance() const;

    [[nodiscard]] std::set<Point> GetStops() const;

    [[nodiscard]] bool operator==(const CPath& path) const;

private:
    const std::vector<Segment> m_list;
};
}