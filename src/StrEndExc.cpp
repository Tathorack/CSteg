/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StrEndExc.h"

using namespace std;

/**
 * @brief Default constructor
 */
StrEndExc::StrEndExc(){

}

/**
 * @brief Default destructor
 */
StrEndExc::~StrEndExc() throw (){

}

/**
 * @brief Constructor with message
 * @details Allows you to throw a custom message that gets appended to the the exception name.
 */
StrEndExc::StrEndExc(const string& msg)
: _msg (msg)
{

}

/**
 * @brief Override of std::exception::what() for compatibility
 * @returns name()
 */
const char* StrEndExc::what() const throw(){
   return name();
}

/**
 * @brief Exception name
 * @returns "String End Exception"
 */
const char* StrEndExc::name() const throw(){
   return "String End Exception";
}

/**
 * @brief Returns exception text
 * @details Returns exception information with name() appended with #_msg if _msg is not empty.
 * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 * @returns name() or "name(): _msg"
 */
string StrEndExc::displayText() const{
   string txt = name();
      if (!_msg.empty()) {
         txt.append(": ");
         txt.append(_msg);
      }
      return txt;
}
