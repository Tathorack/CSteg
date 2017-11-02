/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "StrToBin.h"
#include "CodecExc.h"

using namespace std;

StrToBin::StrToBin(const string& text)
: _text (text)
, _sindex (0)
, _hindex (0)
, _bindex (0)
{
   _currentbyte = bitset<8>(_text[0]);
   _sizeheader = bitset<32>(sizeof(uint32_t) + (sizeof(char) * _text.length()));
}

bool StrToBin::next(){
   if (!end()){
      if (_hindex < 32){
         return _sizeheader[_hindex++];
      } else {
         bool output = _currentbyte[_bindex++];
         if (_bindex >= 8){
            _currentbyte = bitset<8>(_text[++_sindex]);
            _bindex = 0;
         }
         return output;
      }
   } else {
      throw StrEndExc("End of string reached");
   }
}

bool StrToBin::end(){
   if (_sindex >= _text.length()){
      return true;
   }
   return false;
}


uint32_t StrToBin::getsize(){
   return _sizeheader.to_ulong();
}
