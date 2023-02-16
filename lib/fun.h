#ifndef __FUN_H__
#define __FUN_H__

#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <sys/stat.h>

#define MAX_LEN 1024

/**
 * @brief ��ȡ�ļ��е���Ϣ
 * 
 * @param path Ҫ���ɵ��ļ���·��
 * @param deep Ҫ���ɵ����
 */
void getFileInfo(char* path, int* deep);
/**
 * @brief ��ʾ�ļ��нṹ
 * 
 * @param path �ļ���·��
 * @param deep �������
 * @param nowDeep ��ǰ���
 */
void showFolderStruct(char* path, int deep, int nowDeep);

#endif