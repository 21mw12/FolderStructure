#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <sys/stat.h>

#define MAX_LEN 1024

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

int getDeep(char* deepChar) {
    int deep = 0;
    int i = 0;
    while (deepChar[i] != '\0') {
        deep = deep * 10 + (int)(deepChar[i]-'0');
        i++;
    }
    return deep;
}

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

void showFormat(int nowDeep, int count) {
    for (int j = 0; j < nowDeep-1; j++) {
        if (j == nowDeep-2) {
            printf("  ├─── ");
            break;
        }
        printf("  │   ");
    }
}

void showFolderStruct(char* path, int deep, int nowDeep) {
    if (deep == 0) {
        return;
    }

    struct _finddata_t file;
    intptr_t  hFile;
    char buf[MAX_LEN];

    if (_chdir(path)) {
        printf("打开文件夹失败: %s\n", path);
        return;
    }

    int count = 0;

    hFile = _findfirst("*", &file);
    while (_findnext(hFile, &file) == 0) {
        if (!strcmp(file.name, "..")) continue;

        showFormat(nowDeep, ++count);

        printf(" %s\n", file.name);
        if (!isFile(file.name)) {
            sprintf_s(buf, MAX_LEN, "%s\\\\%s", path, file.name);
            showFolderStruct(buf, deep-1, nowDeep+1);
        }
    }
}

int main() {
    char path[MAX_LEN];
    int deep = 0;
    getFileInfo(path, &deep);

    printf("%s:\n", path);
    showFolderStruct(path, deep, 1);

    system ("pause");


    // printf("%s", path);
    // printf("%d\n", deep);
    return 0;
}
