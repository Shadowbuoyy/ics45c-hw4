#include <iostream>
#include <utility>
#include "string.hpp"

using namespace std;

String::String(const char* s){
	buf = strdup(s ? s: "");
}

String::String(const String& s){
	buf = strdup(s.buf);
}

String::String(int length){
	buf = new char[length + 1];
}

String::~String(){
	delete[] buf;
}

String &String::operator=(String s){
	swap(s);

	return *this;
}

void String::swap(String &s){
	std::swap(buf, s.buf);
}

char* String::strncat(char *dest, const char *src, int n){
	int dest_len = strlen(dest);
	int i = 0;

	for(; i < n && src[i] != '\0'; i++){
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return dest;
}

char* String::strcat(char *dest, const char* src){
	int dest_len = strlen(dest);
	int i = 0;
	for(; src[i] != '\0'; i++){
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';
	
	return dest;
}

int String::strcmp(const char* left, const char *right){
	int i = 0;
	for(;  left[i] != '\0' && right[i] != '\0' && left[i] == right[i]; i++){
		// Funny	
	}

	return left[i] - right[i];
}

int String::strncmp(const char* left, const char* right, int n){
	if(n == 0){
		return 0;
	}
	int i = 0;
	for(; i < n - 1 && left[i] != '\0' && right[i] != '\0' && left[i] == right[i]; i++){
		// Funny
	}

	return left[i] - right[i];
}

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

char* String::strncpy(char* dest, const char* src, int n){
	int i = 0;
	for(; i < n && src[i] != '\0'; i++){
		dest[i] = src[i];
	}

	for(; i < n; i++){
		dest[i] = '\0';
	}

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
