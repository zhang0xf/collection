#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef linux
#include <unistd.h>
#endif // linux
#include "itcastderlog.h"
#include "teacher/teacher_code.h"

void teacher_encode_test() {
    int OutDataLen = 0;
    Teacher *pTeacher = NULL;
    unsigned char *OutData = NULL;

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

    teacher_encode(&teacher, &OutData, &OutDataLen);
    write_to_file(OutData, OutDataLen);
    teacher_decode(OutData, OutDataLen, &pTeacher);

    // 比较结构体是否相等：
    if (compare_teacher(&teacher, pTeacher) == 0)
        printf("code sucess!\n");
    else
        printf("code failure!\n");
}

int main() {
    teacher_encode_test();
    return 0;
}