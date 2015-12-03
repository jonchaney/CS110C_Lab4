//
//  ArrayQueue.hpp
//  CS110C_Lab4
//
//  Created by Jon Chaney and Van Ralf Aguas on 11/25/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include "QueueInterface.h"
#include "QueueException.h"

const int MAX_QUEUE = 4;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
  ItemType items[MAX_QUEUE];   // array of queue items
  int front;                   // index to front of queue
  int back;                    // index to back of queue
  bool isFull;
  
public:
  ArrayQueue();
  // copy constructor and destructor are supplied by the compiler
  
  // sees whether this queue is empty
  // return true if the queue is empty, false if not
  bool isEmpty() const;
  
  // adds a new entry to the back of this queue
  // post  : newEntry is a the back of the Queue
  // param : newEntry is the object to be added as a new entry
  // throw QueueException if Queue is full
  void enqueue(const ItemType& newEntry);
  
  // removes the front of this queue
  // post  : the front of the queue is removed
  // throw : QueueException if queue is initally empty
  void dequeue();
  
  // returns a copy of the front of this queue
  // post   : a copy of the front of the queue is returned and the queue is unchanged
  // return : a copy of the front of the queue
  // throw  : QueueException if queue is initally empty
  ItemType peekFront() const;
  
  // displays queue
  // post : none
  // throw : throws exception if list is empty
  void display();
};

#endif /* ArrayQueue_hpp */
