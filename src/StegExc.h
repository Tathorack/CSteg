/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef STEGEXC_H_
#define STEGEXC_H_

#include "BaseException.h"

using namespace std;

/**
 * @brief Steganography Exception
 * @details Class for all exceptions to be thrown by LSBsteganography.
 */
class StegExc: public BaseException {
public:
   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   StegExc(const string& msg);

   /**
    * @brief Default destructor
    */
   virtual ~StegExc() throw();

   /**
    * @brief Exception name
    * @returns "Steganography Exception"
    */
   virtual const char* name() const throw();
private:
   string _msg; /**< Additional error message. Can be empty */
};

/**
 * @brief Steganography File Exception
 * @details Exception class to be thrown by LSBsteganography if it encounters file errors.
 */
class StegFileExc: public StegExc {
public:
   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   StegFileExc(const string& msg);

   /**
    * @brief Exception name
    * @returns "File Exception"
    */
   virtual const char* name() const throw();
};

/**
 * @brief Steganography Image Exception
 * @details Exception class to be thrown by LSBsteganography if it encounters image errors.
 */
class StegImageExc: public StegExc {
public:
   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   StegImageExc(const string& msg);

   /**
    * @brief Exception name
    * @returns "Image Exception"
    */
   virtual const char* name() const throw();
};

#endif /* STEGEXC_H_ */
