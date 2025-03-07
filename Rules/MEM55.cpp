#include <new>
#include <cstdlib>
#include <iostream>

/**
 * @brief Custom memory allocation function.
 * 
 * @param size Size of memory to allocate.
 * @return void* Pointer to allocated memory.
 */
void* alloc_mem(std::size_t size) {
    return std::malloc(size);
}

/**
 * @brief Overloaded global new operator using custom memory allocator.
 * 
 * @param size Size of memory to allocate.
 * @return void* Pointer to allocated memory.
 * @throws std::bad_alloc If allocation fails.
 */
void* operator new(std::size_t size) {
    if (void* ret = alloc_mem(size)) {
        return ret;
    }
    throw std::bad_alloc();
}

/**
 * @brief A simple structure with an int data.
 */
struct MyStruct {
    int data;
};

/**
 * @brief Allocates memory, constructs and destructs the obj.
 */
void process() {
   
    void* ptr = ::operator new(sizeof(MyStruct));
    MyStruct* obj = new(ptr) MyStruct; 
    obj->~MyStruct();
    std::free(ptr);
}

/**
 * @brief main.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
