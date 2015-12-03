//
//  ArrayQueue.cpp
//  CS110C_Lab4
//
//  Created by Jon Chaney and Van Ralf Aguas on 11/25/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(-1), back(-1)
{
}

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
  // queue is empty when back and front equal -1
  return (front == -1 && back == -1);
}

template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  
  // check to see if list is full
  isFull = (back+1) % MAX_QUEUE == front ? true : false;
  // throw exception is queue is full
  if(isFull)
    throw QueueException("QueueException: queue is full on enqueue");
  // if list is empty front and back equal zero
  else if(isEmpty())
    front = back = 0;
  // sets back to next index
  else
    back = (back+1) % MAX_QUEUE;
  
  // add new item to array
  items[back] = newEntry;
}


template<class ItemType>
void ArrayQueue<ItemType>::dequeue()
{
    // throw QueueException is queue is initially empty
		if(isEmpty())
      throw QueueException("QueueException: queue empty on dequeue");
    // if only one item set front and back to -1
    else if(front == back)
      back = front = -1;
    // set front to next item
    else
      front = (front+1) % MAX_QUEUE;
}

// throw exception if queue is empty
template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const
{
  if (isEmpty())
    throw QueueException("QueueException: queue empty on peekFront");
  else
    return items[front];
}

template <class ItemType>
void ArrayQueue<ItemType>::display()
{
  // throws exception if list is empty
  if(isEmpty())
    throw QueueException("QueueException: queue empty on display");
  else
  {
    // set count to last item in circular queue
    int count = (back + MAX_QUEUE - front) % MAX_QUEUE + 1;
    // display items
		for(int i = 0; i < count; i++)
    {
      cout << items[(front+i) % MAX_QUEUE] << " ";
    }
  }
}




