#ifndef MYDYNAMICARRAY_H
#define MYDYNAMICARRAY_H

#include "iarray.h"

// 1 задание. Динамические массивы.
// Написать метод добавления и удаления элементов:
// void add(T item, int index);
// T remove(int index); // возвращает удаляемый элемент
// по индексу во все варианты динамических массивов:
// SingleArray, VectorArray, FactorArray, MatrixArray *.

#include <stdexcept>
#include <array>
#include <vector>

template <typename T>
class SingleArray : public IArray<T>
{
private:
    T *Data = nullptr;
    size_t Count = 0;
public:

    SingleArray() = default;

    virtual void Add(T _item, size_t _index) override
    {
        if (_index > Count)
            throw std::invalid_argument("_index > Count");

        T *newData = new T[Count + 1];
        for (size_t i = 0; i < _index; ++i)
            newData[i] = std::move(Data[i]);

        newData[_index] = std::move(_item);

        for (size_t i = _index; i < Count; ++i)
            newData[i+1] = std::move(Data[i]);

        if (Data)
            delete[]Data;

        Data = newData;
        ++Count;
    }

    virtual T Remove(size_t _index) override  // возвращает удаляемый элемент
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        T res = Data[_index];

        if (Count == 1)
        {
            if (Data) delete[]Data;
            Data = nullptr;
        }
        else
        {
            T *newData = new T[Count - 1];
            for (size_t i = 0; i < _index; ++i)
                newData[i] = std::move(Data[i]);

            for (size_t i = _index; i < Count-1; ++i)
                newData[i] = std::move(Data[i+1]);

            if (Data) delete[]Data;

            Data = newData;
        }
        --Count;

        return res;
    }

    virtual size_t Size() const override { return Count; }
    virtual size_t GetCapacity() const override { return Count; }

    virtual const T & operator[](size_t _index) const override
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        return Data[_index];
    }

    virtual T & operator[](size_t _index) override
    {
        return const_cast<T&>(const_cast<const SingleArray&>(*this)[_index]);
    }

    ~SingleArray()
    {
        if (Data)
            delete[]Data;
    }
};
//-----------------------------------------------------------


template <typename T, size_t V = 10>
class VectorArray : public IArray<T>
{
private:
    T *Data = nullptr;
    size_t Count = 0;
    size_t Capacity = 0;
public:

    VectorArray() = default;

    virtual void Add(T _item, size_t _index) override
    {
        if (_index > Count)
            throw std::invalid_argument("_index > Count");

        if (Count == Capacity)
        {
            T *newData = new T[Count + V];

            for (size_t i = 0; i < _index; ++i)
                newData[i] = std::move(Data[i]);

            newData[_index] = std::move(_item);

            for (size_t i = _index; i < Count; ++i)
                newData[i+1] = std::move(Data[i]);

            if (Data)
                delete[]Data;

            Data = newData;

            Capacity += V;
        }
        else
        {
            for (size_t i = Count; i > _index; --i)
                Data[i] = std::move(Data[i-1]);

            Data[_index] = std::move(_item);
        }

        ++Count;
    }

    virtual T Remove(size_t _index) override  // возвращает удаляемый элемент
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        T res = Data[_index];

        if (Count == 1)
        {
            if (Data) delete[]Data;
            Data = nullptr;
            Capacity = 0;
        }
        else
        {
            if (Count == Capacity - V + 1)
            {
                T *newData = new T[Count - 1];

                for (size_t i = 0; i < _index; ++i)
                    newData[i] = std::move(Data[i]);

                for (size_t i = _index; i < Count-1; ++i)
                    newData[i] = std::move(Data[i+1]);

                if (Data) delete[]Data;

                Data = newData;

                Capacity -= V;
            }
            else
            {
                for (size_t i = _index; i < Count; ++i)
                        Data[i] = std::move(Data[i+1]);
            }
        }
        --Count;

        return res;
    }

    virtual size_t Size() const override { return Count; }

    size_t GetCapacity() const { return Capacity; }

    virtual const T & operator[](size_t _index) const override
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        return Data[_index];
    }

    virtual T & operator[](size_t _index) override
    {
        return const_cast<T&>(const_cast<const VectorArray&>(*this)[_index]);
//        return const_cast<T&>(const_cast<const decltype(*this) &>(*this)[_index]);
    }

    ~VectorArray()
    {
        if (Data)
            delete[]Data;
    }
};
//-----------------------------------------------------------

template <typename T, size_t F = 2>
class FactorArray : public IArray<T>
{
private:
    T *Data = nullptr;
    size_t Count = 0;
    size_t Capacity = 0;
public:

    FactorArray() = default;

    virtual void Add(T _item, size_t _index) override
    {
        if (_index > Count)
            throw std::invalid_argument("_index > Count");

        if (Count == Capacity)
        {
            T *newData = new T[ (Count) ? Count*F : 1];

            for (size_t i = 0; i < _index; ++i)
                newData[i] = std::move(Data[i]);

            newData[_index] = std::move(_item);

            for (size_t i = _index; i < Count; ++i)
                newData[i+1] = std::move(Data[i]);

            if (Data)
                delete[]Data;

            Data = newData;

            Capacity = Capacity ? Capacity*F : 1;
        }
        else
        {
            for (size_t i = Count; i > _index; --i)
                Data[i] = std::move(Data[i-1]);

            Data[_index] = std::move(_item);
        }

        ++Count;
    }

    virtual T Remove(size_t _index) override  // возвращает удаляемый элемент
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        T res = Data[_index];

        if (Count == 1)
        {
            if (Data) delete[]Data;
            Data = nullptr;
            Capacity = 0;
        }
        else
        {
            if (Count == Capacity/F + 1)
            {
                T *newData = new T[Count - 1];

                for (size_t i = 0; i < _index; ++i)
                    newData[i] = std::move(Data[i]);

                for (size_t i = _index; i < Count-1; ++i)
                    newData[i] = std::move(Data[i+1]);

                if (Data)
                    delete[]Data;

                Data = newData;

                Capacity /= F;
            }
            else
            {
                for (size_t i = _index; i < Count; ++i)
                        Data[i] = std::move(Data[i+1]);
            }
        }
        --Count;

        return res;
    }

    virtual size_t Size() const override { return Count; }
    size_t GetCapacity() const { return Capacity; }

    virtual const T & operator[](size_t _index) const override
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        return Data[_index];
    }

    virtual T & operator[](size_t _index) override
    {
        return const_cast<T&>(const_cast<const FactorArray&>(*this)[_index]);
    }

    ~FactorArray()
    {
        if (Data)
            delete[]Data;
    }
};
//-----------------------------------------------------------


//template <typename T, IArray<T> I, size_t N>
template <typename T, size_t N>
class MatrixArray : public IArray<T>
{
private:

    FactorArray<std::array<T, N>> Data;
//    I<std::array<T, N>> Data;
    size_t Count = 0;

public:

    MatrixArray() = default;

    virtual void Add(T _item, size_t _index) override
    {
        if (_index > Count)
            throw std::invalid_argument("_index > Count");

        if (Count == Data.Size()*N)
        {
            std::array<T, N> newLine;
            Data.Add(newLine, Data.Size());
        }

        for (size_t i = Count; i > _index; --i)
            Data[i/N][i%N] = std::move(Data[(i-1)/N][(i-1)%N]);

        Data[_index/N][_index%N] = std::move(_item);

        ++Count;
    }

    virtual T Remove(size_t _index) override  // возвращает удаляемый элемент
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        T res = Data[_index/N][_index%N];

        for (size_t i = _index; i < Count-1; ++i)
            Data[i/N][i%N] = std::move(Data[(i+1)/N][(i+1)%N]);

        --Count;

        if ( Count == (Data.Size() - 1)*N )
        {
            Data.Remove(Data.Size() - 1);
        }

        return res;
    }

    virtual size_t Size() const override { return Count; }
    size_t GetCapacity() const override { return Data.Size()*N; }

    virtual const T & operator[](size_t _index) const override
    {
        if (_index >= Count)
            throw std::invalid_argument("_index >= Count");

        return Data[_index/N][_index%N];
    }

    virtual T & operator[](size_t _index) override
    {
        return const_cast<T&>(const_cast<const MatrixArray&>(*this)[_index]);
    }

    ~MatrixArray()
    {
        // nothing
    }
};
//-----------------------------------------------------------


template <typename T>
class STL_VectorWrapper : public IArray<T>
{
private:

    std::vector<T> Data; // Аналог нашего FactorArray

public:

    STL_VectorWrapper() = default;

    virtual void Add(T _item, size_t _index) override
    {
        if (_index > Data.size())
            throw std::invalid_argument("_index > Count");

        if (_index == Data.size())
            Data.emplace_back(_item);
        else
            Data.emplace(Data.cbegin() + _index, _item);
    }

    virtual T Remove(size_t _index) override  // возвращает удаляемый элемент
    {
        if (_index >= Data.size())
            throw std::invalid_argument("_index >= Count");

        T res = Data[_index];

        if (_index == Data.size()-1)
            Data.pop_back();
        else
            Data.erase(Data.begin()+_index);

        // можно сэмитировать уменьшение Capacity при помощи shrink_to_fit()

        return res;
    }

    virtual size_t Size() const override { return Data.size(); }
    size_t GetCapacity() const override { return Data.capacity(); }

    virtual const T & operator[](size_t _index) const override
    {
        if (_index >= Data.size())
            throw std::invalid_argument("_index >= Count");

        return Data[_index];
    }

    virtual T & operator[](size_t _index) override
    {
        return const_cast<T&>(const_cast<const STL_VectorWrapper&>(*this)[_index]);
    }

    ~STL_VectorWrapper()
    {
        // nothing
    }
};


#endif // MYDYNAMICARRAY_H
