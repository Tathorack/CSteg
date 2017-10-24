/*
 * @brief     main.cpp
 * @details
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef STRTOBIN_H_
#define STRTOBIN_H_

#include <bitset>
#include <exception>
#include <string>
#include <stdint.h>

using namespace std;

class StrToBin {
public:
   StrToBin(const string& text);
   bool next();
   bool end();
   uint32_t getsize();
private:
   // Message to be encoded
   const string _text;
   // string count
   size_t _scount;
   // size of message in bytes including header
   bitset<32> _sizeheader;
   // header count
   size_t _hcount;
   // Current byte being returned
   bitset<8> _currentbyte;
   // bit count
   size_t _bcount;
};

#endif /* STRTOBIN_H_ */
