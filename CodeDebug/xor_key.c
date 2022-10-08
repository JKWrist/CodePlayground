#include <stdio.h>
#include <stdlib.h>
//#ifdef XOR_ENCRYPT

const char XOR_KEY[] = "tecomtec";
void xor_encrypt(char *inputfile, char *outputfile)
{
	FILE *input  = fopen(inputfile, "rb");
	FILE *output = fopen(outputfile, "wb");

	if(input != NULL && output != NULL) {
		unsigned char buffer[4096];
		size_t count, i, j = 0;
		do {
			count = fread(buffer, sizeof *buffer, sizeof buffer, input);
			for(i = 0; i<count; ++i) {
				buffer[i] ^= XOR_KEY[j++];
				if(XOR_KEY[j] == '\0')
					j = 0; /* restart at the beginning of the key */
			}
			fwrite(buffer, sizeof *buffer, count, output);
		} while (count == sizeof buffer);
		fclose(input);
		fclose(output);
	}
}

int main()
{
	xor_encrypt("normal.xml", "normal_1.xml");
    return 0;
}
