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
  
public:
  ArrayQueue();
  // copy constructor and destructor are supplied by the compiler
  
  bool isEmpty() const;
  bool isFull() const;
  
  // throw QueueException is queue is full
  void enqueue(const ItemType& newEntry);
  
  // throw QueueException if queue is initially empty
  void dequeue();
  
  // throw QueueException if queue is empty
  ItemType peekFront() const;
  
  // displays queue
  void display();
};

#endif /* ArrayQueue_hpp */
