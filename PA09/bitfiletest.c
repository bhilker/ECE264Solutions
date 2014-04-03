#include <stdio.h>
#include <stdlib.h>

typedef struct {
	FILE *fp;
	unsigned char byte;
	int position;
}BitFile;

BitFile *BitFile_create(FILE *fp)
{
	BitFile *bitfile=malloc(sizeof(BitFile));
	bitfile->fp=fp;
	bitfile->byte=0;
	bitfile->position=8;
	return bitfile;
}

void BitFile_destroy(BitFile *bitfile)
{
	free(bitfile);
}

int BitFile_nextBit(BitFile *bitfile)
{
	if(bitfile->position==8)
	{
		bitfile->position=0;
		if(fread(&(bitfile->byte),sizeof(unsigned char),1,bitfile->fp) != 1) return -1;
	}
	int val= ((bitfile->byte)>>(7-(bitfile->position)))&0x01;
	bitfile->position++;
	printf("Value of bit: %d\n",val);
	return val;
}

int BitFile_nextByte(BitFile *bf)
{
	int ret=0;
	int pos;
	for(pos=0;pos<8;pos++)
	{
		int bit=BitFile_nextBit(bf);
		if(bit<0) return -1;
		ret=ret | (bit<<(7-pos));
	}
	return ret;
}


int main(int argc, char **argv)
{
	FILE *test=fopen("02-godfather.txt-huff","rb");
	unsigned char holdit;
	BitFile *bf=BitFile_create(test);
	holdit=BitFile_nextByte(bf);
	printf("%02x\n",holdit);
	BitFile_destroy(bf);;
	fclose(test);
	return 0;
}
