#include "im_utils.h"

int im_str_append(char **buf, char *str, uint32_t *len)
{
    uint32_t used_len;
    unsigned long tmp_addr;
    uint32_t tmp_len;
    uint32_t str_len;

    used_len = strlen(*buf);
    str_len = strlen(str);

    if(str_len >= (*len - used_len))
    {
        tmp_addr = (unsigned long)(*buf);
        tmp_len = *len;

        for(; *len <= str_len + used_len; *len = (*len) * 2);

        *buf = (char *)malloc(*len);
        if(*buf == NULL)
        {
            *len = tmp_len;
            *buf = (char *)tmp_addr;
            return -1;
        }

        memset(*buf, 0, *len);
        strcpy(*buf, (char *)tmp_addr);
        free((char *)tmp_addr);
    }

    strcat(*buf, str);
}
