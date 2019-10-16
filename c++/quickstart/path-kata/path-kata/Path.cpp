#include "stdafx.h"
#include "Path.h"

namespace path::kata
{
CPath::CPath(const std::vector<Segment>& path) :
    m_list(path)
{
}

std::optional<Point> CPath::From() const
{
    return m_list.empty() ? std::nullopt : std::make_optional(m_list.front().From());
}

std::optional<Point> CPath::To() const
{
    return m_list.empty() ? std::nullopt : std::make_optional(m_list.back().To());
}

double CPath::GetDistance() const
{
    return std::accumulate(m_list.cbegin(), m_list.cend(), 0.0,
        [](const auto& prevValue, const auto& segment) { return prevValue + segment.GetDistance(); });
}

std::set<Point> CPath::GetStops() const
{
    std::set<Point> result;
    std::for_each(m_list.cbegin(), m_list.cend(),
        [&result](const auto& segment)
        {
            result.emplace(segment.From());
            result.emplace(segment.To());
        });

    return result;
}

bool CPath::operator==(const CPath& path) const
{
    return m_list.size() == path.m_list.size() && 
        std::includes(m_list.cbegin(), m_list.cend(), 
            path.m_list.cbegin(), path.m_list.cend());
}
}
