#include <cstdlib>
#include <new>
#include <iostream>

/**
 * @brief A struct with an over-aligned requirement.
 * 
 * The alignment is set to twice the alignment of std::max_align_t.
 */
struct alignas(alignof(std::max_align_t) * 2) OverAlignedType {
    int data; 
};

/**
 * @brief Custom allocation function for over-aligned types.
 * 
 * @param size The size of memory to allocate.
 * @return void* Pointer to allocated memory.
 * @throws std::bad_alloc if allocation fails.
 */
void* operator new(std::size_t size) {
    void* ptr = std::malloc(size); 
    if (!ptr) throw std::bad_alloc();
    return ptr;
}

/**
 * @brief Custom deallocation function for over-aligned types.
 * 
 * @param ptr Pointer to allocated memory.
 */
void operator delete(void* ptr) noexcept {
    std::free(ptr);
}

/**
 * @brief Demonstrates allocation and deallocation of an over-aligned type.
 * 
 */
void process() {
    OverAlignedType* obj = new OverAlignedType; 
    delete obj; 
}

/**
 * @brief Entry point of the program.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
