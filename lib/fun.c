#include "fun.h"

/**
 * @brief 将char型深度转换为int型深度
 * 
 * @param deepChar char型的深度
 * @return int 要生成的深度
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
 * @brief 判断是文件还是文件夹
 * 
 * @param name 名称
 * @return int 
 *        1: 文件
 *        0: 文件夹
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
 * @brief 打印输出格式
 * 
 * @param nowDeep 当前深度
 * @param count 当前数量
 */
void showFormat(int nowDeep, int count) {
    for (int j = 0; j < nowDeep-1; j++) {
        if (j == nowDeep-2) {
            printf("  ├─── ");
            break;
        }
        printf("  │   ");
    }
}

void getFileInfo(char* path, int* deep) {
    char buf[MAX_LEN];      /* 缓冲区 */
    FILE* pathFile;         /* 文件指针 */
    char deepChar[MAX_LEN];

    if ((pathFile = fopen("path.txt", "r")) == NULL) {
        printf("路径文件打开失败，请确认文件是否存在");
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
    //     printf("打开文件夹失败: %s\n", path);
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

