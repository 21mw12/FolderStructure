#ifndef __FUN_H__
#define __FUN_H__

#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <sys/stat.h>

#define MAX_LEN 1024

/**
 * @brief 获取文件中的信息
 * 
 * @param path 要生成的文件夹路径
 * @param deep 要生成的深度
 */
void getFileInfo(char* path, int* deep);
/**
 * @brief 显示文件夹结构
 * 
 * @param path 文件夹路径
 * @param deep 访问深度
 * @param nowDeep 当前深度
 */
void showFolderStruct(char* path, int deep, int nowDeep);

#endif