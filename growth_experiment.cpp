// ============================================================================
// CS32 P01 Part 2: the growth-factor experiment
//
// Implement measure_growth below. Then run   make experiment && ./experiment
// to see your results as a table.
// ============================================================================

#include "growth_experiment.h"
#include "Vector.h"

// Sets Vector<int>::growth_factor to factor, then push_backs n ints into an
// empty Vector<int>, watching what happens, and returns the GrowthStats (see
// growth_experiment.h for what each field means). Before returning, puts
// growth_factor back to the value it had when measure_growth was called.
//
// Measure by watching a real Vector<int>: push_back the elements one at a time
// and use size() and capacity() to see when the buffer grows and how many
// elements it had to copy. Do not compute the answers from the growth formula
// alone.
GrowthStats measure_growth(double factor, std::size_t n) {
     double oldFactor = Vector<int>::growth_factor;
    Vector<int>::growth_factor = factor;
    Vector<int> v;
    GrowthStats stats{};
    for (std::size_t i = 0; i < n; i++) {
        std::size_t oldSize = v.size();
        std::size_t oldCapacity = v.capacity();

        v.push_back(static_cast<int>(i));

        if (v.capacity() != oldCapacity) {
            stats.reallocations++;
            stats.elements_copied += oldSize;
        }
    }

    Vector<int>::growth_factor = oldFactor;
    return stats;
    
}
