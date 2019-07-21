
#include "Particle.h"

#include <stdio.h>

#include "Adafruit_GFX.h"

#include "emscripten.h"

#include <emscripten/bind.h>
#include <emscripten/val.h>


using namespace emscripten;

void setup();
void loop();

typedef struct {
	const char *name;
	const GFXfont *gfxFont;
} FontInfo;

#include "Fonts/FreeMono9pt7b.h"
#include "Fonts/FreeMono12pt7b.h"
#include "Fonts/FreeMono18pt7b.h"
#include "Fonts/FreeMono24pt7b.h"
#include "Fonts/FreeMonoBold9pt7b.h"
#include "Fonts/FreeMonoBold12pt7b.h"
#include "Fonts/FreeMonoBold18pt7b.h"
#include "Fonts/FreeMonoBold24pt7b.h"
#include "Fonts/FreeMonoBoldOblique9pt7b.h"
#include "Fonts/FreeMonoBoldOblique12pt7b.h"
#include "Fonts/FreeMonoBoldOblique18pt7b.h"
#include "Fonts/FreeMonoBoldOblique24pt7b.h"
#include "Fonts/FreeMonoOblique9pt7b.h"
#include "Fonts/FreeMonoOblique12pt7b.h"
#include "Fonts/FreeMonoOblique18pt7b.h"
#include "Fonts/FreeMonoOblique24pt7b.h"

#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSans18pt7b.h"
#include "Fonts/FreeSans24pt7b.h"
#include "Fonts/FreeSansBold9pt7b.h"
#include "Fonts/FreeSansBold12pt7b.h"
#include "Fonts/FreeSansBold18pt7b.h"
#include "Fonts/FreeSansBold24pt7b.h"
#include "Fonts/FreeSansBoldOblique9pt7b.h"
#include "Fonts/FreeSansBoldOblique12pt7b.h"
#include "Fonts/FreeSansBoldOblique18pt7b.h"
#include "Fonts/FreeSansBoldOblique24pt7b.h"
#include "Fonts/FreeSansOblique9pt7b.h"
#include "Fonts/FreeSansOblique12pt7b.h"
#include "Fonts/FreeSansOblique18pt7b.h"
#include "Fonts/FreeSansOblique24pt7b.h"

#include "Fonts/FreeSerif9pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "Fonts/FreeSerif18pt7b.h"
#include "Fonts/FreeSerif24pt7b.h"
#include "Fonts/FreeSerifBold9pt7b.h"
#include "Fonts/FreeSerifBold12pt7b.h"
#include "Fonts/FreeSerifBold18pt7b.h"
#include "Fonts/FreeSerifBold24pt7b.h"
#include "Fonts/FreeSerifBoldItalic9pt7b.h"
#include "Fonts/FreeSerifBoldItalic12pt7b.h"
#include "Fonts/FreeSerifBoldItalic18pt7b.h"
#include "Fonts/FreeSerifBoldItalic24pt7b.h"
#include "Fonts/FreeSerifItalic9pt7b.h"
#include "Fonts/FreeSerifItalic12pt7b.h"
#include "Fonts/FreeSerifItalic18pt7b.h"
#include "Fonts/FreeSerifItalic24pt7b.h"

#include "Fonts/Org_01.h"
#include "Fonts/Picopixel.h"
#include "Fonts/Tiny3x3a2pt7b.h"
#include "Fonts/TomThumb.h"

FontInfo fontInfo[] = {
		{ "FreeMono9pt7b", &FreeMono9pt7b },
		{ "FreeMono12pt7b", &FreeMono12pt7b },
		{ "FreeMono18pt7b", &FreeMono18pt7b },
		{ "FreeMono24pt7b", &FreeMono24pt7b },

		{ "FreeMonoBold9pt7b", &FreeMonoBold9pt7b },
		{ "FreeMonoBold12pt7b", &FreeMonoBold12pt7b },
		{ "FreeMonoBold18pt7b", &FreeMonoBold18pt7b },
		{ "FreeMonoBold24pt7b", &FreeMonoBold24pt7b },

		{ "FreeMonoOblique9pt7b", &FreeMonoOblique9pt7b },
		{ "FreeMonoOblique12pt7b", &FreeMonoOblique12pt7b },
		{ "FreeMonoOblique18pt7b", &FreeMonoOblique18pt7b },
		{ "FreeMonoOblique24pt7b", &FreeMonoOblique24pt7b },

		{ "FreeMonoBoldOblique9pt7b", &FreeMonoBoldOblique9pt7b },
		{ "FreeMonoBoldOblique12pt7b", &FreeMonoBoldOblique12pt7b },
		{ "FreeMonoBoldOblique18pt7b", &FreeMonoBoldOblique18pt7b },
		{ "FreeMonoBoldOblique24pt7b", &FreeMonoBoldOblique24pt7b },

		{ "FreeSans9pt7b", &FreeSans9pt7b },
		{ "FreeSans12pt7b", &FreeSans12pt7b },
		{ "FreeSans18pt7b", &FreeSans18pt7b },
		{ "FreeSans24pt7b", &FreeSans24pt7b },

		{ "FreeSansBold9pt7b", &FreeSansBold9pt7b },
		{ "FreeSansBold12pt7b", &FreeSansBold12pt7b },
		{ "FreeSansBold18pt7b", &FreeSansBold18pt7b },
		{ "FreeSansBold24pt7b", &FreeSansBold24pt7b },

		{ "FreeSansOblique9pt7b", &FreeSansOblique9pt7b },
		{ "FreeSansOblique12pt7b", &FreeSansOblique12pt7b },
		{ "FreeSansOblique18pt7b", &FreeSansOblique18pt7b },
		{ "FreeSansOblique24pt7b", &FreeSansOblique24pt7b },

		{ "FreeSansBoldOblique9pt7b", &FreeSansBoldOblique9pt7b },
		{ "FreeSansBoldOblique12pt7b", &FreeSansBoldOblique12pt7b },
		{ "FreeSansBoldOblique18pt7b", &FreeSansBoldOblique18pt7b },
		{ "FreeSansBoldOblique24pt7b", &FreeSansBoldOblique24pt7b },

//
		{ "FreeSerif9pt7b", &FreeSerif9pt7b },
		{ "FreeSerif12pt7b", &FreeSerif12pt7b },
		{ "FreeSerif18pt7b", &FreeSerif18pt7b },
		{ "FreeSerif24pt7b", &FreeSerif24pt7b },

		{ "FreeSerifBold9pt7b", &FreeSerifBold9pt7b },
		{ "FreeSerifBold12pt7b", &FreeSerifBold12pt7b },
		{ "FreeSerifBold18pt7b", &FreeSerifBold18pt7b },
		{ "FreeSerifBold24pt7b", &FreeSerifBold24pt7b },

		{ "FreeSerifItalic9pt7b", &FreeSerifItalic9pt7b },
		{ "FreeSerifItalic12pt7b", &FreeSerifItalic12pt7b },
		{ "FreeSerifItalic18pt7b", &FreeSerifItalic18pt7b },
		{ "FreeSerifItalic24pt7b", &FreeSerifItalic24pt7b },

		{ "FreeSerifBoldItalic9pt7b", &FreeSerifBoldItalic9pt7b },
		{ "FreeSerifBoldItalic12pt7b", &FreeSerifBoldItalic12pt7b },
		{ "FreeSerifBoldItalic18pt7b", &FreeSerifBoldItalic18pt7b },
		{ "FreeSerifBoldItalic24pt7b", &FreeSerifBoldItalic24pt7b },

		{ "Org_01", &Org_01 },
		{ "Picopixel", &Picopixel },
		{ "Tiny3x3a2pt7b", &Tiny3x3a2pt7b },
		{ "TomThumb", &TomThumb }

};

class TestGFX : public GFXcanvas1 {
public:
	TestGFX(int16_t w, int16_t h);

	// Enscripten doesn't like all of the special types like uint16_t, so just wrap them with ints
	void _fillScreen(int color) { fillScreen(color); };
    void _fillRect(int x, int y, int w, int h, int color) { fillRect(x, y, w, h, color); };
    void _writePixel(int x, int y, int color) { writePixel(x, y, color); };
    void _drawLine(int x0, int y0, int x1, int y1, int color) { drawLine(x0, y0, x1, y1, color); };
    void _drawRect(int x, int y, int w, int h, int color) { drawRect(x, y, w, h, color); };
    void _drawCircle(int x0, int y0, int r, int color) { drawCircle(x0, y0, r, color); };
    void _fillCircle(int x0, int y0, int r, int color) { fillCircle(x0, y0, r, color); };
    void _drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color) { drawTriangle(x0, y0, x1, y1, x2, y2, color); };
    void _fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color) { fillTriangle(x0, y0, x1, y1, x2, y2, color); };
    void _drawRoundRect(int x0, int y0, int w, int h, int radius, int color) { drawRoundRect(x0, y0, w, h, radius, color); };
    void _fillRoundRect(int x0, int y0, int w, int h, int radius, int color) { fillRoundRect(x0, y0, w, h, radius, color); };
    void _setCursor(int x, int y) { setCursor(x, y); };
    void _setTextColor(int color) { setTextColor(color); };
    void _setTextSize(int size) { setTextSize(size); };
    void _setTextWrap(int w) { setTextWrap(w != 0); };
    void _drawBitmap(int x, int y, std::vector<int> bitmap, int w, int h, int color);

    void _print(std::string s);
    void _println(std::string s);

    int getNumFonts();
    std::string getFontName(int index);
    std::vector<std::string> getFonts();
    void setFontByName(std::string name);

	val getBytes();


    size_t bufSize;
};

TestGFX::TestGFX(int16_t w, int16_t h) : GFXcanvas1(w, h) {
	bufSize = ((w + 7) / 8) * h;
}

void TestGFX::_print(std::string str) {
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		write((char)*it);
	}
}

void TestGFX::_println(std::string str) {
	for (std::string::iterator it = str.begin(); it < str.end(); it++) {
		write((char)*it);
	}
	write('\n');
}

void TestGFX::_drawBitmap(int x, int y, std::vector<int> bitmapValues, int w, int h, int color) {
	uint8_t *bitmap = new uint8_t[bitmapValues.size()];

	for(size_t ii = 0; ii < bitmapValues.size(); ii++) {
		bitmap[ii] = (uint8_t) bitmapValues[ii];
	}

	drawBitmap((int16_t)x, (int16_t)y, bitmap, (int16_t)w, (int16_t)h, (uint16_t)color);

	delete[] bitmap;
}

std::vector<std::string> TestGFX::getFonts() {
	std::vector<std::string> result;

	size_t numFonts = sizeof(fontInfo) / sizeof(FontInfo);
	for(size_t ii = 0; ii < numFonts; ii++) {
		result.push_back(std::string(fontInfo[ii].name));
	}


	return result;
}


void TestGFX::setFontByName(std::string name) {
	bool found = false;

	size_t numFonts = sizeof(fontInfo) / sizeof(FontInfo);

	for(size_t ii = 0; ii < numFonts; ii++) {
		if (name.compare(fontInfo[ii].name) == 0) {
			setFont(fontInfo[ii].gfxFont);
			found = true;
			break;
		}
	}

	if (!found) {
		setFont(NULL);
	}
}


val TestGFX::getBytes() {

	return val(typed_memory_view(bufSize, getBuffer()));
}

EMSCRIPTEN_BINDINGS(testGFX) {
	class_<TestGFX>("TestGFX")
    		.constructor<int16_t, int16_t>()
			.function("fillRect", &TestGFX::_fillRect)
			.function("fillScreen", &TestGFX::_fillScreen)
			.function("writePixel", &TestGFX::_writePixel)
			.function("drawLine", &TestGFX::_drawLine)
			.function("drawRect", &TestGFX::_drawRect)
			.function("drawCircle", &TestGFX::_drawCircle)
			.function("fillCircle", &TestGFX::_fillCircle)
			.function("drawTriangle", &TestGFX::_drawTriangle)
			.function("fillTriangle", &TestGFX::_fillTriangle)
			.function("drawRoundRect", &TestGFX::_drawRoundRect)
			.function("fillRoundRect", &TestGFX::_fillRoundRect)
			.function("setCursor", &TestGFX::_setCursor)
			.function("setTextColor", &TestGFX::_setTextColor)
			.function("setTextSize", &TestGFX::_setTextSize)
			.function("setTextWrap", &TestGFX::_setTextWrap)
			.function("print", &TestGFX::_print)
			.function("println", &TestGFX::_println)
			.function("drawBitmap", &TestGFX::_drawBitmap)
			.function("getFonts", &TestGFX::getFonts)
			.function("setFontByName", &TestGFX::setFontByName)
			.function("getBytes", &TestGFX::getBytes)
			;
	register_vector<std::string>("VectorString");
	register_vector<int>("VectorInt");
}


int main() {
	setup();
	emscripten_set_main_loop(loop, 100, 1);
}


void setup() {
	// printf("setup\n");
}

void loop() {
	// printf("loop\n");
}
