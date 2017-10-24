/*
 * @brief     main.cpp
 * @details   
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */


#include <iostream>
#include <opencv2/opencv.hpp>

#include "LSBsteganography.h"
#include "StegExc.h"

using namespace cv;

int main( int argc, char** argv )
{
   try{
      LSBsteganography steg = LSBsteganography();
      steg.loadImage(argv[1]);
      steg.encode("Test Message");
      std::cout << steg.decode() << std::endl;
      steg.saveImage("test.png");
      steg.clearimage();
//      std::cout << steg.decode() << std::endl;
      steg.loadImage("test.png");
      std::cout << steg.decode() << std::endl;
   }
   catch (StegExc& ex){
      std::cout << ex.displayText() << std::endl;
      return 1;
   }
   return 0;
}

