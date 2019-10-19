#pragma once

#include "Path.h"

namespace path::kata::utils
{
std::optional<CPath> CalculateShortestPath(const std::vector<CPath>& paths);

std::optional<CPath> CalculateBestPath(const std::vector<CPath>& paths, const std::vector<Point>& requiredStops);
}