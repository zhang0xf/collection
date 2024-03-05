#ifndef _TEACHER_CODE_H_
#define _TEACHER_CODE_H_

typedef enum _FreeTag {
    CHAR_TAG,
    Teacher_TAG,
    INVLID_TAG
} FreeTag;

typedef struct _Teacher {
    char name[64];
    int age;
    char sex[64];
    int stus;
    char *p;
    int pLen;
} Teacher;

int teacher_encode(Teacher *pTeacher, unsigned char **dataOut, int *dataLen);
int teacher_decode(unsigned char *dataIn, int dataLen, Teacher **pTeacher);
void write_to_file(unsigned char *DataIn, int DataLen);
int compare_teacher(Teacher *t1, Teacher *t2);
void print_teacher(Teacher *pTeacher);
void free_teacher(void **ptr, FreeTag tag);

#endif