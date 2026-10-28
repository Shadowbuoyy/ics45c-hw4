#include <iostream>
#include <utility>
#include "string.hpp"

using namespace std;

int String::strlen(const char* s){
	int len = 0;
	for(; s[len] != '\0'; len++){
		// Funny
	}

	return len;
}

char* String::strcpy(char *dest, const char* src){
	int i = 0;
	for(; src[i] != '\0'; i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	
	return dest;
}


char * String::strdup(const char* src){
	if(src == nullptr) {
		return nullptr;
	}
	int src_length = strlen(src);
	char* dest = new char[src_length + 1];
	strcpy(dest, src);

	return dest;
}
