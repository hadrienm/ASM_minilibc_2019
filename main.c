/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strstr(const char *__haystack, const char *__needle);

void strcmp_test()
{
    int cmp = strcmp("abc\0", "ab\0");

    printf("Test on strcmp function: \n");
    if (cmp == 1) {
        printf("\tstrcmp(\"abc\\0\", \"ab\\0\"): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcmp(\"abc\", \"ab\"): \033[0;31mFail test => got : %d, excepted : 1\033[0;37m\n", cmp);
    }
    cmp = strcmp("ab\0", "abc\0");
    if (cmp == -1) {
        printf("\tstrcmp(\"ab\\0\", \"abc\\0\"): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcmp(\"ab\\0\", \"abc\\0\"): \033[0;31mFail test => got : %d, excepted : -1\033[0;37m\n", cmp);
    }
    cmp = strcmp("Abc\0", "abc\0");
    if (cmp == -1) {
        printf("\tstrcmp(\"Abc\\0\", \"abc\\0\"): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcmp(\"Abc\\0\", \"abc\\0\"): \033[0;31mFail test => got : %d, excepted : -1\033[0;37m\n", cmp);
    }
}

void strncmp_test()
{
    int cmp = strncmp("abc\0", "ab\0", 2);

    printf("\nTest on strncmp function: \n");
    if (cmp == 0) {
        printf("\tstrncmp(abc, ab, 2): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrncmp(abc, ab, 2): \033[0;31mFail test => got : %d, excepted : 0\033[0;37m\n", cmp);
    }
    cmp = strncmp("abc\0", "ab\0", 0);
    if (cmp == 0) {
        printf("\tstrncmp(abc, ab, 0): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrncmp(abc, ab, 0): \033[0;31mFail test => got : %d, excepted : 0\033[0;37m\n", cmp);
    }
    cmp =  strncmp("ab\0", "abc\0", 3);
    if (cmp == -1) {
        printf("\tstrncmp(abc, ab, 3): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrncmp(abc, ab, 3): \033[0;31mFail test => got : %d, excepted : -1\033[0;37m\n", cmp);
    }
}

void strcasecmp_test()
{
    int cmp = strcasecmp("cni\0", "dNi\0");

    printf("\nTest on strcasecmp function: \n");
    if (cmp == -1) {
        printf("\tstrcasecmp(cni, dNi): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcasecmp(cni, dNi): \033[0;31mFail test => got : %d, excepted : -1\033[0;37m\n", cmp);
    }
    cmp = strcasecmp("cni\0", "eNi\0");
    if (cmp == -1) {
        printf("\tstrcasecmp(cni, eNi): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcasecmp(cni, eNi): \033[0;31mFail test => got : %d, excepted : -1\033[0;37m\n", cmp);
    }
    cmp = strcasecmp("enI\0", "enI\0");
    if (cmp == 0) {
        printf("\tstrcasecmp(enI, enI): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcasecmp(enI, enI): \033[0;31mFail test => got : %d, excepted : 0\033[0;37m\n", cmp);
    }
    cmp = strcasecmp("enI\0", "eNi\0");
    if (cmp == 0) {
        printf("\tstrcasecmp(enI, eNi): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tstrcasecmp(enI, eNi): \033[0;31mFail test => got : %d, excepted : 0\033[0;37m\n", cmp);
    }
}

void strlen_test()
{
    int size = 0;

    printf("\nTest on strlen function: \n");
    size = strlen("oeuf");
    if (size == 4)
        printf("\tstrlen(\"oeuf\") : \033[0;32mSuccessful test\033[0;37m\n");
    else
        printf("\tstrlen(\"oeuf\") : \033[0;31mFail test => got : %d, excepted : 4\033[0;37m\n", size);
    size = strlen("");
    if (size == 0)
        printf("\tstrlen(\"\") : \033[0;32mSuccessful test\033[0;37m\n");
    else
        printf("\tstrlen(\"\") : \033[0;31mFail test => got : %d, excepted : 0\033[0;37m\n", size);
}

void strchr_test()
{
    char *ptr = strchr("oeuf", 'a');

    printf("\nTest on strchr function: \n");
    if (ptr == NULL)
        printf("\tstrchr(\"oeuf\", 'a'): \033[0;32mSuccessful test\033[0;37m\n");
    else
        printf("\tstrchr(\"oeuf\", 'a) : \033[0;31mFail test => got : %s, excepted : null\033[0;37m\n", ptr);
    ptr = strchr("", 'a');
    if (ptr == NULL)
        printf("\tstrchr(\"\", 'a'): \033[0;32mSuccessful test\033[0;37m\n");
    else
        printf("\tstrchr(\"\", 'a') : \033[0;31mFail test => got : %s, excepted : null\033[0;37m\n", ptr);
    free(ptr);
}

void memset_test()
{
    void *ptr = calloc(7, sizeof(int));

    printf("\nTest on memset function: \n");
    ptr = memset(ptr, 'd', 5);
    if (strcmp(ptr, "ddddd") == 0) {
        printf("\tmemset(ptr, 'd', 5): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemset(\"ptr\", 'd'): \033[0;31mFail test => got : [%s], excepted : ddddd\033[0;37m\n", ptr);
    }
    ptr = memset(ptr, 'f', 0);
    if (strcmp(ptr, "ddddd") == 0) {
        printf("\tmemset(ptr, 'f', 0): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemset(\"ptr\", 'f', 0): \033[0;31mFail test => got : [%s], excepted : ddddd\033[0;37m\n", ptr);
    }
    ptr = memset(ptr, 'e', 6);
    if (strcmp(ptr, "eeeeee") == 0) {
        printf("\tmemset(ptr, 'e', 6): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemset(ptr, 'e', 6): \033[0;31mFail test => got : [%s], excepted : eeee\033[0;37m\n", ptr);

    }
    ptr =  memset(ptr, 'f', 7);
    if (strcmp(ptr, "fffffff") == 0) {
        printf("\tmemset(ptr, 'f', 7): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemset(ptr, 'f', 7): \033[0;31mFail test => got : [%s], excepted : fffffff\033[0;37m\n", ptr);
    }
    free(ptr);
}

void memcpy_test()
{
    void *ptr = memcpy("coucou", "toi", 0);

    printf("\nTest on memcpy_test function:\n");
    if (strcmp(ptr, "coucou") == 0) {
        printf("\tmemcpy(\"coucou\", \"toi\", 0): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemcpy(\"coucou\", \"toi\", 0): \033[0;31mFail test => got : [%s], excepted : coucou\033[0;37m\n", ptr);
    }
    ptr = calloc(7, sizeof(int));
    ptr = memcpy(ptr, "je t'aime", 7);
    if (strcmp(ptr, "je t'ai") == 0) {
        printf("\tmemcpy(\"\", \"je t'aime\", 7): \033[0;32mSuccessful test\033[0;37m\n");
    } else {
        printf("\tmemcpy(\"\", \"je t'aime\", 7): \033[0;31mFail test => got : [%s], excepted : je t'ai\033[0;37m\n", ptr);
    }
}

int main(void)
{
    void *ptr = calloc(7, sizeof(int));
    void *ptr2 = calloc(7, sizeof(int));

    strcmp_test();
    strncmp_test();
    strcasecmp_test();
    strlen_test();
    strchr_test();
    memset_test();
    memcpy_test();
    printf("\nmemset(ptr, 'f', 7) = %s\n", memset(ptr, 'e', 7));
    printf("memset(ptr, 'f', 7) = %s\n", memset(ptr2, 'f', 7));
    printf("\nmemmove(ptr, ptr2, 0) = %s\n", memmove(ptr2, ptr, 0));
    printf("memmove(ptr, ptr2, 7) = %s\n", memmove(ptr2, ptr, 7));
    ((char *)(ptr))[0] = 'p';
    ((char *)(ptr))[4] = 'o';
    printf("\nmemmove(ptr, ptr, 0) = %s\n", memmove(ptr, ptr, 0));
    printf("memmove(ptr+2, ptr, 5) = %s\n", memmove(ptr + 2, ptr, 5));
    printf("memmove(ptr, ptr, 0) = %s\n", memmove(ptr, ptr, 0));
    printf("rindex(\"42547\\0\", '5') = %s\n", rindex("42547\0", '5'));
    printf("strpbrk(\"bon oeuf\", \"no\") = %s\n", strpbrk("bon oeuf", "no"));
    printf("strpbrk(\"bon oeuf\", \" \") = %s\n", strpbrk("bon oeuf", " "));
    printf("strpbrk(\"bon oeuf\", \"f\") = %s\n", strpbrk("bon oeuf", "f"));
    printf("strpbrk(\"bon oeuf\", \"x\") = %s\n", strpbrk("bon oeuf", "x"));
    printf("strpbrk(\"bon oeuf\", \"b\") = %s\n", strpbrk("bon oeuf", "b"));
    printf("strpbrk(\"bon oeuf\", \"ob\") = %s\n", strpbrk("bon oeuf", "ob"));
    printf("strcspn(\"bon oeuf\", \"x\") = %d\n", strcspn("bon oeuf", "x"));
    printf("strcspn(\"bon oeuf\", \"u\") = %d\n", strcspn("bon oeuf", "u"));
    printf("strcspn(\"bon oeuf\", \" \") = %d\n", strcspn("bon oeuf", " "));
    printf("strcspn(\"bon oeuf\", \"b\") = %d\n", strcspn("bon oeuf", "b"));
    printf("strcspn(\"bon oeuf\", \"o\") = %d\n", strcspn("bon oeuf", "o"));
    printf("strstr(\"bon oeuf\", \"bo\") = %s\n", strstr("bon oeuf", "bo"));
    printf("strstr(\"bon oeuf\", \"n o\") = %s\n", strstr("bon oeuf", "n o"));
    printf("strstr(\"bon oeuf\", \"oof\") = %s\n", strstr("bon oeuf", "oof"));
}
