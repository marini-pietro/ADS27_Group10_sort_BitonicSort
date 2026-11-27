#include "metrics.hpp" // Include the metrics header file for tracking sorting metrics
#include <cstddef> // Include the cstddef header to access size_t data type

// Begin the bitonic_sort namespace to encapsulate the sorting logic and avoid name collisions
namespace bitonic_sort {

class SortBuffer {

// public interface for the SortBuffer class
public:
    // Constructor to allocate a buffer of the specified size
    explicit SortBuffer(std::size_t size)
        : data_(new int[size]), size_(size) {}

    // Destructor to deallocate the buffer
    ~SortBuffer() {
        delete[] data_;
    }

    // Delete the copy constructor and assignment operator to prevent shallow copies
    // Without dedicated deep copy logic C++ would copy only the pointer, so both objects would try to delete the same memory when destroyed, leading to undefined behavior.
    SortBuffer(const SortBuffer&) = delete;
    SortBuffer& operator=(const SortBuffer&) = delete;

    // TODO: Understand if logic for deep copies is necessary or we can skip it

    // Getter method to get the beginning of the buffer
    // noexcept specifier indicates that this function is not supposed to throw exceptions
    // if it does std::terminate is called immediately
    int* begin() noexcept {
        return data_;
    }

    // Getter method to get the end of the buffer
    // noexcept specifier indicates that this function is not supposed to throw exceptions
    // if it does std::terminate is called immediately
    int* end() noexcept {
        return data_ + size_;
    }

// private members of the SortBuffer class
private:
    int* data_; // Pointer to the dynamically allocated buffer
    std::size_t size_; // Size of the primitive data type in the buffer
};

void sort(SortBuffer&, heritage::SortMetrics&) {
    // TODO: Implement the bitonic sorting algorithm.
}

} // End of namespace bitonic_sort

int main() {
    return 0;
}
