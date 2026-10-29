GrowthStats measure_growth(double factor, std::size_t n) {
    double oldFactor = Vector<int>::growth_factor;
    Vector<int>::growth_factor = factor;

    Vector<int> v;
    GrowthStats stats;

    for (std::size_t i = 0; i < n; i++) {
        std::size_t oldSize = v.size();
        std::size_t oldCapacity = v.capacity();

        v.push_back(static_cast<int>(i));

        if (v.capacity() != oldCapacity) {
            stats.reallocations++;
            stats.elements_copied += oldSize;
        }
    }

    stats.final_capacity = v.capacity();

    Vector<int>::growth_factor = oldFactor;

    return stats;
}
