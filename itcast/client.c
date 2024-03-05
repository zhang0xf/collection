#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socket/poolsocket.h"
#include "asn1/teacher/teacher_code.h"
#include "client_initialize.h"

#define MAX_LEN 100
#define INI_PATH "client.ini"

void client_send_teacher() {
    int ret = 0;
    int cfd = -1;
    void *handle = NULL;
    char *dataout = NULL; // 接受数据
    int dataoutlen = 0;
    unsigned char *datain = NULL; // 发送数据
    int datainLen = 0;
    SCKClitPoolParam sockpool;
    memset(&sockpool, 0, sizeof(SCKClitPoolParam));

    client_socket_initialize(&sockpool, INI_PATH);

    ret = sckCltPool_init(&handle, &sockpool);
    if (ret != Sck_Ok) {
        printf("client can not create socket pool ... \n");
        return;
    } else
        printf("client socket pool created down ...\n");

    ret = sckCltPool_getConnet(handle, &cfd);
    if (ret != Sck_Ok)
        return;

    Teacher teacher;
    teacher.age = 30;
    teacher.stus = 60;
    strcpy(teacher.name, "bigmax");
    strcpy(teacher.sex, "man");
    teacher.p = NULL;
    teacher.p = (char *)malloc(64);
    memset(teacher.p, 0, 64);
    if (teacher.p)
        strcpy(teacher.p, "hello world");
    teacher.pLen = strlen(teacher.p);
    teacher_encode(&teacher, &datain, &datainLen);

    ret = sckCltPool_send(handle, cfd, (unsigned char *)datain, datainLen);
    if (ret != Sck_Ok)
        return;

    ret = sckCltPool_rev(handle, cfd, (unsigned char **)&dataout, &dataoutlen);
    if (ret != Sck_Ok)
        return;

    if (dataout && dataoutlen > 0)
        printf("so happy to get your message server: \"%s\"", (char *)dataout);

    ret = sckCltPool_putConnet(handle, cfd, 1);
    if (ret != Sck_Ok)
        return;

    sckCltPool_destroy(handle);

    free(dataout);

    return;
}

int main(int argc, char *argv[]) {
    client_send_teacher();
    return 0;
}