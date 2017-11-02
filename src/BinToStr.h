/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef BINTOSTR_H_
#define BINTOSTR_H_

#include <bitset>
#include <string>
#include <stdint.h>

using namespace std;

/**
 * @brief Class for converting a series of bits generated with StrToBin to be converted back to a string.
 * @details The message is input one bit at a time by calling next().
 * Before the the message a uint32_t header with the size of the header and the message is read.
 * This allows BinToStr to know when to end when decoding the string.
 * After the header is read the message is input one bit at a time till the end of the message.
 * At this point a StrEndExc is thrown.
 */
class BinToStr {
public:
   /**
    * @brief Default constructor
    */
   BinToStr();

   /**
    * @brief Adds the next bit to the current message
    * @details
    * @param[in] bit The bit to add to the current message
    */
   void next(const bool bit);

   /**
    * @brief Checks if at end of #_text
    * @details Uses the size encoded in the header to determine if the end of the message has been reached
    * @returns true if at end else false
    */
   bool end();

   /**
    * @brief Returns the result as currently encoded
    * @details Should only be called after end() == true or StrEndExc is thrown
    * @returns The string created from the binary stream
    */
   string result();

   /**
   * @brief Gets the size of the message in bytes including the header
   * @returns Size of message and header if header has been read else returns 0
   */
   uint32_t getsize();
private:
   string _text;     /**< Message being decoded */
   bitset<32> _size; /**< Size of message in bytes including header */
   size_t _hindex;   /**< header index */
   bitset<8> _bytes; /**< Current byte being decoded */
   size_t _bindex;   /**< bit index */
};

#endif /* BINTOSTR_H_ */
