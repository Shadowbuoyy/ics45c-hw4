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

int String::size() const{
	return strlen(buf);
}

bool String::operator==(String s) const{
	return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(String s) const{
	return strcmp(buf, s.buf) != 0;
}

bool String::operator<(String s) const{
	return strcmp(buf, s.buf) < 0;
}

bool String::operator>(String s) const{
	return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(String s) const{
	return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(String s) const{
	return strcmp(buf, s.buf) >= 0;
}

String String::operator+(String s) const{
	int total_len = strlen(buf) + strlen(s.buf);

	String result(total_len);

	strcpy(result.buf, buf);
	strcat(result.buf, s.buf);

	return result;
}

String &String::operator+=(String s){
	int new_len = strlen(buf) + strlen(s.buf);
	char *new_buf = new char[new_len + 1];
	strcpy(new_buf, buf);
	strcat(new_buf, s.buf);

	delete[] buf;
	buf = new_buf;

	return *this;
}

char &String::operator[](int index){
	return buf[index];
}

const char &String::operator[](int index) const{
	return buf[index];
}

void String::reverse_cpy(char *dest, const char *src){
	int len = strlen(src);
	int i = 0;
	for(; i < len; i++){
		dest[i] = src[len - 1 - i];
	}
	dest[len] = '\0';
}

const char* String::strchr(const char* str, char c){
	int i = 0;
	for(; str[i] != '\0'; i++){
		if(str[i] == c){
			return &str[i];
		}
	}

	if(c == '\0'){
		return &str[i];
	}

	return nullptr;
}

const char* String::strstr(const char *haystack, const char *needle){
	if(*needle == '\0'){
		return haystack;
	}

	for(int i = 0; haystack[i] != '\0'; i++){
		int j = 0;
		
		for(; haystack[i + j] != '\0' && needle[j] != '\0' && haystack[i + j] == needle[j]; j++){
			// Funny
		}

		if(needle[j] == '\0'){
			return &haystack[i];
		}
	}

	return nullptr;
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
