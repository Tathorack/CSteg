/*
 * @brief     BaseException.cpp
 * @details   
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "BaseException.h"

BaseException::BaseException(const string& msg)
: _msg (msg)
{

}

BaseException::~BaseException() throw(){

}

const char* BaseException::what() const throw(){
   return name();
}

string BaseException::displayText() const{
   string txt = name();
      if (!_msg.empty()) {
         txt.append(": ");
         txt.append(_msg);
      }
      return txt;
}
