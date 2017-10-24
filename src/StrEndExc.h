/*
 * @brief     main.cpp
 * @details
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 *      Adapted from Poco/Exception
 *      https://pocoproject.org/docs/Poco.Exception.html
 */

#ifndef STRENDEXC_H_
#define STRENDEXC_H_

#include <exception>
#include <string>

using namespace std;

class StrEndExc: public std::exception {
public:
   StrEndExc();
   StrEndExc(const string& msg);
   virtual ~StrEndExc() throw();
   virtual const char* what() const throw();
   virtual const char* name() const throw();
   virtual string displayText() const;
private:
   string _msg;
};

#endif /* STRENDEXC_H_ */
