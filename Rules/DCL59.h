/**
 * @file DCL59.h
 * @brief Header file for the delta namespace.
 *
 * This file contains the declaration of the external variable alpha within the delta namespace,
 * fulfilling the DCL59-CPP rule by ensuring that all declarations are properly guarded.
 */

#ifndef DCL59_HEADER
#define DCL59_HEADER

namespace delta{
    extern int alpha; /**< External variable alpha declared in the delta namespace. */
}
#endif 
