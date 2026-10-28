#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
	EXPECT_EQ(String::strlen("foo foo"), 7);
}

TEST(StringFunction, strcpy) {
    char dest[10];
    
	const char* src1 = "Bobby";
	char* result1 = String::strcpy(dest, src1);
	EXPECT_EQ(result1, dest);
	EXPECT_STREQ(dest, src1);

	const char* src2 = "";
	String::strcpy(dest, src2);
	EXPECT_STREQ(dest, src2);
}

TEST(StringFunction, strdup) {
    const char* original = "COOKIE";
	char* duplicate  = String::strdup(original);

	EXPECT_NE(duplicate, original);

	for(int i = 0; i <= String::strlen(original); i++) {
		EXPECT_EQ(duplicate[i], original[i]);
	}

	delete[] duplicate;

	const char* empty_original = "";
	char* empty_duplicate = String::strdup(empty_original);

	EXPECT_NE(empty_duplicate, empty_original);
	EXPECT_EQ(empty_duplicate[0], '\0');

	delete[] empty_duplicate;
}

TEST(StringFunction, strncpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strcat) {
    char dest[20] = "Bobby, ";
	const char* src = "Brown";

	char* result = String::strcat(dest, src);
	EXPECT_EQ(result, dest);
	EXPECT_STREQ(dest, "Bobby, Brown");

	const char* empty_src = "";
	String::strcat(dest, empty_src);
	EXPECT_STREQ(dest, "Bobby, Brown");
}

TEST(StringFunction, strncat) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strcmp) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
