/**
 * @author    Rhys Hansen
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef LSBSTEGANOGRAPHY_H_
#define LSBSTEGANOGRAPHY_H_

#include <set>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * @brief Class for performing least significant bit steganography
 */
class LSBsteganography {
public:
   /**
    * @brief Default constructor
    */
	LSBsteganography();

	/**
	 * @brief Default destructor
	 */
	virtual ~LSBsteganography();

	/**
	 * @brief Load an image from a file to perform steganography on
	 * @details Loads an image file using openCV
	 * @details Refer to the openCV documentation for file format information https://docs.opencv.org
	 * @param[in] imagepath The path to load an image from
	 * @throw StegFileExc image not loaded
	 */
	void loadImage(const string& imagepath);

	/**
	 * @brief Saves the current image to a file
	 * @details Saves an image file to a lossless file format using openCV. Accepted lossless file formats are bmp, dlb, png, tif, & tiff.
	 * @details Refer to the openCV documentation for file format information https://docs.opencv.org
	 * @param[in] imagepath The path to save an image at
	 * @throws StegImageExc no image to save
	 * @throws StegFileExc file extension is not lossless
	 * @throws StegFileExc cv::Exception.what()
	 */
	void saveImage(const string& imagepath);
	/**
	 * @brief Clear the current image from memory
	 * @details calls Mat::release() on the current image. Refer to openCV documentation https://docs.opencv.org
	 */
	void clearimage();

	/**
	 * @brief Steganographically encode a string into the currently open image
	 * @details Uses LSB steganography to encode a string into the LSB of each channel in each each pixel.
	 * Uses StrToBin to encode the message length and convert the string into a series of individual bits.
	 * @param[in] message The string to encode into the image
	 * @throws StegExc image not large enough for message
	 * @throws StegImageExc image size is less than 0!?
	 */
	void encode(const string& message);

	/**
	 * @brief Steganographically decode a string from the currently open image
	 * @details Uses LSB steganography to decode a string from the LSB of each channel in each each pixel.
	 * Uses BinToStr to decode the message length and convert a series of individual bits into a string.
	 * @param[out] The string decoded from the image
	 * @throws StegExc no message found
	 */
	string decode();
private:
	/**Currently open image to perform LSB steganography on */
	Mat image;
	/**Set of accepted lossless image file extensions for saveImage(). These are bmp, dlb, png, tif, & tiff. */
	static const set<string> llext;

	/**
	 * @brief Set the LSB of a byte
	 * @param[in,out] byte The byte to set the LSB on
	 * @param[in] bit The bit to set the LSB to
	 */
	void lsbset(uchar& byte, bool bit);

	/**
	 * @brief Get the LSB of a byte
	 * @param[in] byte The byte to get the LSB from
	 * @return The LSB of byte
	 */
	bool lsbget(uchar& byte);
};

#endif /* LSBSTEGANOGRAPHY_H_ */
