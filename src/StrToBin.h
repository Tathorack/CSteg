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
   /**
    * @brief Default constructor
    * @param[in] text String to be converted to binary stream
    */
   StrToBin(const string& text);

   /**
    * @brief Returns the next bit
    * @details
    * @returns Next bit in message
    */
   bool next();

   /**
    * @brief Checks if at end of #_text
    * @returns true if at end else false
    */
   bool end();

   /**
    * @brief Gets the size of the message in bytes including the header
    * @returns Size of message and header
    */
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
