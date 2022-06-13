#ifndef IM_COMMON_H
#define IM_COMMON_H
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define IM_STR_LEN_64     64

typedef struct sysmon_mem_info_s {
    unsigned long long total_k;            /* 系统总内 */
    unsigned long long free_k;             /* 内存余量 */
    unsigned long long buffers_k;
    unsigned long long cached_k;
    unsigned long long reserved_k;         /* 内核保留 */
    unsigned long long active_k;
    unsigned long long inactive_k;
    unsigned long long mapped_k;
    unsigned long long slab_k;
    unsigned long long other_k;
    unsigned long long shmem_k;
} sysmon_mem_info_t;

#endif // IM_COMMON_H
