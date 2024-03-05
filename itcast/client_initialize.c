#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "iniparser/iniparser.h"
#include "client_initialize.h"

#define KEYS_NUM 30

typedef enum _SCKParamNum {
    IP,
    PORT,
    CONNC_TIME,
    SEND_TIME,
    RECV_TIME,
    BOUNDS,
    SOCK_END
} SCKParamNum;

void client_socket_initialize(SCKClitPoolParam *sockpool, char *filepath) {
    dictionary *dict = NULL;
    int nsec = -1;
    int iter = 0;
    const char *secName = NULL;
    int keysNum = -1;
    const char *keyValue = NULL;
    const char *keysArr[KEYS_NUM] = {0};
    if (NULL == sockpool || NULL == filepath)
        return;

    dict = iniparser_load(filepath);
    if (NULL == dict)
        return;

    nsec = iniparser_getnsec(dict);
    if (-1 == nsec)
        return;

    for (iter = 0; iter < nsec; iter++) {
        secName = iniparser_getsecname(dict, iter);
        if (NULL == secName)
            continue;

        keysNum = iniparser_getsecnkeys(dict, secName);
        if (-1 == keysNum)
            continue;

        iniparser_getseckeys(dict, secName, keysArr);

        if (strcmp(secName, "socket") == 0 && keysNum >= SOCK_END) {
            keyValue = iniparser_getstring(dict, keysArr[IP], "127.0.0.1");
            strcpy(sockpool->serverip, keyValue);
            sockpool->serverport = iniparser_getint(dict, keysArr[PORT], 8001);
            sockpool->connecttime = iniparser_getint(dict, keysArr[CONNC_TIME], 0);
            sockpool->sendtime = iniparser_getint(dict, keysArr[SEND_TIME], 0);
            sockpool->revtime = iniparser_getint(dict, keysArr[RECV_TIME], 0);
            sockpool->bounds = iniparser_getint(dict, keysArr[BOUNDS], 1000);
        }
    }
    return;
}