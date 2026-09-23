#include "priority_queue.h"

PriorityQueue::PriorityQueue()
{
    size = 0;
}

bool PriorityQueue::isEmpty()
{
    return size == 0;
}

bool PriorityQueue::isFull()
{
    return size == MAX_APPLICANTS;
}

int PriorityQueue::getSize()
{
    return size;
}

void PriorityQueue::swap(Applicant *&a, Applicant *&b)
{
    Applicant *temp = a;
    a = b;
    b = temp;
}

// Returns true if a should come before b
bool PriorityQueue::higherPriority(Applicant *a, Applicant *b)
{
    // 1. Smaller distance = higher priority
    if (a->distance < b->distance)
        return true;

    if (a->distance > b->distance)
        return false;

    // 2. Higher rating = higher priority
    if (a->workerRating > b->workerRating)
        return true;

    if (a->workerRating < b->workerRating)
        return false;

    // 3. Earlier application = higher priority
    return a->applicationTime < b->applicationTime;
}

void PriorityQueue::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (higherPriority(heap[index], heap[parent]))
        {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int best = index;

        if (left < size &&
            higherPriority(heap[left], heap[best]))
        {
            best = left;
        }

        if (right < size &&
            higherPriority(heap[right], heap[best]))
        {
            best = right;
        }

        if (best != index)
        {
            swap(heap[index], heap[best]);
            index = best;
        }
        else
        {
            break;
        }
    }
}

void PriorityQueue::push(Applicant *applicant)
{
    if (isFull())
    {
        return;
    }

    heap[size] = applicant;

    heapifyUp(size);

    size++;
}

Applicant *PriorityQueue::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }

    Applicant *top = heap[0];

    heap[0] = heap[size - 1];

    size--;

    if (size > 0)
    {
        heapifyDown(0);
    }

    return top;
}