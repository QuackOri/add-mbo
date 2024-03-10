//main.cpp
#include <cstdint>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc != 3){
		printf("Usage: ./add-nbo <file1> <file2>");
		return 0;
	}

	const char* fileNameA = argv[1];
	const char* fileNameB = argv[2];

	FILE* pFileA = fopen(fileNameA, "rb");
	if (!pFileA){
		perror("FileA");
		exit(EXIT_FAILURE);
	}

	FILE* pFileB = fopen(fileNameB, "rb");
	if (!pFileB){
		perror("FileB");
		fclose(pFileA);
		exit(EXIT_FAILURE);
	}

	uint32_t numberA;
	uint32_t numberB;

	fread(&numberA, sizeof(unsigned int), 1, pFileA);
	fread(&numberB, sizeof(unsigned int), 1, pFileB);

	numberA = htonl(numberA);
	numberB = htonl(numberB);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", numberA, numberA, numberB, numberB, numberA+numberB, numberA+numberB);

	fclose(pFileA);
	fclose(pFileB);
}
