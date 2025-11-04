#include "interval.h"

interval::interval() {
    min = infinity;
    max = -infinity;
}

interval::interval(double minimum, double maximum) {
    min = minimum;
    max = maximum;
}

double interval::size() const {
    return max - min;
}

double interval::contains(double x) const {
    return min <= x && x <= max;
}

bool interval::surrounds(double x) const {
    return min < x && x < max;
}


const interval interval::empty(infinity, -infinity);
const interval interval::universe(-infinity, infinity);
