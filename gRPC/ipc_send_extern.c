#include "im_upgrade_data.h"
#include "im.grpc-c.h"

static int ipc_arrange_upgrade_data(im_upgrade_data_t *upd_data, GIm__ImDeviceUpgradeData *upgrade)
{
    upgrade->has_device_upgrade_type = true;
    upgrade->device_upgrade_type =upd_data->data_type;

    if(upd_data->data_type == G_IM__DEVICE_UPGRADE_TYPE__DEVICE_GET_VERSION)
    {
        upgrade->passthrough_data = (GIm__ImDevicePassthroughResponse *)malloc(sizeof(GIm__ImDevicePassthroughResponse));
        g_im__im_device_passthrough_response__init(upgrade->passthrough_data);

        //version data
        upgrade->passthrough_data->address = malloc(PASSTHROUGH_ADDR_LENGTH_DEF);
        memset(upgrade->passthrough_data->address, 0, 32);
        strcpy(upgrade->passthrough_data->address, upd_data->passthrough_data.addr);
    }
}
