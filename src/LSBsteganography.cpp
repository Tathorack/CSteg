/**
 * @author    Rhys Hansen
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

LSBsteganography::LSBsteganography() {

}

LSBsteganography::~LSBsteganography() {
	LSBsteganography::clearimage();
}

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

void LSBsteganography::clearimage(){
	image.release();
}

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


void LSBsteganography::lsbset(uchar& byte, bool bit){
   if (bit) {
      byte |= 1;
   }
   else {
      byte &= ~1;
   }
}


bool LSBsteganography::lsbget(uchar& byte){
   return byte & 1;
}






