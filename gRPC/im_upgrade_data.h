#ifndef IM_UPGRADE_DATA_H
#define IM_UPGRADE_DATA_H

#include "im_passthrough_data.h"

#define UPGRADE_INFO_CNT_MAX    6

typedef struct{
    int             id;
    unsigned int    type;
    char            addr[64];
    unsigned short  port;
    unsigned short  status;
    unsigned short  errcode;
} im_upgradeInfo_t;

typedef struct{
    unsigned int        data_type;
    unsigned int        upgrade_number;
    im_upgradeInfo_t    upgrade_info[UPGRADE_INFO_CNT_MAX];
    im_passthrough_data_t   passthrough_data;
} im_upgrade_data_t;

#endif // IM_UPGRADE_DATA_H
