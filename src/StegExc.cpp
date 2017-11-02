/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StegExc.h"

using namespace std;

StegExc::StegExc(){

}

StegExc::StegExc(const string& msg)
: _msg (msg)
{

}

StegExc::~StegExc() throw (){

}

const char* StegExc::what() const throw(){
   return name();
}

const char* StegExc::name() const throw(){
   return "Steganography Exception";
}

string StegExc::displayText() const{
   string txt = name();
      if (!_msg.empty()) {
         txt.append(": ");
         txt.append(_msg);
      }
      return txt;
}

StegFileExc::StegFileExc(const string& msg)
: StegExc(msg)
{

}

const char* StegFileExc::name() const throw(){
   return "File Exception";
}

StegImageExc::StegImageExc(const string& msg)
: StegExc(msg)
{

}

const char* StegImageExc::name() const throw(){
   return "Image Exception";
}
