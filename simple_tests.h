#ifndef SIMPLE_TESTS_H
#define SIMPLE_TESTS_H

#include "iarray.h"
#include <string>

#include <chrono>

using ClockType = std::chrono::steady_clock;
//#include "space_array.h"

void SpaceArrayTest();

void PriorityQueueTest();


using std::cout;
using std::endl;

template <typename T>
void SimpleTest(IArray<T> &_array, const std::string &_testName)
{
    cout << "Test " << _testName << ":" << endl;

    cout << _array << "\tCapacity = " << _array.GetCapacity() << std::endl;

    _array.Add(0, 0); std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;
    _array.Add(1, 1); std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;
    _array.Add(2, 2);
    std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;
    _array.Add(3, 0);
    std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;
    _array.Add(4, _array.Size());
    std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;
    _array.Add(5, 2);
    cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;

    _array[2] = 77;
    cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;

    cout << "Remove: " << _array.Remove(2) << endl;
    std::cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;

    cout << "Remove: " << _array.Remove(0) << endl;
    cout << _array << "\tCapacity = " << _array.GetCapacity() << endl;

    cout << "Remove: " << _array.Remove(_array.Size()-1) << std::endl;
    cout << _array << "\tCapacity = " << _array.GetCapacity() << std::endl;

    _array.Remove(0); std::cout << _array << "\tCapacity = " << _array.GetCapacity() << std::endl;
    _array.Remove(0); std::cout << _array << "\tCapacity = " << _array.GetCapacity() << std::endl;
    _array.Remove(0); std::cout << _array << "\tCapacity = " << _array.GetCapacity() << std::endl;

    cout << endl;
}

template <typename T>
void ArrayTestRandomAdd(IArray<T> &_array, size_t _count, const std::string &_testName)
{
    cout << "Test " << _testName << ":" << endl;// " for ";
//    cout << typeid(_array).name() << ":" << endl;

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    for (size_t i = 0; i < _count; ++i)
    {
        _array.Add(i, rand()%(_array.Size()+1));
    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();

    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    cout << "Added " << _count << " elements. Took " << Time << ", s";
    cout << endl << endl;
}

template <typename T>
void ArrayTestAddAtEnd(IArray<T> &_array, size_t _count, const std::string &_testName)
{
    cout << "Test " << _testName << ":" << endl;// " for ";
//    cout << typeid(_array).name() << ":" << endl;

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    for (size_t i = 0; i < _count; ++i)
    {
        _array.Add(i, _array.Size());
    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();

    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    cout << "Added " << _count << " elements. Took " << Time << ", s";
    cout << endl << endl;
}

template <typename T>
void ArrayTestRandomRemove(IArray<T> &_array, size_t _count, const std::string &_testName)
{
    cout << "Test " << _testName << ":" << endl;// " for ";
//    cout << typeid(_array).name() << ":" << endl;

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    for (size_t i = 0; i < _count; ++i)
    {
        if (_array.Size() == 0)
            cout << "!!!!!!!!" << endl;

        _array.Remove(rand()%_array.Size());
    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();

    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    cout << "Removed " << _count << " elements. Took " << Time << ", s";
    cout << endl << endl;
}

template <typename T>
void ArrayTestRemoveFromEnd(IArray<T> &_array, size_t _count, const std::string &_testName)
{
    cout << "Test " << _testName << ":" << endl;// " for ";
//    cout << typeid(_array).name() << ":" << endl;

    std::chrono::time_point<ClockType> TimeStart = ClockType::now();

    for (size_t i = 0; i < _count; ++i)
    {
        _array.Remove(_array.Size()-1);
    }

    std::chrono::time_point<ClockType> TimeEnd = ClockType::now();

    double Time = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(TimeEnd - TimeStart).count();
    Time /= 1.0e9;

    cout << "Removed " << _count << " elements. Took " << Time << ", s";
    cout << endl << endl;
}



#endif // SIMPLE_TESTS_H
