/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    void *ptr = calloc(7, sizeof(int));
    void *ptr2 = calloc(7, sizeof(int));

    printf("strlen(\"oeuf\") = %d\n",       strlen("oeuf"));
    printf("strlen(\"\") = %d\n",           strlen(""));
    printf("strchr(\"oeuf\", 'u') = %s\n",  strchr("oeuf", 'a'));
    printf("strchr(\"\", 'a') = %s\n",      strchr("", 'a'));
    printf("memset(ptr, 'd', 5) = %s\n",    memset(ptr, 'd', 5));
    printf("memset(ptr, 'f', 0) = %s\n",    memset(ptr, 'f', 0));
    printf("memset(ptr, 'e', 6) = %s\n",    memset(ptr, 'e', 6));
    printf("memset(ptr, 'f', 7) = %s\n",    memset(ptr, 'f', 7));
    free(ptr);
    free(ptr2);
    ptr = calloc(7, sizeof(int));
    ptr2 = calloc(7, sizeof(int));
    printf ("ptr [%s], ptr2 [%s]\n", ptr, ptr2);
    printf("strcmp(\"abc\\0\", \"ab\\0\") = %d\n",       strcmp("abc\0", "ab\0"));
    printf("strcmp(\"ab\\0\", \"abc\\0\") = %d\n",       strcmp("ab\0", "abc\0"));
    printf("strcmp(\"Abc\\0\", \"abc\\0\") = %d\n",      strcmp("Abc\0", "abc\0"));
    printf("strcmp(ptr, ptr2) = %d\n",                   strcmp(ptr, ptr2));
    printf("strncmp(abc, ab, 2) = %d\n",                 strncmp("abc\0", "ab\0", 2));
    printf("strncmp(abc, ab, 0) = %d\n",                 strncmp("abc\0", "ab\0", 0));
    printf("strncmp(abc, ab, 0) = %d\n",                 strncmp("ab\0", "abc\0", 3));
    printf("strcasecmp(cni, dNi) = %d\n",                strcasecmp("cni\0", "dNi\0"));
    printf("strcasecmp(cni, eNi) = %d\n",                strcasecmp("cni\0", "eNi\0"));
    printf("strcasecmp(enI, enI) = %d\n",                strcasecmp("enI\0", "enI\0"));
    printf("\nmemcpy(coucou, toi, 0) = %s\n",            memcpy("coucou", "toi", 0));
    printf("strcasecmp(enI, cNi) = %d\n",                strcasecmp("enI\0", "enI\0"));
    printf("memcpy(ptr, ptr2, 7) = %s\n",                memcpy(ptr, "je t'aime", 7));
    printf("\nmemset(ptr, 'f', 7) = %s\n",               memset(ptr,  'e', 7));
    printf("memset(ptr, 'f', 7) = %s\n",                 memset(ptr2, 'f', 7));
    printf("\nmemmove(ptr, ptr2, 0) = %s\n",             memmove(ptr2, ptr, 0));
    printf("memmove(ptr, ptr2, 7) = %s\n",               memmove(ptr2, ptr, 7));
    ((char*)(ptr))[0] = 'p';
    ((char*)(ptr))[4] = 'o';
    printf("\nmemmove(ptr, ptr, 0) = %s\n",   memmove(ptr, ptr, 0));
    printf("memmove(ptr+2, ptr, 5) = %s\n",   memmove(ptr+2, ptr, 5));
    printf("memmove(ptr, ptr, 0) = %s\n",   memmove(ptr, ptr, 0));
    printf("rindex(\"42547\\0\", '5') = %s\n",  rindex("42547\0", '5'));
    printf("strstr(\"bon oeuf\", \"n o\") = %s\n",                     strstr("bon oeuf", "n o"));
    printf("strstr(\"bon oeuf\", \"oof\") = %s\n",                     strstr("bon oeuf", "oof"));
    printf("strpbrk(\"bon oeuf\", \"no\") = %s\n", strpbrk("bon oeuf", "no"));
    printf("strpbrk(\"bon oeuf\", \" \") = %s\n", strpbrk("bon oeuf", " "));
    printf("strpbrk(\"bon oeuf\", \"f\") = %s\n", strpbrk("bon oeuf", "f"));
    printf("strpbrk(\"bon oeuf\", \"x\") = %s\n", strpbrk("bon oeuf", "x"));
    printf("strcspn(\"bon oeuf\", \"x\") = %d\n", strcspn("bon oeuf", "x"));
    printf("strcspn(\"bon oeuf\", \"u\") = %d\n", strcspn("bon oeuf", "u"));
    printf("strcspn(\"bon oeuf\", \" \") = %d\n", strcspn("bon oeuf", " "));
    printf("strncasecmp(\"425\\0\", '5', 0) = %d\n",  strncasecmp("cni\0", "dNi\0", 0));
    printf("strncasecmp(\"425\\0\", '5', 5) = %d\n",  strncasecmp("cni\0", "eNi\0", 48));
    printf("strncasecmp(\"425\\0\", '5', 5) = %d\n",  strncasecmp("cnI\0", "cNe\0", 1));
    printf("strspn(\"bon oeuf\", \"bon \") = %d\n", strspn("bon oeuf", "bon \0"));
    printf("strspn(\"bon oeuf\", \"u\") = %d\n", strspn("bon oeuf", "u\0"));
    printf("strspn(\"bon oeuf\", \" \") = %d\n", strspn("bon oeuf", " \0"));
    printf("strcasestr(\"bon oeuf\", \"n o\") = %s\n", strcasestr("bon oeuf", "N O"));
    printf("strcasestr(\"bon oeuf\", \"oof\") = %s\n", strcasestr("bon oeuf", "oof"));
}

