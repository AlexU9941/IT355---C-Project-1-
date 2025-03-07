#include <cstdlib>

/**
 * @brief A simple structure containing a single integer.
 */
struct r {
    int x;
};

/**
 * @brief Allocates memory for an r struct and initializes it.
 * 
 * @param x The integer value to store in the struct.
 * @return r* Pointer to the allocated struct, or nullptr if allocation fails.
 */
struct r* make_r(int x) {
    struct r* ptr = (struct r*)malloc(sizeof(*ptr));
    if (ptr == NULL) {
        return NULL;
    }
    ptr->x = x; 
    return ptr;
}

/**
 * @brief main.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    struct r* ptr = make_r(9);
    free(ptr);
    return 0;
}
