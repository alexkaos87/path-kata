#include <optional>
#include <set>
#include "include/catch.hpp"

#include "PathsUtils.h"

struct SInputData
{
    const path::kata::Point a{ 0, 0 };
    const path::kata::Point b{ 10, 10 };
    const path::kata::Point c{ 20, 0 };
    const path::kata::Point d{ 30, 0 };
    const path::kata::Point e{ 40, 0 };
    const path::kata::Point f{ 40, 20 };

    const path::kata::Segment ac{ a, c };
    const path::kata::Segment bc{ b, c };
    const path::kata::Segment ab{ a, b };
    const path::kata::Segment cd{ c, d };
    const path::kata::Segment de{ d, e };
    // a---c--d--e
    //  \ /
    //   b

    const path::kata::CPath path1{ {ac, cd, de} };
    const path::kata::CPath path2{ {ab, bc, cd, de} };
    
    const std::vector<path::kata::Point> stops{ a, b };
};

constexpr auto g_NumericThreshold{ 0.01 };

TEST_CASE("Test1") // segment ac should have 20 as distance
{
    const SInputData input;

    const auto expected{ 20.0 };
    const auto actual{ input.ac.GetDistance() };
    REQUIRE(std::abs(expected - actual) < g_NumericThreshold);
}

TEST_CASE("Test2") // path1 should have 40 as distance, and a/c/d/e as stops
{
    const SInputData input;

    const auto expected{ 40.0 };
    const auto actual{ input.path1.GetDistance() };
    REQUIRE(std::abs(expected - actual) < g_NumericThreshold);

    REQUIRE(input.path1.GetStops() == std::set<path::kata::Point>{input.a, input.c, input.d, input.e});
}

TEST_CASE("Test3") // path1 should be shortest than path2
{
    const SInputData input;

    const auto expected{ input.path1 };
    const auto actual{ path::kata::utils::CalculateShortestPath({input.path1, input.path2}) };
    REQUIRE(actual.has_value());
    REQUIRE(expected == actual.value());
}

TEST_CASE("Test4") // find the best path between path1 and path2, using stops 
{
    const SInputData input;

    const auto expected{ input.path2 };
    const auto actual{ path::kata::utils::CalculateBestPath({input.path1, input.path2}, input.stops) };
    REQUIRE(actual.has_value());
    REQUIRE(expected == actual.value());
}


