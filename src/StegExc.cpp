/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StegExc.h"

using namespace std;

/**
 * @brief Default constructor
 */
StegExc::StegExc(){

}

/**
 * @brief Default destructor
 */
StegExc::~StegExc() throw (){

}

/**
 * @brief Constructor with message
 * @details Allows you to throw a custom message that gets appended to the the exception name.
 */
StegExc::StegExc(const string& msg)
: _msg (msg)
{

}

/**
 * @brief Override of std::exception::what() for compatibility
 * @returns name()
 */
const char* StegExc::what() const throw(){
   return name();
}

/**
 * @brief Exception name
 * @returns "Steganography Exception"
 */
const char* StegExc::name() const throw(){
   return "Steganography Exception";
}

/**
 * @brief Returns exception text
 * @details Returns exception information with name() appended with #_msg if _msg is not empty.
 * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 * @returns name() or "name(): _msg"
 */
string StegExc::displayText() const{
   string txt = name();
      if (!_msg.empty()) {
         txt.append(": ");
         txt.append(_msg);
      }
      return txt;
}

/**
 * @brief Constructor with message
 * @details Allows you to throw a custom message that gets appended to the the exception name.
 */
StegFileExc::StegFileExc(const string& msg)
: StegExc(msg)
{

}

/**
 * @brief Exception name
 * @returns "File Exception"
 */
const char* StegFileExc::name() const throw(){
   return "File Exception";
}

/**
 * @brief Constructor with message
 * @details Allows you to throw a custom message that gets appended to the the exception name.
 */
StegImageExc::StegImageExc(const string& msg)
: StegExc(msg)
{

}

/**
 * @brief Exception name
 * @returns "Image Exception"
 */
const char* StegImageExc::name() const throw(){
   return "Image Exception";
}
