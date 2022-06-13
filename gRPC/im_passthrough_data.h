#ifndef IM_PASSTHROUGH_DATA_H
#define IM_PASSTHROUGH_DATA_H

#define PASSTHROUGH_COMMON_LENGTH_DEF   16
#define PASSTHROUGH_ADDR_LENGTH_DEF     32
#define PASSTHROUGH_CONTENT_LENGTH_DEF  256

typedef struct{
    char    addr[PASSTHROUGH_ADDR_LENGTH_DEF];
    char    port[PASSTHROUGH_COMMON_LENGTH_DEF];
    char    content[PASSTHROUGH_CONTENT_LENGTH_DEF];
    char    channel[PASSTHROUGH_COMMON_LENGTH_DEF];
    int     result;
}im_passthrough_data_t;

#endif // IM_PASSTHROUGH_DATA_H
