
/* 
 * File:   StaticQueue.h
 * Author: Heidi Dye
 *
 * Created on June 8, 2019, 4:56 PM
 */

#ifndef STATICQUEUE_H
#define STATICQUEUE_H


#include <iostream>

using namespace std;

class StaticQueue {
public:
    StaticQueue();
    StaticQueue(const StaticQueue& orig);
    virtual ~StaticQueue();
    StaticQueue(int); //need a size
    void enqueue(int); //add a value to the queue
    int dequeue(); //remove from the queue
    //int valueAt(int); //which index value is at the front
    void output();
    int &operator[](int i) 
    {
        if( i > size ) {
        cout << "Index out of bounds" <<endl; 
        // return first element.
        return queue[0];
         }
         
         return queue[i];
      }
private:
    int* queue; //static queue
    int size; //Number of current values
    int capacity; // total size of the queue
    int front; // location of the front
    int rear; //location of the rear

};

#endif /* STATICQUEUE_H */

