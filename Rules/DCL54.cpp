#include <iostream> 
#include <new> 

extern "C++" void update_bookkeeping(void *allocated_ptr, std::size_t size, bool alloc);

struct S {
    void *operator new(std::size_t size) noexcept(false){
        void *ptr = ::operator new(size);
        update_bookkeeping(ptr, size, true);
        return ptr; 
    }

    void operator delete(void *ptr, std::size_t size) noexcept{
        ::operator delete(ptr);
        update_bookkeeping(ptr, size, false);
    }
}; 

void update_bookkeeping(void *allocated_ptr, std::size_t size, bool alloc){
    std::cout<< "update_bookkeeping called with ptr: " << allocated_ptr << " , size: " << size << " , alloc: " << alloc << std::endl;  
}

int main(){
    S* obj = new S();
    delete obj;
    return 0; 
}