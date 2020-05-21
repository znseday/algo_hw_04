#include "simple_tests.h"
//#include "space_array.h"

#define SHOW_TRACE_ENQUEUE

#include "priority_queue.h"

using namespace std;


template <typename T, size_t P>
static void DequeueAllWithPrint(PriorityQueue<T, P> &_pq)
{
    cout << "Full Dequeue: ";
    while (!_pq.IsEmpty())
        cout << _pq.Dequeue() << "  ";
    cout << endl << endl;
}


void PriorityQueueTest()
{
    cout << "Test PriorityQueue:" << endl;

    PriorityQueue<char, 3> pq;
    pq.Enqueue(3, 'A');
    pq.Enqueue(3, 'B');
    pq.Enqueue(2, 'C');
    pq.Enqueue(2, 'D');
    pq.Enqueue(1, 'E');
    pq.Enqueue(3, 'F');
    DequeueAllWithPrint(pq);

    pq.Enqueue(1, 'A');
    pq.Enqueue(3, 'B');
    DequeueAllWithPrint(pq);

    pq.Enqueue(1, 'B');
    pq.Enqueue(3, 'A');
    DequeueAllWithPrint(pq);

    pq.Enqueue(2, 'A');
    DequeueAllWithPrint(pq);

    pq.Enqueue(2, 'A');
    pq.Enqueue(2, 'B');
    pq.Enqueue(2, 'C');
    //DequeueAllWithPrint(pq);

    cout << "Deque: " << pq.Dequeue() << endl; // A
    pq.Enqueue(1, 'D');
    pq.Enqueue(1, 'E');
    cout << "Deque: " << pq.Dequeue() << endl; // D
    pq.Enqueue(3, 'F');
    pq.Enqueue(2, 'G');
    pq.Enqueue(3, 'H');
    pq.Enqueue(2, 'Z');
    DequeueAllWithPrint(pq); // expected: E B C G Z F H

    cout << endl;
}
