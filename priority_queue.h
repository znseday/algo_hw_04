#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include <array>
#include <algorithm>

template <typename T>
struct Node
{
    T Data;
    Node<T> *next = nullptr;
    Node() = default;
    Node(const T &_data) : Data(_data), next(nullptr) {}
};

template <typename T>
class List
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
public:

    List() = default;

    void PushBack(const T &_data)
    {
        Node<T> *temp;
        Node<T> *newNode = new Node<T>(_data);

        if (!head)
            head = tail = newNode;
        else
        {
            temp = tail;
            tail = newNode;
            temp->next = tail;
        }
    }

    T PopFront()
    {
        if (!head)
            return T();

        Node<T> *temp;
        T res = head->Data;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        return res;
    }

    bool IsEmpty() const {return head == nullptr;}

};


template <typename T, size_t P>
class PriorityQueue
{
private:

    std::array<List<T>, P> q;

public:
    PriorityQueue() = default;

    void Enqueue(int priority, T item) // поместить элемент в очередь
    {
#ifdef SHOW_TRACE_ENQUEUE
    std::cout << "Add " << item << " with " << priority << " priority" << endl;
#endif
//        q[P - priority].Add(item);   // приоритеты в обратном порядке, начиная с 1
        q[priority-1].PushBack(item);  // самый высокий 1
    }

    T Dequeue()                        // выбрать элемент из очереди
    {
        for (auto &l : q)
            if (!l.IsEmpty())
                return l.PopFront();

        return T();
    }

    bool IsEmpty() const
    {
        // "По-крестьянски"
//        for (const auto &l : q)
//            if (!l.IsEmpty())
//                return false;
//        return true;

        // "Профессионально" :)
        return !std::any_of(q.cbegin(), q.cend(), [](const auto &l) {return !l.IsEmpty();});
    }
};



#endif // PRIORITY_QUEUE_H
