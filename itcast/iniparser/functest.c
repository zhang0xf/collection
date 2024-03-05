#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef linux
#include <unistd.h>
#endif // linux
#include "iniparser.h"

#define MAX_LEN 1024
#define CONFIG "config.ini"
#define DUMP_SECTION "dump/dumpsection"
#define DUMP_FILE "dump/dumpall.txt"

void iniparser_test() {
    int iter = 0;
    int jter = 0;
    int port = -1;
    int KeyNums = 0;

    char filepath[MAX_LEN] = {0};
    char sectionNum[MAX_LEN] = {0};
    const char *keyArr[MAX_LEN] = {0};

    const char *SectionName = NULL;
    const char *keyValue = NULL;

    FILE *fp = NULL;
    dictionary *dict = NULL;

    dict = iniparser_load(CONFIG);
    if (NULL == dict)
        return;

    int nsecNum = iniparser_getnsec(dict);
    printf("[section]的数量 = %d\n", nsecNum);

    for (iter = 0; iter < nsecNum; iter++) {
        SectionName = iniparser_getsecname(dict, iter);
        if (NULL == SectionName)
            return;
        printf("[section]的序号 = %d, [section]的名字 = %s\n", iter, SectionName);

        KeyNums = iniparser_getsecnkeys(dict, SectionName);
        printf("[%s] has %d keys\n", SectionName, KeyNums);

        if (iniparser_find_entry(dict, SectionName))
            printf("has [section] : %s!\n", SectionName);
        else
            printf("no [section] : %s!\n", SectionName);

        iniparser_getseckeys(dict, SectionName, keyArr);

        memset(filepath, 0, MAX_LEN);
        strcat(filepath, DUMP_SECTION);
        sprintf(sectionNum, "%d", iter);
        strcat(filepath, sectionNum);
        strcat(filepath, ".txt");
        fp = fopen(filepath, "w");
        if (NULL == fp)
            return;
        iniparser_dumpsection_ini(dict, SectionName, fp);
        fclose(fp);

        for (jter = 0; jter < MAX_LEN; jter++) {
            if (NULL == keyArr[jter])
                continue;
            keyValue = iniparser_getstring(dict, keyArr[jter], "Nothing");
            if (NULL == keyValue)
                continue;
            printf("key[%s] = value[%s]\n", keyArr[jter], keyValue);
        }
    }

    memset(filepath, 0, MAX_LEN);
    strcat(filepath, DUMP_FILE);
    fp = fopen(filepath, "w");
    if (NULL == fp)
        return;
    iniparser_dump_ini(dict, fp);
    fclose(fp);

    keyValue = iniparser_getstring(dict, "server:ip", "Nothing");
    if (keyValue)
        printf("key[server:ip] => value[%s]\n", keyValue);
    else
        printf("key[server:ip] => value[%s]\n", "NO value");

    keyValue = iniparser_getstring(dict, ":name", "Nothing");
    if (keyValue)
        printf("key[:name] value[%s]\n", keyValue);
    else
        printf("key[:name] value[%s]\n", "NO value");

    port = iniparser_getint(dict, "server:port", -1);
    if (-1 != port)
        printf("key[server:port] value[%d]\n", port);
    else
        printf("key[server:port] value[%s]\n", "NO value");

    iniparser_freedict(dict);
    return;
}

int main(int argc, char *argv[]) {
    iniparser_test();
    return 0;
}