//A simple header for text printing related stuffs
//Cross-Platform
//Huge Thanks to https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal

#ifndef PRINTER_H
#define PRINTER_H

#ifdef _WIN32
	#define PLATFORM_WINDOWS 1
#endif
#if __linux__
	#define PLATFORM_LINUX 1
#endif


constexpr auto MAX_BUFFER_LENGTH = 128;
constexpr bool IN_RANGE(int option, int start, int end)
{
	return option > start && option < end;
}

enum e_text_foreground_colors
{
	_text_foreground_start = 29,

	_text_foreground_black,
	_text_foreground_red,
	_text_foreground_green,
	_text_foreground_yellow,
	_text_foreground_blue,
	_text_foreground_magneta,
	_text_foreground_cyan,
	_text_foreground_white,

	_text_foreground_end,
	_text_foreground_default = _text_foreground_white
};

enum e_text_background_colors
{
	_text_background_start = 39,

	_text_background_black,
	_text_background_red,
	_text_background_green,
	_text_background_yellow,
	_text_background_blue,
	_text_background_magneta,
	_text_background_cyan,
	_text_background_white,

	_text_background_end,
	_text_background_default = _text_background_black
};

enum e_text_styles
{
	_text_style_reset = 0,			//Back to normal (remove all styles)
	_text_style_bold = 1,			//Bold the text
	_text_style_underline = 4,		//Underline text
	_text_style_inverse = 7,		//Interchange colors of background and foreground
	_text_style_bold_off = 21,		//Normal from bold
	_text_style_underline_off = 24,//Normal from Underline
	_text_style_inverse_off = 27,	//Reverse of the Inverse

};


void printerFormatText(char* dest, const char* text);
void printerFormatText(char* dest, const char* text, const e_text_foreground_colors);
void printerFormatText(char* dest, const char* text, const e_text_foreground_colors, const e_text_background_colors);
void printerFormatText(char* dest, const char* text, const e_text_foreground_colors, const e_text_background_colors, const e_text_styles);

void printerPrintText(const char*);
void printerPrintText(const char*, const e_text_foreground_colors);
void printerPrintText(const char*, const e_text_foreground_colors, const e_text_background_colors);
void printerPrintText(const char*, const e_text_foreground_colors, const e_text_background_colors, const e_text_styles);

void printerSlowPrint(const char*);
void printerSlowPrint(const char*,int);


void printerClearScreen();


#undef PRINTER_H

#endif // !PRINTER_H
