/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef STRTOBIN_H_
#define STRTOBIN_H_

#include <bitset>
#include <string>
#include <stdint.h>

using namespace std;

/**
 * @brief Class for converting a string into a series of bits that can be converted back to a string using BinToStr.
 * @details The message is output one bit at a time by calling next().
 * Before the the message a uint32_t header with the size of the header and the message is encoded and output one bit at a time.
 * This allows BinToStr to know when to end when decoding the string.
 * After the header is output the message is output one bit at a time till the end of the message.
 * At this point a StrEndExc is thrown.
 */
class StrToBin {
public:
   StrToBin(const string& text);
   bool next();
   bool end();
   uint32_t getsize();
private:
   const string _text;     /**< Message to be encoded */
   size_t _sindex;         /**< string index */
   bitset<32> _sizeheader; /**< Size of message in bytes including header */
   size_t _hindex;         /**< header index */
   bitset<8> _currentbyte; /**< Current byte being returned */
   size_t _bindex;         /**< bit index */
};

#endif /* STRTOBIN_H_ */
