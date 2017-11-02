/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StrEndExc.h"

using namespace std;

StrEndExc::StrEndExc(){

}

StrEndExc::~StrEndExc() throw (){

}

StrEndExc::StrEndExc(const string& msg)
: _msg (msg)
{

}

const char* StrEndExc::what() const throw(){
   return name();
}

const char* StrEndExc::name() const throw(){
   return "String End Exception";
}

string StrEndExc::displayText() const{
   string txt = name();
      if (!_msg.empty()) {
         txt.append(": ");
         txt.append(_msg);
      }
      return txt;
}
