#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

#define LIM 255

char *read(char filename[]){
	FILE *src = fopen(filename, "r");
	if(src == NULL) return 0;
	//if file exists, initialize char buffer and read a file
	int len = 0;
	char *buffer = malloc(LIM), c;
	while((c = fgetc(src)) != EOF) buffer[len] = c, len++;
	char *source = malloc(len);
	for(int i = 0; i < len; i++) source[i] = buffer[i];
	//finalize
	free(buffer);
	fclose(src);
	return source;
}

int main(){
	printf("pixlaunch v1.0.0 (build10000)\npixleb, 2022\n\n");
	
	//entering if debug mode is on
	char *is_debug = read("./pixlaunch/debug.ini"), debug = is_debug[0]-48; //atoi()? what's that?
	free(is_debug);
	
	if(debug) printf("INFO: debug mode is on.\nYou can switch it off by changing value in ./pixlaunch/debug.ini to 0.\n\n");
	setlocale(LC_ALL, "");
	
	//getting greet text from file
	printf("%s\n", read("./pixlaunch/greet.ini"));
	
	//finalize
	system("start \"\" \"%cd%\"/index.html\"");
	printf("Press enter to exit...");
	getchar();
}

