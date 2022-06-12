#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "testing_utils.h"

void testing_utils()
{
    testing_append_str();
}

void testing_append_str()
{
    char *auth_str;
    char tmp_str[64] = {0};
    uint32_t len = 0;

    auth_str = (char *)malloc(10);
    sprintf(auth_str, "License");
    snprintf(tmp_str, sizeof(tmp_str), " Total = %u\n", 100);
    len = 20;
    im_str_append(&auth_str, tmp_str, &len);

    printf("auth_str = %s\n", auth_str);
    free(auth_str);
    auth_str = NULL;
}
