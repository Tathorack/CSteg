/*
 * @brief     main.cpp
 * @details
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StrToBin.h"
#include "StrEndExc.h"

using namespace std;

StrToBin::StrToBin(const string& text)
: _text (text)
, _scount (0)
, _hcount (0)
, _bcount (0)
{
   _currentbyte = bitset<8>(_text[0]);
   _sizeheader = bitset<32>(sizeof(uint32_t) + (sizeof(char) * _text.length()));
}

bool StrToBin::next(){
   if (!end()){
      if (_hcount < 32){
         return _sizeheader[_hcount++];
      } else {
         bool output = _currentbyte[_bcount++];
         if (_bcount >= 8){
            _currentbyte = bitset<8>(_text[++_scount]);
            _bcount = 0;
         }
         return output;
      }
   } else {
      throw StrEndExc("End of string reached");
   }
}

bool StrToBin::end(){
   if (_scount >= _text.length()){
      return true;
   }
   return false;
}

uint32_t StrToBin::getsize(){
   return _sizeheader.to_ulong();
}
