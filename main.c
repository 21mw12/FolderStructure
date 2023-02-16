#include <stdio.h>
#include "lib/fun.h"

int main() {
    char path[MAX_LEN];
    int deep = 0;
    getFileInfo(path, &deep);

    printf("%s:\n", path);
    showFolderStruct(path, deep, 1);

    system ("pause");
    return 0;
}
