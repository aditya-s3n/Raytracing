#pragma once

#include "rt_utility.h"

class interval {
    public:
        double max, min;

        interval();
        interval(double minimum, double maximum);

        double size() const;

        double contains(double x) const;

        bool surrounds(double x) const;

        double clamp(double x) const;

        static const interval empty, universe;
};

