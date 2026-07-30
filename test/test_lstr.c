#include "test_assert.h"

#include <windows.h>

static void test_lstrlen(void) {
	TEST_CHECK_EQ(0, lstrlenA(NULL));
	TEST_CHECK_EQ(0, lstrlenA(""));
	TEST_CHECK_EQ(5, lstrlenA("hello"));
	TEST_CHECK_EQ(0, lstrlenW(NULL));
	TEST_CHECK_EQ(0, lstrlenW(L""));
	TEST_CHECK_EQ(5, lstrlenW(L"hello"));
}

static void test_lstrcmp_ansi(void) {
	TEST_CHECK_EQ(0, lstrcmpA("abc", "abc"));
	TEST_CHECK(lstrcmpA("abc", "abd") < 0);
	TEST_CHECK(lstrcmpA("abd", "abc") > 0);
	TEST_CHECK(lstrcmpA("abc", "ABC") != 0);
	TEST_CHECK(lstrcmpA("abc", "abcd") < 0);

	TEST_CHECK_EQ(0, lstrcmpiA("abc", "ABC"));
	TEST_CHECK_EQ(0, lstrcmpiA("MiXeD", "mixed"));
	TEST_CHECK(lstrcmpiA("abc", "abd") < 0);
	TEST_CHECK(lstrcmpiA("abd", "ABC") > 0);
	TEST_CHECK(lstrcmpiA("abc", "abcd") < 0);
}

static void test_lstrcmp_wide(void) {
	TEST_CHECK_EQ(0, lstrcmpW(L"abc", L"abc"));
	TEST_CHECK(lstrcmpW(L"abc", L"abd") < 0);
	TEST_CHECK(lstrcmpW(L"abd", L"abc") > 0);
	TEST_CHECK(lstrcmpW(L"abc", L"ABC") != 0);
	TEST_CHECK(lstrcmpW(L"abc", L"abcd") < 0);

	TEST_CHECK_EQ(0, lstrcmpiW(L"abc", L"ABC"));
	TEST_CHECK_EQ(0, lstrcmpiW(L"MiXeD", L"mixed"));
	TEST_CHECK(lstrcmpiW(L"abc", L"abd") < 0);
	TEST_CHECK(lstrcmpiW(L"abd", L"ABC") > 0);
	TEST_CHECK(lstrcmpiW(L"abc", L"abcd") < 0);
}

int main(void) {
	test_lstrlen();
	test_lstrcmp_ansi();
	test_lstrcmp_wide();
	printf("test_lstr: all checks passed\n");
	return 0;
}
