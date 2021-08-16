#pragma comment(lib, "crypt32.lib") 
#pragma comment(lib, "advapi32.lib") 

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <Wincrypt.h>

#include "printer.hpp"


#define CHUNK_SIZE 32 //must be greater than flag_size

//const char FLAG[] = "csoc{@_11ttl3_JumBl3d_p@55}";						
const char FLAG[] = "csoc{good_boi_wrong_flag}";                //satisfy the compiler
//const char KEY_CODE[] = "my_secret_code_is_undetectable";
constexpr auto FLAG_LENGTH = sizeof(FLAG);
constexpr auto KEY_LENGTH = 31;


void loadingBar(float seconds, int bars);
bool key_check(char* pass);
void encrypt_pass(char*);
void decrypt_pass(char*);
void wrong_key();
void wrong_length();
void correct_key(char*);

void main()
{
	char input[KEY_LENGTH];
	char buffer[32];
	
	loadingBar(5, 20);
	
	printf("\n\t\t\t\t\t");
	printerPrintText("Welcome to CSOC CryptoWorld\n", _text_foreground_white, _text_background_red);
	printf("\n\n");
	printerSlowPrint("We have located a hidden file inside this program.", 55);
	printerSlowPrint("\n", 400);
	printerSlowPrint("Starting Decrypting the file......\n\n", 35);

	printerFormatText(buffer, "\n\nHALT Soldier!!\n\n", _text_foreground_red, _text_background_default, _text_style_underline);
	printerSlowPrint(buffer, 30);
	printerSlowPrint("This file requires a hidden ");
	printerFormatText(buffer, "secret key\n\n", _text_foreground_black, _text_background_white);
	printerSlowPrint(buffer,40);

	printf("Enter the Secret Key : ");
	scanf_s("%30s", input, 31);
	int len = strnlen(input, 30);

	if (len != 30)
		wrong_length();
	else
	{
		if (key_check(input))
			correct_key(input);
		else
			wrong_key();
	}

	getch();
}


void loadingBar(float seconds, int bars)
{
	//Credits : https://www.geeksforgeeks.org/how-to-create-a-command-line-progress-bar-in-c-c/


	// 0 - black background,
	// A - Green Foreground
	system("color 0A");

	// Initialize char for printing loading bar
	char a = 177, b = 219;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t\t");
	printf("Loading...\n\n");
	printf("\n\t\t\t\t\t  ");

	// Print initial loading bar
	for (int i = 0; i < bars; i++)
		printf("%c", a);

	// Set the cursor again starting
	// point of loading bar
	printf("\r");
	printf("\t\t\t\t\t  ");

	float delay = seconds / bars;
	// Print loading bar progress
	for (int i = 0; i < bars; i++) {
		printf("%c", b);
		Sleep(delay * 1000);
	}

	printerClearScreen();
	//reset back to default color
	system("color 0F");
}
bool key_check(char* pass)
{
	//"my_secret_code_is_undetectable"

	if (pass[15] != 'i')
		return false;
	if (pass[16] != 's')
		return false;
	if (pass[17] != '_')
		return false;
	if (pass[18] != 'u')
		return false;
	if (pass[19] != 'n')
		return false;
	if (pass[20] != 'd')
		return false;

	if (pass[0] != 'm')
		return false;
	if (pass[1] != 'y')
		return false;

	if (pass[5] != 'c')
		return false;
	if (pass[6] != 'r')
		return false;
	if (pass[7] != 'e')
		return false;
	if (pass[8] != 't')
		return false;
	if (pass[9] != '_')
		return false;

	if (pass[10] != 'c')
		return false;
	if (pass[21] != 'e')
		return false;
	if (pass[22] != 't')
		return false;
	if (pass[23] != 'e')
		return false;
	if (pass[24] != 'c')
		return false;
	if (pass[25] != 't')
		return false;

	if (pass[11] != 'o')
		return false;
	if (pass[12] != 'd')
		return false;
	if (pass[13] != 'e')
		return false;
	if (pass[14] != '_')
		return false;

	if (pass[2] != '_')
		return false;
	if (pass[3] != 's')
		return false;
	if (pass[4] != 'e')
		return false;

	if (pass[29] != 'e')
		return false;

	if (pass[26] != 'a')
		return false;
	if (pass[27] != 'b')
		return false;
	if (pass[28] != 'l')
		return false;


	return true;
}
void encrypt_pass(char* input)
{
	HCRYPTPROV phProv;
	HCRYPTKEY phKey;
	HCRYPTHASH phHash;

	//int len = strlen(input);
	if (!CryptAcquireContextW(&phProv, 0, L"Microsoft Enhanced RSA and AES Cryptographic Provider", PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
		printf("failed at CryptAcquireContextW ....\n");
	if (!CryptCreateHash(phProv, CALG_SHA_256, 0, 0, &phHash))
		printf("failed at CryptCreateHash ....\n");
	if (!CryptHashData(phHash, (const BYTE*)input, KEY_LENGTH, 0))
		printf("failed at CryptHashData ....\n");
	if (!CryptDeriveKey(phProv, CALG_AES_128, phHash, 0, &phKey))
		printf("failed at CryptDeriveKey ....\n");


	///Note that, depending on the algorithm used, the encrypted text can be larger than the original plaintext. 
	//In this case, the pbData buffer needs to be large enough to contain the encrypted text and any padding.

	char pbData[CHUNK_SIZE];
	DWORD pdwDataLen = FLAG_LENGTH;
	ZeroMemory(pbData, CHUNK_SIZE);
	memcpy(pbData, FLAG, FLAG_LENGTH);

	if (!CryptEncrypt(phKey, 0i64, true, 0, (BYTE*)pbData, &pdwDataLen, CHUNK_SIZE))
		printf("failed at CryptEncrypt ....\n");

	for (int i = 0; i < pdwDataLen; i++)
		printf("0x%02X,", pbData[i]);
	printf("\n");

	//encrypted flag
	//pbData-> { 0x4B,0x17,0xFFFFFFB4,0x18,0x60,0x0E,0xFFFFFFA3,0xFFFFFFDA,0x46,0xFFFFFFCA,0xFFFFFFCF,
	//		0xFFFFFFD0, 0xFFFFFFF5, 0x3C, 0x1C, 0x4C, 0x6F, 0xFFFFFF82, 0xFFFFFF82, 0x0F, 0x59, 0x25,
	//		0xFFFFFFC2, 0xFFFFFFF2, 0x25, 0x75, 0xFFFFFFEB, 0xFFFFFFFE, 0x0D, 0x0A, 0x2C, 0xFFFFFFF8 };



	CryptReleaseContext(phProv, 0);
	CryptDestroyKey(phKey);
	CryptDestroyHash(phHash);

}
void decrypt_pass(char* input)
{
	HCRYPTPROV phProv;
	HCRYPTKEY phKey;
	HCRYPTHASH phHash;

	if (!CryptAcquireContextW(&phProv, 0, L"Microsoft Enhanced RSA and AES Cryptographic Provider", PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
		printf("failed at CryptAcquireContextW ....\n");
	if (!CryptCreateHash(phProv, CALG_SHA_256, 0, 0, &phHash))
		printf("failed at CryptCreateHash ....\n");
	if (!CryptHashData(phHash, (const BYTE*)input, KEY_LENGTH, 0))
		printf("failed at CryptHashData ....\n");
	if (!CryptDeriveKey(phProv, CALG_AES_128, phHash, 0, &phKey))
		printf("failed at CryptDeriveKey ....\n");


	char pbData[] = { 0x4B,0x17,0xFFFFFFB4,0x18,0x60,0x0E,0xFFFFFFA3,0xFFFFFFDA,0x46,0xFFFFFFCA,0xFFFFFFCF,
			0xFFFFFFD0,0xFFFFFFF5,0x3C,0x1C,0x4C,0x6F,0xFFFFFF82,0xFFFFFF82,0x0F,0x59,0x25,
			0xFFFFFFC2,0xFFFFFFF2,0x25,0x75,0xFFFFFFEB,0xFFFFFFFE,0x0D,0x0A,0x2C,0xFFFFFFF8 };

	DWORD pdwDataLen = sizeof(pbData);

	if (!CryptDecrypt(phKey, 0, true, 0, (BYTE*)pbData, &pdwDataLen))
		printf("failed at CryptDecrypt.... %d \n", pdwDataLen);

	printf("yeeeboi!\nHeres your reward : ");
	for (int i = 0; i < pdwDataLen; i++)
		printf("%c", pbData[i]);
	printf("\n");



	CryptReleaseContext(phProv, 0);
	CryptDestroyKey(phKey);
	CryptDestroyHash(phHash);
}
void wrong_key()
{
	char buffer[32];
	printerFormatText(buffer, "\n\nSorry!\n\n", _text_foreground_red, _text_background_default, _text_style_underline);
	printerSlowPrint(buffer, 30);
	printerSlowPrint("Wrong Key...\nPlease try again");
}
void wrong_length()
{
	char buffer[32];
	printerFormatText(buffer, "\n\nSorry!\n\n", _text_foreground_red, _text_background_default, _text_style_underline);
	printerSlowPrint(buffer, 30);
	printerSlowPrint("Wrong Length of of Key");
}
void correct_key(char* input)
{
	char buffer[32];
	printerFormatText(buffer, "\n\nSuccess!\n\n", _text_foreground_green, _text_background_default, _text_style_underline);
	printerSlowPrint(buffer, 20);
	printerSlowPrint("Starting Decrypting the password......\n", 20);

	decrypt_pass(input);
}