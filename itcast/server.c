#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef linux
#include <unistd.h>
#endif // linux
#include "server_initialize.h"
#include "teacher_code.h"

#define MAX_LEN 1024
#define DEFAULT_LEN 1024
#define INI_PATH "server.ini"

void server_recv_teacher() {
    int lfd = -1;
    int cfd = -1;
    int ret = 0;
    int outlen = 0;
    char *datain = "hey, cute client! i have received your message ...";
    int inlen = strlen(datain);
    char *dataout = NULL;
    SCKClitPoolParam sockpool;
    memset(&sockpool, 0, sizeof(SCKClitPoolParam));
    Teacher *pTeacher = NULL;

    server_socket_initialize(&sockpool, INI_PATH);

    ret = sckServer_init(sockpool.serverport, &lfd);
    if (Sck_Ok != ret)
        return;

    printf("server begin accept ... \n");

    ret = sckServer_accept(lfd, sockpool.connecttime, &cfd);
    if (ret != Sck_Ok)
        return;

    if (cfd)
        printf("server has connected to one client .. \n");

    ret = sckServer_rev(cfd, sockpool.revtime, (unsigned char **)&dataout, &outlen);
    if (ret != Sck_Ok)
        return;

    if (dataout && outlen > 0) {
        printf("client message: \"%s\"\n", (char *)dataout);
        teacher_decode((unsigned char *)dataout, outlen, &pTeacher);
        print_teacher(pTeacher);
    }

    ret = sckServer_send(cfd, sockpool.sendtime, (unsigned char *)datain, inlen);
    if (ret != Sck_Ok)
        return;

    printf("message to client has been sended!\n");

    sckServer_close(cfd);
    sckServer_close(lfd);
    sckServer_destroy();
    return;
}

int main(int argc, char *argv[]) {
    server_recv_teacher();
    return 0;
}
