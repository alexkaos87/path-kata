#include "include/catch.hpp"

#include "Point.h"
#include "Segment.h"

TEST_CASE("IsTrue")
{
    REQUIRE(true);
}

constexpr auto g_NumericThreshold{ 0.01 };

TEST_CASE("SegmentDistanceZeroTest")
{
    const path::kata::Point a{ 0, 10 };
    const path::kata::Segment segment{ a, a };

    const auto expected{ 0.0 };
    const auto actual{ segment.GetDistance() };
    REQUIRE(std::abs(expected - actual) < g_NumericThreshold);
}

TEST_CASE("SegmentDistanceNotZeroTest")
{
    const path::kata::Point a{ 0, 10 }, b{ 0, 20 };
    const path::kata::Segment segment{ a, b };

    const auto expected{ 10.0 };
    const auto actual{ segment.GetDistance() };
    REQUIRE(std::abs(expected - actual) < g_NumericThreshold);
}

// Find the shortest path: Find the shortest path in a list of paths

// Filter paths: Filter paths keeping only those which include a given list of stops

// Find the best path: Find the shortest path in a list of paths, which includes a given list of stops