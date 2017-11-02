/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StegExc.h"

using namespace std;

StegExc::StegExc(const string& msg)
: BaseException(msg)
{

}

StegExc::~StegExc() throw(){

}

const char* StegExc::name() const throw(){
   return "Steganography Exception";
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
