#ifndef GEOMETRY_CIRCUMCENTER_HPP
#define GEOMETRY_CIRCUMCENTER_HPP

#include <optional>

namespace geometry
{

    struct Point
    {
        long double x{};
        long double y{};
    };

    std::optional<Point>

    circumcenter(const Point &a, const Point &b, const Point &c, long double eps = 1e-15L) noexcept;

}

#endif