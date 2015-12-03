//
//  main.cpp
//  CS110C_Lab4
//
//  Created by Jon Chaney, Van Ralf Aguas, and Wendy Nguyen on 11/25/15.
//  Purpose:  Prompts the user to enter a number (1,2,3). 1 prompts user to enter a value into a queue
//            2 deletes the first item in queue, and 3 exits the program.
//

#include <iostream>
#include "ArrayQueue.hpp"
#include "ArrayQueue.cpp"
#include "QueueInterface.h"

int main()
{
  int choice = 0;
  int num = 0;    // number to insert
  ArrayQueue<int> queue;
  
  do
  {
    cout << "1) Add item to queue" << endl;
    cout << "2) Remove item from queue" << endl;
    cout << "3) Exit program" << endl;
    cout << "Enter your selection (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
      cout << "Enter item to insert: ";
      cin >> num;
      // determine whether to display queue
      bool handle = true;
      // try to add item to queue, if full throw exception
      try
      {
        queue.enqueue(num);
      }
      catch(QueueException e)
      {
        cout << "Unable to insert on full queue" << endl;
        handle = false;
      }
      
      // if queue not full on enqueue print queue
      if(handle)
      {
        cout << "Queue Contents: ";
        queue.display();
        cout << endl;
      }
      cout << endl;
    }
    
    if (choice == 2)
    {
      // determine whether to display queue
      bool handle = true;
      // try to remove item from queue, if empty throw exception
      try
      {
        queue.dequeue();
      }
      catch(QueueException e)
      {
        cout << "Unable to remove from an empty queue" << endl;
        handle = false;
      }
      // if queue not full on enqueue print queue
      if(handle)
      {
        cout << "Queue Contents: ";
        queue.display();
        cout << endl;
      }
      cout << endl;
    }
  } while (choice != 3 );
}
