// Project UID af1f95f547e44c8ea88730dfb185559d

#include <fstream>
#include "Matrix.h"
#include "Image.h"
#include "processing.h"
using namespace std;

int main(int argc, char* argv[]) {
	int width;
	int height;
	if (argc < 4 || argc > 5) {
		cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
			<< "WIDTH and HEIGHT must be less than or equal to original" << endl;
		return 1;
	}
	ifstream is;
	ofstream os;
	is.open(argv[1]);
	os.open(argv[2]);
	if (!is) {
		cout << "Error opening file: " << argv[1] << endl;
		return 1;
	}
	if (!os) {
		cout << "Error opening file: " << argv[2] << endl;
		return 1;
	}
	Image* img = new Image;
	Image_init(img, is);
	width = atoi(argv[3]);
	if (width <= 0 || width > Image_width(img)) {
		cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
			<< "WIDTH and HEIGHT must be less than or equal to original" << endl;
		return 1;
	}
	if (argc == 5) {
		height = atoi(argv[4]);
		if (height <= 0 || height > Image_height(img)) {
			cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
				<< "WIDTH and HEIGHT must be less than or equal to original" << endl;
			return 1;
		}
	}
	else {
		height = Image_height(img);
	}
	seam_carve(img, width, height);
	Image_print(img, os);
	is.close();
	os.close();
	delete img;

	return 0;
}