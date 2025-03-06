/**
 * @file example.cpp
 * @brief Example file demonstrating custom new and delete operators.
 *
 * This file contains an example of how to implement custom new and delete operators
 * for a class, fulfilling the DCL54-CPP rule by ensuring that all memory allocation
 * and deallocation operations are properly handled.
 */

#include <iostream> 
#include <new> 

/**
 * @brief Updates bookkeeping information for memory allocation and deallocation.
 *
 * This function is called whenever memory is allocated or deallocated to update
 * the bookkeeping information variable seen in here.
 *
 * @param allocated_ptr Pointer to the allocated or deallocated memory.
 * @param size Size of the allocated or deallocated memory.
 * @param alloc True if memory is being allocated, false if it is being deallocated.
 */

extern "C++" void update_bookkeeping(void *allocated_ptr, std::size_t size, bool alloc);

struct S {
/**
 *@struct S
 *@brief A new structure with custom new and delete operators. 
 *This unique structure demonstrates how to implement custom new and deletion operators
 *to better update bookkeeping information
 */
    void *operator new(std::size_t size) noexcept(false){
        void *ptr = ::operator new(size);
        update_bookkeeping(ptr, size, true);
        return ptr; 
    }
/**
 *@brief Custom-built delete operator.
 *Correctly deallocates memory for any object of type S and updates bookkeeping information.
 *@param ptr (Pointer) to the memory to be deallocated.
 *@param size (Size) of the memory to be deallocated.
 */
    void operator delete(void *ptr, std::size_t size) noexcept{
        ::operator delete(ptr);
        update_bookkeeping(ptr, size, false);
    }
}; 

/**
 *@brief Updates the bookkeeping information.
 *Correctly deallocates memory for any object of type S and updates bookkeeping information.
 *@param allocated_ptr (Allocated pointer) to the allocated or deallocated memory.
 *@param size (Size) of the allocated or deallocated memory.
 *@param alloc (True) if the memory is being allocated, (False) if being deallocated.
 */
void update_bookkeeping(void *allocated_ptr, std::size_t size, bool alloc){
    std::cout<< "update_bookkeeping called with ptr: " << allocated_ptr << " , size: " << size << " , alloc: " << alloc << std::endl;  
}

int main(){
    S* obj = new S();
    delete obj;
    return 0; 
}

