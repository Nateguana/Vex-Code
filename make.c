#include <stdio.h>
#include <stdlib.h>
int main() {
	
	FILE* file = fopen("C:/Git/Vex - Code/src/main.cpp", "w");
	fprintf(file, "#define VERSION %d\n#include \"mains.h\"\nint main(){return mains(VERSION);}", rand());
	fclose(file);
}