#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../itcastderlog.h"
#include "../itcast_asn1_der.h"
#include "teacher_code.h"

#define MAX_LEN 1024
#define _DCODE_OUT_FILE_NAME_ "teacher.ber"

int teacher_encode(Teacher *pTeacher, unsigned char **dataOut, int *dataLen) {
    ITCAST_INT ret = ITDER_NoErr;
    ITASN1_PRINTABLESTRING *pHeader = NULL;
    ITCAST_ANYBUF *pCurrent = NULL;
    ITASN1_INTEGER *pTempBuf = NULL;
    ITASN1_INTEGER *pOutBuf = NULL;
    ITCAST_UINT8 *_Temp = NULL;
    ITCAST_INT TempLen = 0;

    if (NULL == pTeacher || NULL == dataOut || NULL == dataLen)
        return -1;

    // 编码name:
    ret = DER_ITCAST_String_To_AnyBuf(&pTempBuf, (unsigned char *)pTeacher->name, strlen(pTeacher->name));
    if (ret != ITDER_NoErr) {
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ITCAST_String_To_AnyBuf() error !");
        return ret;
    }

    ret = DER_ItAsn1_WritePrintableString(pTempBuf, &pHeader);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pTempBuf);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WritePrintableString() error !");
        return ret;
    }
    DER_ITCAST_FreeQueue(pTempBuf);

    pCurrent = pHeader;

    // 编码age:
    ret = DER_ItAsn1_WriteInteger(pTeacher->age, &pCurrent->next);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WriteInteger() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 编码sex:
    ret = DER_ITCAST_String_To_AnyBuf(&pTempBuf, (unsigned char *)pTeacher->sex, strlen(pTeacher->sex));
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ITCAST_String_To_AnyBuf() error !");
        return ret;
    }

    ret = DER_ItAsn1_WritePrintableString(pTempBuf, &pCurrent->next);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WritePrintableString() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 编码stus:
    ret = DER_ItAsn1_WriteInteger(pTeacher->stus, &pCurrent->next);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WriteInteger() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 编码p
    ret = EncodeChar(pTeacher->p, pTeacher->pLen, &pCurrent->next);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func EncodeChar() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 编码pLen
    ret = DER_ItAsn1_WriteInteger(pTeacher->pLen, &pCurrent->next);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WriteInteger() error !");
        return ret;
    }

    // 编码链表
    ret = DER_ItAsn1_WriteSequence(pHeader, &pOutBuf);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_WriteSequence() error !");
        return ret;
    }
    DER_ITCAST_FreeQueue(pHeader);

    _Temp = (unsigned char *)malloc(pOutBuf->dataLen);
    if (NULL == _Temp) {
        ret = ITDER_MemoryErr;
        DER_ITCAST_FreeQueue(pOutBuf);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func malloc() error !");
        return ret;
    }
    memcpy(_Temp, pOutBuf->pData, pOutBuf->dataLen);
    TempLen = pOutBuf->dataLen;

    // 释放节点：
    DER_ITCAST_FreeQueue(pOutBuf);

    *dataOut = _Temp;
    *dataLen = TempLen;

    return ret;
}

int teacher_decode(unsigned char *dataIn, int dataLen, Teacher **pTeacher) {
    ITCAST_INT ret = ITDER_NoErr;
    ITCAST_ANYBUF *DataBufIn = NULL;
    ITASN1_SEQUENCE *pHeader = NULL;
    ITCAST_ANYBUF *pCurrent = NULL;
    ITCAST_ANYBUF *pTempBuf = NULL;
    Teacher *pTmpeacher = NULL;
    int charLen = 0;

    if (NULL == dataIn || NULL == pTeacher || dataLen <= 0)
        return -1;

    // 创建老师结构体：
    pTmpeacher = (Teacher *)malloc(sizeof(Teacher));
    if (NULL == pTmpeacher) {
        ret = ITDER_MemoryErr;
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func malloc() error !");
        return ret;
    }
    memset(pTmpeacher, 0, sizeof(Teacher));

    // 构建Anybuf
    DataBufIn = (ITCAST_ANYBUF *)malloc(sizeof(ITCAST_ANYBUF));
    if (NULL == DataBufIn) {
        ret = ITDER_MemoryErr;
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func malloc() error !");
        return ret;
    }
    memset(DataBufIn, 0, sizeof(ITCAST_ANYBUF));

    DataBufIn->dataLen = dataLen;
    DataBufIn->next = NULL;
    DataBufIn->prev = NULL;
    DataBufIn->pData = (unsigned char *)malloc(DataBufIn->dataLen);
    if (NULL == DataBufIn->pData) {
        ret = ITDER_MemoryErr;
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func malloc() error !");
        return ret;
    }
    memcpy(DataBufIn->pData, dataIn, DataBufIn->dataLen);

    // 解码链表;
    ret = DER_ItAsn1_ReadSequence(DataBufIn, &pHeader);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(DataBufIn);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadSequence() error !");
        return ret;
    }
    DER_ITCAST_FreeQueue(DataBufIn);

    pCurrent = pHeader;

    // 解码name：
    ret = DER_ItAsn1_ReadPrintableString(pCurrent, &pTempBuf);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadPrintableString() error !");
        return ret;
    }
    memcpy(pTmpeacher->name, pTempBuf->pData, pTempBuf->dataLen);

    pCurrent = pCurrent->next;

    // 解码age：
    ret = DER_ItAsn1_ReadInteger(pCurrent, (ITCAST_UINT32 *)&pTmpeacher->age);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadInteger() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 解码sex:
    ret = DER_ItAsn1_ReadPrintableString(pCurrent, &pTempBuf);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadPrintableString() error !");
        return ret;
    }
    memcpy(pTmpeacher->sex, pTempBuf->pData, pTempBuf->dataLen);

    pCurrent = pCurrent->next;

    // 解码stus：
    ret = DER_ItAsn1_ReadInteger(pCurrent, (ITCAST_UINT32 *)&pTmpeacher->stus);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadInteger() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 解码p：
    ret = DecodeChar(pCurrent, &pTmpeacher->p, &charLen);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DecodeChar() error !");
        return ret;
    }

    pCurrent = pCurrent->next;

    // 解码pLen：
    ret = DER_ItAsn1_ReadInteger(pCurrent, (ITCAST_UINT32 *)&pTmpeacher->pLen);
    if (ret != ITDER_NoErr) {
        DER_ITCAST_FreeQueue(pHeader);
        ITDER_LOG(__FILE__, __LINE__, LogLevel[4], ret, "func DER_ItAsn1_ReadInteger() error !");
        return ret;
    }
    DER_ITCAST_FreeQueue(pHeader);

    *pTeacher = pTmpeacher;

    return ret;
}

void write_to_file(unsigned char *DataIn, int DataLen) {
    FILE *fp = NULL;
    char path[MAX_LEN] = {0};

    if (NULL == DataIn || DataLen < 0)
        return;

#ifdef _WIN32
    sprintf(path, "d:\\keymng\\client\\ber\\%s", _DCODE_OUT_FILE_NAME_);
#else
    sprintf(path, "./ber/%s", _DCODE_OUT_FILE_NAME_);
#endif // _WIN32

    fp = fopen(path, "wb+");
    if (NULL == fp) {
        printf("open file error !\n");
        return;
    }
    fwrite(DataIn, 1, DataLen, fp);
    fclose(fp);
}

int compare_teacher(Teacher *t1, Teacher *t2) {
    if (NULL == t1 || NULL == t2)
        return -1;

    if (strcmp(t1->name, t2->name) == 0 && strcmp(t1->sex, t2->sex) == 0 && (t1->age == t2->age) && (t1->stus == t2->stus) && (t1->pLen == t2->pLen) && strncmp(t1->p, t2->p, t1->pLen) == 0) {
        return 0;
    } else
        return -1;
}

void print_teacher(Teacher *pTeacher) {
    if (NULL == pTeacher)
        return;

    printf("name = %s\n", pTeacher->name);
    printf("age = %d\n", pTeacher->age);
    printf("sex = %s\n", pTeacher->sex);
    printf("stus = %d\n", pTeacher->stus);
    printf("p = %s\n", pTeacher->p);
    printf("pLen = %d\n", pTeacher->pLen);
    return;
}

void free_teacher(void **ptr, FreeTag tag) {
    if (NULL == ptr || INVLID_TAG == tag)
        return;

    if (CHAR_TAG == tag) {
        if (*ptr != NULL) {
            free(*ptr);
            *ptr = NULL;
        }
    } else if (Teacher_TAG == tag) {
        Teacher *pTeacher = (Teacher *)(*ptr);
        if (NULL == pTeacher)
            return;

        if (pTeacher->p) {
            free(pTeacher->p);
            pTeacher->p = NULL;
        }
        free(pTeacher);
        pTeacher = NULL;
    }
    return;
}