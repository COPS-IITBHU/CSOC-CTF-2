#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "printer.hpp"

#define flag_len 28

int check_key(char* key);
void generate_data();

//char flag[]="csoc{32y_x0r_f0r_w@RM1ng_up}";

int main()
{

	char input[flag_len + 1] = { 0 };
	system("clear");
	//generate_data();
	printf("Its too cold here...z.z..z.z.zz\n");
	printf("I need to go to my room fast\n");
	printf("You are outside and your doors have been autolocked.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	printf("\nJust enter correct password in your mobile\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	printf("You password is the flag\n");
	printerPrintText("Flag: ", _text_foreground_white, _text_background_red);
	scanf("%28s", input);
	if (strlen(input) != flag_len)
	{
		printerPrintText("\n\nBad Flag Length\n", _text_foreground_white, _text_background_red);
		printf("Enjoy your...day...z.z..z.z.zz\n");
		return 0;
	}
	else
	{
		if (check_key(input))
		{
			printf("\n\nHaha..You did it \n");
			printf("Now go inside and get yoursef a Hot coffee\n");
			return 0;
		}
		else
		{
			printerPrintText("\n\nBad Flag!\n", _text_foreground_white, _text_background_red);
			printf("Go learn some basics\n");
		}
	}

}

int check_key(char* key)
{
	srand(0x1337);

	int exp = rand() % 0x20;
	const char data[] = "fvjf~67|Z}5wZc5wZrEWH4kbZpux";

	for (int i = 0; i < flag_len; i++)
	{
		if ((key[i] ^ exp) != data[i])
			return 0;
	}
	return 1;

}

/* void generate_data()
{
	srand(0x1337);

	int exp=rand() % 0x20;

	for(int i =0;i<flag_len;i++)
	{
		printf("%c",flag[i] ^ exp);
	}
	printf("\n");
	exit(0);
}


 */