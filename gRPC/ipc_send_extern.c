#include "im_upgrade_data.h"
#include "protobuf-c/im.pb-c.h"
#include <stdbool.h>

static int ipc_arrange_upgrade_data(im_upgrade_data_t *upd_data, GIm__ImDeviceUpgradeData *upgrade)
{
//    upgrade->has_device_upgrade_type = true;
    upgrade->device_upgrade_type =upd_data->data_type;

    if(upd_data->data_type == G_IM__DEVICE_UPGRADE_TYPE__DEVICE_GET_VERSION)
    {
        upgrade->passthrough_data = (GIm__ImDevicePassthroughResponse *)malloc(sizeof(GIm__ImDevicePassthroughResponse));
        g_im__im_device_passthrough_response__init(upgrade->passthrough_data);

        //version data
        upgrade->passthrough_data->address = malloc(PASSTHROUGH_ADDR_LENGTH_DEF);
        memset(upgrade->passthrough_data->address, 0, 32);
        strcpy(upgrade->passthrough_data->address, upd_data->passthrough_data.addr);

        upgrade->passthrough_data->port = malloc(16);
        memset(upgrade->passthrough_data->port, 0, 16);
        strcpy(upgrade->passthrough_data->port, upd_data->passthrough_data.port);

        upgrade->passthrough_data->content = malloc(256);
        memset(upgrade->passthrough_data->content, 0, 256);
        strcpy(upgrade->passthrough_data->content, upd_data->passthrough_data.content);

        upgrade->passthrough_data->channel_id = malloc(16);
        memset(upgrade->passthrough_data->channel_id, 0, 16);
        strcpy(upgrade->passthrough_data->channel_id, upd_data->passthrough_data.channel);

        upgrade->passthrough_data->result = 0;
    }
    else
    {
        upgrade->n_update_data = upd_data->upgrade_number;
        if(upgrade->n_update_data > 0)
        {
            upgrade->update_data = (GIm__ImDeviceUpdateInfo **)malloc(sizeof(GIm__ImDeviceUpdateInfo *) * upgrade->n_update_data);
            for(int i = 0; i < (int)upgrade->n_update_data; i++)
            {
                ;
            }
        }
    }
}



















