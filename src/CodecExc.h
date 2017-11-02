/*
 * @brief     CodecExc.h
 * @details   
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef CODECEXC_H_
#define CODECEXC_H_

#include "BaseException.h"

using namespace std;

class CodecExc: public BaseException {
public:
   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   CodecExc(const string& msg);

   /**
    * @brief Default destructor
    */
   virtual ~CodecExc() throw();

   /**
    * @brief Exception name
    * @returns "Codec Exception"
    */
   virtual const char* name() const throw();

};

/**
 * @brief String End Exception
 * @details Thrown when StrToBin and BinToStr reach the end of the string that they are encoding.
 */
class StrEndExc: public CodecExc {
public:
   /**
    * @brief Constructor with message
    * @details Allows you to throw a custom message that gets appended to the the exception name.
    * @param[in] msg custom message to append to exception name when calling displayText().
    */
   StrEndExc(const string& msg);

   /**
    * @brief Exception name
    * @returns "String End Exception"
    */
   virtual const char* name() const throw();
};

#endif /* CODECEXC_H_ */
