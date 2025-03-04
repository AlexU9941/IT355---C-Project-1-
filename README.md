Some files need to be run a specific way to work.

ERR-59:
    g++ -fPIC -shared -o libERR-59-2.so ERR-59-2.cpp
    
    g++ -o ERR-59-1 ERR-59-1.cpp -L. -lERR-59-2
    
    LD_LIBRARY_PATH=. ./ERR-59-1
