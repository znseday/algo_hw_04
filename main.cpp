#include <iostream>

//#include "itask.h"
//#include "tester.h"

#include "iarray.h"
#include "dynamic_arrays.h"
#include "simple_tests.h"

using namespace std;
//namespace fs = std::experimental::filesystem;

int main()
{
    SingleArray<int> sa, sa2, sa3;
    SimpleTest<int>(sa, "SingleArray");

    VectorArray<int, 2> va;
    SimpleTest<int>(va, "VectorArray");

    FactorArray<int, 2> fa, fa2, fa3;
    SimpleTest<int>(fa, "FactorArray");

    MatrixArray<int, 2> ma;
    SimpleTest<int>(ma, "MatrixArray");

    STL_VectorWrapper<int> stl_a, stl_a2, stl_a3;
    SimpleTest<int>(stl_a, "STL_VectorWrapper");

    PriorityQueueTest();

    size_t count = 200000;

    ArrayTestRandomAdd(sa2, count, "Random insert for SingleArray");
    ArrayTestAddAtEnd(sa3,  count, "Insert at end for SingleArray");


    VectorArray<int, 100> va2, va3;
    ArrayTestRandomAdd(va2, count, "Random insert for VectorArray (V = 100)");
    ArrayTestAddAtEnd(va3,  count, "Insert at end for VectorArray (V = 100)");

    ArrayTestRandomAdd(fa2, count, "Random insert for FactorArray (F = 2)");
    ArrayTestAddAtEnd(fa3,  count, "Insert at end for FactorArray (F = 2)");

    MatrixArray<int, 100> ma2, ma3;
    ArrayTestRandomAdd(ma2, count, "Random insert for MatrixArray (N = 100)");
    ArrayTestAddAtEnd(ma3,  count, "Insert at end for MatrixArray (N = 100)");

    ArrayTestRandomAdd(stl_a2, count, "Random insert for STL_VectorWrapper");
    ArrayTestAddAtEnd(stl_a3,  count, "Insert at end for STL_VectorWrapper");


    ArrayTestRandomRemove(sa2, count, "Random remove for SingleArray");
    ArrayTestRemoveFromEnd(sa3, count, "Remove from end for SingleArray");

    ArrayTestRandomRemove(va2, count, "Random remove for VectorArray (V = 100)");
    ArrayTestRemoveFromEnd(va3, count, "Remove from end for VectorArray (V = 100)");

    ArrayTestRandomRemove(fa2, count, "Random remove for FactorArray (F = 2)");
    ArrayTestRemoveFromEnd(fa3, count, "Remove from end for FactorArray (F = 2)");

    ArrayTestRandomRemove(ma2, count, "Random remove for MatrixArray (N = 100)");
    ArrayTestRemoveFromEnd(ma3, count, "Remove from end for MatrixArray (N = 100)");

    ArrayTestRandomRemove(stl_a2, count, "Random remove for STL_VectorWrapper");
    ArrayTestRemoveFromEnd(stl_a3, count, "Remove from end for STL_VectorWrapper");

    return 0;
}
