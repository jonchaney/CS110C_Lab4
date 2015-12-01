//
//  main.cpp
//  CS110C_Lab4
//
//  Created by Jon Chaney and Van Ralf Aguas on 11/25/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#include <iostream>
#include "ArrayQueue.hpp"
#include "ArrayQueue.cpp"
#include "QueueInterface.h"

int main() {
  int choice = 0;
  int num = 0;
  
  ArrayQueue<int> queue;
  
  do {
    cout << "1) Add item to queue" << endl;
    cout << "2) Remove item from queue" << endl;
    cout << "3) Exit program" << endl;
    cout << "Enter your selection (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
      cout << "Enter item to insert: ";
      cin >> num;
      queue.enqueue(num);
      cout << endl;
    }
    
    cout << endl;
    
    if (choice == 2)
    {
      cout << "Remaining items: ";
      queue.dequeue();
      queue.display();
      cout << endl;
    }
  } while (choice != 3 );
}
