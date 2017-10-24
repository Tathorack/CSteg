/*
 * @brief     main.cpp
 * @details
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef BINTOSTR_H_
#define BINTOSTR_H_

#include <string>
#include <bitset>
#include <stdint.h>

using namespace std;

class BinToStr {
public:
   BinToStr();
   void next(const bool bit);
   bool end();
   string result();
   uint32_t size();
private:
   string _text;
   bitset<32> _size;
   size_t _hcount; // header count
   bitset<8> _bytes;
   size_t _bcount; // bit count
};

#endif /* BINTOSTR_H_ */
