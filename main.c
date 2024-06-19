#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define safeFree(p) saferFree((void**)&(p))

void saferFree(void **pp){
	if(pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}

char* trim(char* phrase){
	char* old = phrase;
	char* new = phrase;
	
	while(*old == ' '){
		old++;
	}
	
	while(*old){
		*(new++) = *(old++);
	}
	*new = 0;
	return (char*) realloc(phrase, strlen(phrase)+1);
}

char* getLine(void){
	const size_t sizeIncrement = 10;
	char* buffer = malloc(sizeIncrement);
	char* currentPosition = buffer;
	size_t maximumLength = sizeIncrement;
	size_t length = 0;
	int character;
	
	if(currentPosition == NULL){
		return NULL;
	}
	
	while(1){
		character = fgetc(stdin);
		if(character == '\n'){
			break;
		}
		if(++length >= maximumLength){
			char* newBuffer = realloc(buffer, maximumLength += sizeIncrement);
			
			if(newBuffer == NULL){
				safeFree(buffer);
				return NULL;
			}
			
			currentPosition = newBuffer + (currentPosition - buffer);
			buffer = newBuffer;
		}
		*currentPosition++ = character;
	}
	*currentPosition = '\0';
	return buffer;
}

void displayArray(int* arr, int size){//or array notation(int arr[], int size)
	for(int i = 0;i < size;i++){
		printf("%d\n",arr[i]);
	}
}
int main(int argc, char *argv[]) {
	int vector[5] = {1,2,3,4,5};
	char* Cptr = getLine();
	trim(Cptr);
	printf("%s\n",Cptr);
	safeFree(Cptr);
	displayArray(vector,(sizeof(vector)/sizeof(int)));
	return 0;
}
