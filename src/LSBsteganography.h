/*
 * @brief Class for performing least significant bit steganography
 * @author    Rhys Hansen
 * @version
 * @copyright Copyright 2017 Rhys Hansen
 */

#ifndef LSBSTEGANOGRAPHY_H_
#define LSBSTEGANOGRAPHY_H_

#include <set>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
 * @brief Class for performing least significant bit steganography
 */
class LSBsteganography {
public:
	LSBsteganography();
	virtual ~LSBsteganography();
	void loadImage(const string imagepath);
	void saveImage(const string imagepath);
	void clearimage();
	void encode(const string message);
	string decode();
private:
	Mat image;
	static const set<string> llext;
	void lsbset(uchar& byte, bool bit);
	bool lsbget(uchar& byte);
};

#endif /* LSBSTEGANOGRAPHY_H_ */
