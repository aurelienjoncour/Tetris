#include <stdbool.h>
#include "my.h"

bool allow_char(char *script, char *allow_char)
{
    int len_script = my_strlen(script);
    int len_allow = my_strlen(allow_char);
    int cnt = 0;

    for (int i = 0; i  < len_script; i++) {
        cnt = 0;
        for (int j = 0; j < len_allow; j++) {
            if (script[i] == allow_char[j])
                cnt++;
        }
        if (cnt != 1)
            return true;
    }
    return false;
}