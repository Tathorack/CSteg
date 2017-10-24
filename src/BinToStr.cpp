/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "BinToStr.h"
#include "StrEndExc.h"

BinToStr::BinToStr()
: _text ("")
, _hindex (0)
, _bindex (0)
{

}

void BinToStr::next(const bool bit){
   if (!end()){
      if (_hindex < 32){
         _size[_hindex++] = bit;
      } else {
         _bytes[_bindex++] = bit;
         if (_bindex >= 8){
            _text.append(1, _bytes.to_ulong());
            _bindex = 0;
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
   if (_hindex < 32){
      return 0;
   } else {
      return _size.to_ulong();
   }
}
