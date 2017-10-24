/*
 * @brief     Steg
 * @details   Adapted from Poco/Exception https://pocoproject.org/docs/Poco.Exception.html
 * 
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 * 
 */

#ifndef STEGEXC_H_
#define STEGEXC_H_

#include <string>
#include <exception>

using namespace std;

class StegExc: public exception {
public:
   StegExc();
   StegExc(const string& msg);
   virtual ~StegExc() throw ();
   virtual const char* what() const throw();
   virtual const char* name() const throw();
   virtual string displayText() const;
private:
   string _msg;
};

class StegFileExc: public StegExc {
public:
   StegFileExc(const string& msg);
   virtual const char* name() const throw();
};

class StegImageExc: public StegExc {
public:
   StegImageExc(const string& msg);
   virtual const char* name() const throw();
};

#endif /* STEGEXC_H_ */
