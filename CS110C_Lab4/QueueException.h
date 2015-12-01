//
//  QueueException.h
//  CS110C_Lab4
//
//  Created by Jon Chaney and Van Ralf Aguas on 11/25/15.
//  Copyright © 2015 Jon Chaney. All rights reserved.
//

#ifndef QueueException_h
#define QueueException_h
#include <stdexcept>
#include <string>

using namespace std;

class QueueException : public logic_error
{
public:
  QueueException(const string& message="")
  : logic_error(message.c_str())
  {}
};
#endif /* QueueException_h */
