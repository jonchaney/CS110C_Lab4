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
  return (front == -1 && back == -1);
}

// To check whether Queue is full or not
template<class ItemType>
bool ArrayQueue<ItemType>::isFull() const
{
		return (back+1) % MAX_QUEUE == front ? true : false;
}

// throw exception is queue is full
template<class ItemType>
void ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
  if(isFull())
    throw QueueException("QueueException: queue is full on enqueue");
  else if(isEmpty())
    front = back = 0;
  else
    back = (back+1)%MAX_QUEUE;
  
  items[back] = newEntry;
}

// throw QueueException is queue is initially empty
template<class ItemType>
void ArrayQueue<ItemType>::dequeue()
{
		if(isEmpty())
      throw QueueException("QueueException: queue empty on dequeue");
    else if(front == back )
      back = front = -1;
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

// throws exception if list is empty
template <class ItemType>
void ArrayQueue<ItemType>::display()
{
  if(isEmpty())
    throw QueueException("QueueException: queue empty on display");
  else
    for (int i = front; i <= back; i++)
      cout << items[i] << " ";
}




