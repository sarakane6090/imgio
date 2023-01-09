#include <string.h>
#include "core/utils.h"

// filenameから"."を含めた拡張子を取得
void DecodeFileExtensions(char *filename, char *extensions)
{
    int maxlen = strlen(filename);

    // 文字列の後ろから4文字取得("."を含めるため)
    char tmp[4];
    for (int i = 0; i < 4; i++) {
        tmp[i] = filename[maxlen - (4 - i)];
    }

    extensions = tmp;
}
