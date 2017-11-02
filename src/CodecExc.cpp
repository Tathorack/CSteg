/*
 * @brief     CodecExc.cpp
 * @details   
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "CodecExc.h"

CodecExc::CodecExc(const string& msg)
: BaseException(msg)
{

}

CodecExc::~CodecExc() throw(){

}

const char* CodecExc::name() const throw(){
   return "Codec Exception";
}

StrEndExc::StrEndExc(const string& msg)
: CodecExc(msg)
{

}

const char* StrEndExc::name() const throw(){
   return "String End Exception";
}


