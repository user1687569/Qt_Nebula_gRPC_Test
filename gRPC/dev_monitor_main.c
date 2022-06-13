#include "dev_monitor.h"

bool dev_monitor_config_netcard()
{
    char cmdstr[IM_STR_LEN_64];
    int ret;

    snprintf(cmdstr, sizeof(cmdstr), "ifconfig %s down", "eth0");
    printf(">>>>>%s\n", cmdstr);
    ret = system(cmdstr);
    if(ret != 0)
    {
        printf(">>>>>Failed! (File: %s, Line: %d)\n", __FILE__, __LINE__);
        return false;
    }

    snprintf(cmdstr, sizeof(cmdstr), "sudo ifconfig %s %s netmask %s",
             "eth0", "192.168.3.123", "255.255.252.0");
    printf(">>>>>%s\n", cmdstr);
    ret = system(cmdstr);
    if(ret != 0)
    {
        printf(">>>>>Failed! (File: %s, Line: %d)\n", __FILE__, __LINE__);
        return false;
    }

    return true;
}


int mc_judge_eth_exist()
{
    char getbuf[IM_STR_LEN_64];
    char *cmd_format = "ifconfig -a | grep -i %s | awk '{print $1}'";
    char cmd[IM_STR_LEN_64];
    FILE *fp;

//    snprintf(cmd, IM_STR_LEN_64, cmd_format, "lo");
    strcpy(cmd, "ifconfig -a");
    fp = popen(cmd, "r");
    if(fp == NULL)
        return -1;

    memset(getbuf, 0, sizeof(getbuf));
    while (fgets(getbuf, sizeof(getbuf), fp) != NULL) {
//        if(getbuf[strlen(getbuf) - 1] == '\n')
//        {
//            getbuf[strlen(getbuf) - 1] = 0;
//        }
        printf("%s", getbuf);
    }

    pclose(fp);
    printf("Get netcard info done...\n");
    return 0;
}


int get_sys_mem_info(sysmon_mem_info_t *sys_info)
{
    FILE *fp;
    char *line, linetmp[IM_STR_LEN_64 * 4] = {0};
    char *p;

    if(sys_info == NULL)
    {
        return -1;
    }

    memset(sys_info, 0, sizeof(sysmon_mem_info_t));

    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL)
    {
        return -1;
    }

    //To Do
}







