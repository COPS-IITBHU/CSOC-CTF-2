#include "printer.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <assert.h>


/// <summary>
/// Simply copies to destination buffer
/// </summary>
/// <param name="dest">Target Buffer</param>
/// <param name="text">Source C-String</param>
void printerFormatText(char* dest, const char* text)
{
	printerFormatText(dest, text, _text_foreground_default);
}
/// <summary>
/// Adds Foregound text colors to a given text and copy to destination buffer
/// </summary>
/// <param name="dest">Target Buffer</param>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
void printerFormatText(char* dest, const char* text,
	const e_text_foreground_colors foreground)
{
	printerFormatText(dest, text, foreground, _text_background_default);
}
/// <summary>
/// Adds Foregound and Background text colors to a given text and copy to destination buffer
/// </summary>
/// <param name="dest">Target Buffer</param>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
/// <param name="background">Text Highlight color</param>
void printerFormatText(char* dest, const char* text,
	const e_text_foreground_colors foreground,
	const e_text_background_colors background)
{
	printerFormatText(dest, text, foreground, background, _text_style_reset);
}
/// <summary>
/// Style a C-String Text as you like
/// </summary>
/// <param name="dest">Target Buffer</param>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
/// <param name="background">Text Highlight color</param>
/// <param name="style">Additional Options</param>
void printerFormatText(char* dest, const char* text,
	const e_text_foreground_colors foreground,
	const e_text_background_colors background,
	const e_text_styles style)
{

	int result = 0;

	assert(IN_RANGE(foreground, _text_foreground_start, _text_foreground_end));
	assert(IN_RANGE(background, _text_background_start, _text_background_end));

	result = snprintf(dest,
		MAX_BUFFER_LENGTH,
		"\033[%d;%d;%dm%s\033[0m",
		style,
		foreground,
		background,
		text);

	assert(result >= 0 && result < MAX_BUFFER_LENGTH);//if this happens then verify text length or arguments
}


/// <summary>
/// Prints text with default settings
/// </summary>
/// <param name="text">Source C-String</param>
void printerPrintText(const char* text)
{
	printerPrintText(text, _text_foreground_default);
}
/// <summary>
/// Prints text with added Foreground color
/// </summary>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
void printerPrintText(const char* text,
	const e_text_foreground_colors foreground)
{
	printerPrintText(text, foreground, _text_background_default);
}
/// <summary>
/// Prints text with added Foreground and Background colors
/// </summary>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
/// <param name="background">Text Highlight color</param>
void printerPrintText(const char* text,
	const e_text_foreground_colors foreground,
	const e_text_background_colors background)
{
	printerPrintText(text, foreground, background, _text_style_reset);
}
/// <summary>
/// Print a C-String Text as you like
/// </summary>
/// <param name="text">Source C-String</param>
/// <param name="foreground">Text Color</param>
/// <param name="background">Text Highlight color</param>
/// <param name="style">Additional Options</param>
void printerPrintText(const char* text,
	const e_text_foreground_colors foreground,
	const e_text_background_colors background,
	const e_text_styles style)
{
	char buffer[MAX_BUFFER_LENGTH];
	printerFormatText(buffer, text, foreground, background, style);
	puts(buffer);
}
/// <summary>
/// Print a C-String slowly with 50ms delay
/// </summary>
/// <param name="text"></param>
void printerSlowPrint(const char* text)
{
	printerSlowPrint(text, 50);
}
/// <summary>
/// Print a C-String slowly with delay between each characters
/// </summary>
/// <param name="text"></param>
/// <param name="delay"></param>
void printerSlowPrint(const char* text,int delay)
{
	int len = strlen(text);
	for (int i = 0; i < len; i++)
	{
		printf("%c", text[i]);
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}

}
/// <summary>
/// Clears the Console window
/// </summary>
void printerClearScreen()
{
#if PLATFORM_WINDOWS
	system("cls");
#endif // PLATFORM_WINDOWS

#if PLATFORM_LINUX
	system("clear");
#endif // PLATFORM_LINUX



}
