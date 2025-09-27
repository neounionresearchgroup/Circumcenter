#include "include/circumcenter.hpp"
#include <cmath>

namespace geometry
{

    static inline long double squared_norm(const Point &p) noexcept
    {
        return p.x * p.x + p.y * p.y;
    }

    std::optional<Point> circumcenter(const Point &a, const Point &b, const Point &c, long double eps) noexcept
    {
        const long double d1 = squared_norm(a);

        const long double d2 = squared_norm(b);
        
        const long double d3 = squared_norm(c);

        const long double denom = 2.0L * ((b.x - c.x) * (a.y - b.y) - (a.x - b.x) * (b.y - c.y));

        if (std::abs(denom) < eps)
        {
            return std::nullopt;
        }

        const long double num_x = -(d1 * (b.y - c.y) + d2 * (c.y - a.y) + d3 * (a.y - b.y));

        const long double num_y = (d1 * (b.x - c.x) + d2 * (c.x - a.x) + d3 * (a.x - b.x));

        return Point{num_x / denom, num_y / denom};
    }

}