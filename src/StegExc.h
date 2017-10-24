/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef STEGEXC_H_
#define STEGEXC_H_

#include <string>
#include <exception>

using namespace std;

/**
 * @brief Steganography Exception
 * @details Base Exception class to be thrown by LSBsteganography.
 * @details Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 */
class StegExc: public exception {
public:
   StegExc();
   StegExc(const string& msg);
   virtual ~StegExc() throw ();
   virtual const char* what() const throw();
   virtual const char* name() const throw();
   virtual string displayText() const;
private:
   string _msg; /**< Additional error message. Can be empty */
};

/**
 * @brief Steganography File Exception
 * @details Exception class to be thrown by LSBsteganography if it encounters file errors.
 */
class StegFileExc: public StegExc {
public:
   StegFileExc(const string& msg);
   virtual const char* name() const throw();
};

/**
 * @brief Steganography Image Exception
 * @details Exception class to be thrown by LSBsteganography if it encounters image errors.
 */
class StegImageExc: public StegExc {
public:
   StegImageExc(const string& msg);
   virtual const char* name() const throw();
};

#endif /* STEGEXC_H_ */
