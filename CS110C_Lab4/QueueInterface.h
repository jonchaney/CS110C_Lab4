//
//  QueueInterface.h
//  CS110C_Lab4
//
//  Created by Jon Chaney and Van Ralf Aguas on 11/25/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#ifndef QueueInterface_h
#define QueueInterface_h

template<class ItemType>
class QueueInterface
{
public:
  // sees whether this queue is empty
  // return true if the queue is empty, false if not
  virtual bool isEmpty() const = 0;
  
  // adds a new entry to the back of this queue
  // post  : newEntry is a the back of the Queue
  // param : newEntry is the object to be added as a new entry
  // throw QueueException if Queue is full
  virtual void enqueue(const ItemType& newEntry) = 0;
  
  // removes the front of this queue
  // post  : the front of the queue is removed
  // throw : QueueException if queue is initally empty
  virtual void dequeue() = 0;
  
  // returns a copy of the front of this queue
  // post   : a copy of the front of the queue is returned and the queue is unchanged
  // return : a copy of the front of the queue
  // throw  : QueueException if queue is initally empty
  virtual ItemType peekFront() const = 0;
};
#endif 
