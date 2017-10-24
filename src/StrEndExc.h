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
   StrEndExc();
   StrEndExc(const string& msg);
   virtual ~StrEndExc() throw();
   virtual const char* what() const throw();
   virtual const char* name() const throw();
   virtual string displayText() const;
private:
   string _msg; /**< Additional error message. Can be empty */
};

#endif /* STRENDEXC_H_ */
