/*
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#include "LSBsteganography.h"

#include <bitset>
#include "Poco/Path.h"

#include "StrToBin.h"
#include "BinToStr.h"
#include "StegExc.h"

using namespace std;
using namespace cv;

const string tmp[] = {"bmp", "dlb", "png", "tif", "tiff"};
const set<string> LSBsteganography::llext(tmp, tmp + sizeof(tmp) / sizeof(tmp[0]));


/**
 * @brief Default constructor
 */
LSBsteganography::LSBsteganography() {

}

/**
 * @brief Default destructor
 */
LSBsteganography::~LSBsteganography() {
	LSBsteganography::clearimage();
}

/**
 * @brief Load an image from a file
 * @details Loads an image file using openCV. Refer to the openCV documentation for file format support https://docs.opencv.org
 * @param[in] imagepath The path to load an image from
 * @throw StegFileExc image not loaded
 */
void LSBsteganography::loadImage(const string imagepath){
//   if an image already is loaded clear it
	if (image.data){
		clearimage();
	}
//	load image and throw if no data
	image = imread(imagepath, 1);
	if(!image.data){
		throw StegFileExc("image not loaded");
	}
}

/**
 * @brief Saves the current image to a file
 * @details Saves an image file to a lossless file format using openCV. Accepted lossless file formats are bmp, dlb, png, tif, & tiff.
 * Refer to the openCV documentation for file format support https://docs.opencv.org
 * @param[in] imagepath The path to save an image at
 * @throws StegImageExc no image to save
 * @throws StegFileExc file extension is not lossless
 * @throws StegFileExc cv::Exception.what()
 */
void LSBsteganography::saveImage(const string imagepath){
//   check for image data
	if (!image.data){
		throw StegImageExc("no image to save");
	}
//   check if extension is in the set of lossless extensions
   Poco::Path p(imagepath);
   set<string>::iterator it = llext.find(p.getExtension());
   if (it == llext.end()) {
      throw StegFileExc("file extension is not lossless");
   }
//   write image and throw cv::Exception as StegFileExc
   try {
      imwrite(imagepath, image);
   }
   catch (cv::Exception& ex) {
      throw StegFileExc(ex.what());
   }
}

/**
 * @brief Clear the current image from memory
 * @details calls Mat.release() on the current image. Refer to openCV documentation https://docs.opencv.org
 */
void LSBsteganography::clearimage(){
	image.release();
}


/**
 * @brief Set the LSB of a byte
 * @param[in,out] byte The byte to set the LSB on
 * @param[in] bit The bit to set the LSB to
 */
void LSBsteganography::lsbset(uchar& byte, bool bit){
   if (bit) {
      byte |= 1;
   }
   else {
      byte &= ~1;
   }
}

/**
 * @brief Get the LSB of a byte
 * @param[in] byte The byte to get the LSB from
 * @return The LSB of byte
 */
bool LSBsteganography::lsbget(uchar& byte){
   return byte & 1;
}

/**
 * @brief Encode a string into the currently open image
 * @details Uses LSB steganography to encode a string into the LSB of each channel in each each pixel.
 * Uses StrToBin to encode the message length and convert the string into a series of individual bits.
 * @param[in] message The string to encode into the image
 * @throws StegExc image not large enough for message
 * @throws StegImageExc image size is less than 0!?
 */
void LSBsteganography::encode(const string message){
   StrToBin msg = StrToBin(message);
   int imagesize = (image.cols * image.rows * image.channels()) / 8;
   if (imagesize < 0){
      throw StegImageExc("image size is less than 0!?");
   }
   unsigned uimagesize = (unsigned) imagesize;
   if (msg.getsize() > uimagesize) {
      throw StegExc("image not large enough for message");
   }
   for (int x = 0; x < image.cols; x++){
      for (int y = 0; x < image.rows; y++){
         for (int c = 0; c < image.channels(); c++){
            if (msg.end()){
               return;
            } else {
               lsbset(image.at<Vec3b>(y, x)[c], msg.next());
            }
         }
      }
   }
}

/**
 * @brief Decode a string from the currently open image
 * @details Uses LSB steganography to decode a string from the LSB of each channel in each each pixel.
 * Uses BinToStr to decode the message length and convert a series of individual bits into a string.
 * @param[out] The string decoded from the image
 * @throws StegExc no message found
 */
string LSBsteganography::decode(){
   BinToStr msg = BinToStr();
   for (int x = 0; x < image.cols; x++){
      for (int y = 0; x < image.rows; y++){
         for (int c = 0; c < image.channels(); c++){
            if (msg.end()){
               return msg.result();
            } else {
               msg.next(lsbget(image.at<Vec3b>(y, x)[c]));
            }
         }
      }
   }
   throw StegExc("no message found");
}
