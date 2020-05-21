#ifndef IARRAY_H
#define IARRAY_H

#include <iostream>

template <typename T>
class IArray
{
public:
    virtual void Add(T _item, size_t _index) = 0;
    virtual T Remove(size_t _index) = 0;  // возвращает удаляемый элемент
    virtual size_t Size() const = 0;
    virtual size_t GetCapacity() const = 0;
    virtual T & operator[](size_t) = 0;
    virtual const T & operator[](size_t) const = 0;

    IArray() = default;
    IArray(const IArray &) = delete;
    IArray & operator=(const IArray &) = delete;
    IArray(IArray &&) = delete;
    IArray & operator=(IArray &&) = delete;

    virtual ~IArray() {};
};

template <typename T>
std::ostream & operator<<(std::ostream &s, const IArray<T> &a)
{
    if (a.Size())
    {
        s << "{";
        for (size_t i = 0; i < a.Size(); ++i)
            s << a[i] << ( (i != a.Size()-1) ? "; " : "}" );
    }
    else
        s << "{empty}";
    return s;
}

#endif // IARRAY_H
