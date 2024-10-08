#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ERROR_OPENING_FILE -1
#define BUFFER_SIZE 1024
struct {
	char ime[10];
	char pezime[10];
	int	postotak;
}typedef student;

int izbroji(char* filename);

int main() {

	printf("Hello World");

	return EXIT_SUCCESS;
}
int izbroji(char* filename) {

	char buffer[BUFFER_SIZE];
	int count = 0;
	FILE* fp = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		return ERROR_OPENING_FILE;
	}

	while (!feof(fp)) {

		fgets(buffer, BUFFER_SIZE, fp);
		++count;
	}

}