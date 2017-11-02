/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef STRENDEXC_H_
#define STRENDEXC_H_

#include <exception>
#include <string>

using namespace std;

/**
 * @brief String End Exception
 * @details Thrown when StrToBin and BinToStr reach the end of the string that they are encoding.
 * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 */
class StrEndExc: public exception {
public:
   /**
    * @brief Default constructor
    */
   StrEndExc();

   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   StrEndExc(const string& msg);

   /**
    * @brief Default destructor
    */
   virtual ~StrEndExc() throw();

   /**
    * @brief Override of std::exception::what() for compatibility
    * @returns name()
    */
   virtual const char* what() const throw();

   /**
    * @brief Exception name
    * @returns "String End Exception"
    */
   virtual const char* name() const throw();

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

#endif /* STRENDEXC_H_ */
