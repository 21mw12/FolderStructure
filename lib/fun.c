#include "fun.h"

/**
 * @brief ��char�����ת��Ϊint�����
 * 
 * @param deepChar char�͵����
 * @return int Ҫ���ɵ����
 */
int getDeep(char* deepChar) {
    int deep = 0;
    int i = 0;
    while (deepChar[i] != '\0') {
        deep = deep * 10 + (int)(deepChar[i]-'0');
        i++;
    }
    return deep;
}

/**
 * @brief �ж����ļ������ļ���
 * 
 * @param name ����
 * @return int 
 *        1: �ļ�
 *        0: �ļ���
 */
int isFile(char* name) {
    int i = 0;
    while (name[i] != '\0') {
        if (name[i] == '.') {
            return 1;
        }
        i++;
    }
    return 0;
}

/**
 * @brief ��ӡ�����ʽ
 * 
 * @param nowDeep ��ǰ���
 * @param count ��ǰ����
 */
void showFormat(int nowDeep, int count) {
    for (int j = 0; j < nowDeep-1; j++) {
        if (j == nowDeep-2) {
            printf("  �������� ");
            break;
        }
        printf("  ��   ");
    }
}

void getFileInfo(char* path, int* deep) {
    char buf[MAX_LEN];      /* ������ */
    FILE* pathFile;         /* �ļ�ָ�� */
    char deepChar[MAX_LEN];

    if ((pathFile = fopen("path.txt", "r")) == NULL) {
        printf("·���ļ���ʧ�ܣ���ȷ���ļ��Ƿ����");
        return;
    }

    // while(fgets(buf, MAX_LEN, pathFile) != NULL) {
    //     printf("%s", buf);
    // }
    fgets(buf, MAX_LEN, pathFile);
    int len = strlen(buf);
    buf[len-1] = '\0';
    strcpy(path, buf);

    fgets(buf, MAX_LEN, pathFile);
    strcpy(deepChar, buf);

    *deep = getDeep(deepChar);
}

void showFolderStruct(char* path, int deep, int nowDeep) {
    if (deep == 0) {
        return;
    }

    struct _finddata_t file;
    intptr_t  hFile;
    char buf[MAX_LEN];

    // if (_chdir(path)) {
    //     printf("���ļ���ʧ��: %s\n", path);
    //     return;
    // }

    int count = 0;

    hFile = _findfirst("*", &file);
    while (_findnext(hFile, &file) == 0) {
        if (!strcmp(file.name, "..")) continue;

        showFormat(nowDeep, ++count);
        printf(" %s\n", file.name);

        if (!isFile(file.name)) {
            sprintf_s(buf, MAX_LEN, "%s\\\\%s", path, file.name);
            showFolderStruct(buf, deep-1, ++nowDeep);
        }
    }
}

