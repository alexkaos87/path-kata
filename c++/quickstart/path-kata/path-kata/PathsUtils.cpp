#include "stdafx.h"
#include "PathsUtils.h"

namespace path::kata::utils
{
std::optional<CPath> CalculateShortestPath(const std::vector<CPath>& paths)
{
    if (paths.empty())
        return std::nullopt;

    return *std::min_element(paths.cbegin(), paths.cend(),
        [](const auto& path1, const auto& path2) { return path1.GetDistance() < path2.GetDistance(); });
}

static std::vector<CPath> FilteringPaths(const std::vector<CPath>& paths, const std::vector<Point>& requiredStops)
{
    std::vector<CPath> result;
    std::copy_if(paths.cbegin(), paths.cend(), std::back_inserter(result),
        [&requiredStops](const auto& path)
        {
            const auto stops{ path.GetStops() };
            return std::includes(stops.cbegin(), stops.cend(), requiredStops.cbegin(), requiredStops.cend());
        });

    return result;
}

std::optional<CPath> CalculateBestPath(const std::vector<CPath>& paths, const std::vector<Point>& requiredStops)
{
    return CalculateShortestPath(FilteringPaths(paths, requiredStops));
}
}