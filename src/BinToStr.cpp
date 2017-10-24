/*
 * @brief     main.cpp
 * @details
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "BinToStr.h"
#include "StrEndExc.h"

BinToStr::BinToStr()
: _text ("")
, _hcount (0)
, _bcount (0)
{

}

void BinToStr::next(const bool bit){
   if (!end()){
      if (_hcount < 32){
         _size[_hcount++] = bit;
      } else {
         _bytes[_bcount++] = bit;
         if (_bcount >= 8){
            _text.append(1, _bytes.to_ulong());
            _bcount = 0;
         }
      }
   } else {
      throw StrEndExc("End of string reached");
   }
}

bool BinToStr::end(){
   if (_text.length() >= size() - sizeof(uint32_t)){
      return true;
   }
   return false;
}

std::string BinToStr::result(){
   return _text;
}

uint32_t BinToStr::size(){
   if (_hcount < 32){
      return 0;
   } else {
      return _size.to_ulong();
   }
}
