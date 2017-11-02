/*
 * @brief     BaseException.h
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;


/**
 * @brief Base Exception
 * @details Virtual class that all exceptions can be derived from.
 * Adds the ability to throw an exception with a message with a custom constructor and displayText().
 * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 */
class BaseException: public exception {
public:
   /**
    * @brief Default constructor
    */
   BaseException();

   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   BaseException(const string& msg);

   /**
    * @brief Default destructor
    */
   virtual ~BaseException() throw();

   /**
    * @brief Override of std::exception::what() for compatibility
    * @returns name()
    */
   virtual const char* what() const throw();

   /**
    * @brief Exception name
    * @details Should be set by the subclass
    */
   virtual const char* name() const throw() = 0;

   /**
    * @brief Returns exception text
    * @details Returns exception information with name() appended with #_msg if _msg is not empty.
    * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
    * @returns name() or "name(): _msg"
    */
   virtual string displayText() const;
private:
   string _msg; /**< Additional error message. Can be empty */
};

#endif /* BASEEXCEPTION_H_ */
