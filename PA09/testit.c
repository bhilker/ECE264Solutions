#include "answer09.h"
#include "treefun.h"

int main(int argc, char **argv)
{
	printf("\nInitializing...");
	FILE *fp=fopen("02-godfather.txt-huff","rb");
	FILE *fpbp=fopen("08-gophers.bit-huff","rb");
	FILE *tester=fopen("readthis.txt","w");
	FILE *tester2=fopen("readthistoo.txt","w");
	HuffNode *test=HuffTree_readTextHeader(fp);
	HuffNode_print(tester,test);
	printf("\nFinished Text, Now hitting binary...");
	test=HuffTree_readBinaryHeader(fpbp);
	HuffNode_printPretty(tester2,test);
	printf("\nFinished.\n");
	

	fclose(fp);
	fclose(fpbp);
	fclose(tester);
	fclose(tester2);
	return 0;
}
