#include <cstdlib>
#include <new>

/**
 * @brief A struct representing a resource that requires explicit construction and destruction.
 */
struct r {
    /**
     * @brief Constructor.
     */
    r();

    /**
     * @brief Destructor.
     */
    ~r();

    /**
     * @brief Example method to use r.
     */
    void use();
};

/**
 * @brief Allocates memory, constructs an object, calls a method, and properly destructs and frees the memory.
 */
void process() {

    void* ptr = std::malloc(sizeof(r));
    r* res = new (ptr) r;
    res->use();
    res->~r();
    std::free(ptr);
}

/**
 * @brief Entry point of the program.
 * 
 * Calls `process()` to demonstrate manual object management.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
