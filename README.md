Some files need to be run a specific way to work.

ERR-59:

    g++ -fPIC -shared -o libERR59-2.so ERR59-2.cpp
    
    g++ -o ERR59-1 ERR59-1.cpp -L. -lERR59-2
    
    LD_LIBRARY_PATH=. ./ERR59-1
