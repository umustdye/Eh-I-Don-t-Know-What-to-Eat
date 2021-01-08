

/* 
 * File:   StaticQueue.cpp
 * Author: Heidi Dye
 * 
 * Created on June 8, 2019, 4:56 PM
 */

#include "StaticQueue.h"

using namespace std;

StaticQueue::StaticQueue() {
}

StaticQueue::StaticQueue(const StaticQueue& orig) {
}

StaticQueue::~StaticQueue() {
}

// creates a static queue based on the size
StaticQueue::StaticQueue(int capacity)
{
    this->capacity =capacity;
    //create the new queue
    this->queue = new int[this->capacity];
    
    //initial settings
    this->size = 0;
    this->front = this->rear = -1;
}

void StaticQueue::enqueue(int val)
{
    if(size == capacity)
    {
        cout<<"Queue is full!"<<endl;
        return;
    }
    
    else
    {
        //first add
        if(front == -1)
        {
            front = rear = 0;
            //assign value to queue
            queue[rear] = val;
        }
        else
        {
            rear = (rear + 1) % capacity;
            queue[rear] = val;
        }
        size++; //adding a value
    }
}

//return the removed value from the queue
int StaticQueue::dequeue()
{
    if(size == 0)
    {
        //Nothing to dequeue
        cout << "Queue is empty!"<< endl;
        return -1; //should be an exception
    }
    
    else
    {
        int val = queue[front];
        front = (front + 1) % capacity; //revolving queue
        size--;
        return val;
    }
}

void StaticQueue::output()
{
    for(int i = 0; i<size; i++)
    {
        cout<<"Value at: "<< front + i<<" is "<< queue[(front + i)% capacity]<< endl;
    }
}

int StaticQueue::valueAt(int index)
{
    int value = queue[front + index];
    return value;
}

