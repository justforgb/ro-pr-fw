#ifndef SRC_COMMUNICATION_H
#define SRC_COMMUNICATION_H

#include "fw_datatypes.h"

s32 com_init(void);
s32 com_setup(void);
s32 com_enable(void);
s32 com_disable(void);

s32 com_isConnected(u8* returnVal);

s32 com_pull(u8* retVal);

s32 com_checkCommands(u8* returnVal, states* nextState);

s32 com_handleErrors(u8* returnVal);
s32 com_handleDisconnect(u8* returnVal);
s32 com_handleInactivity(u8* returnVal);

#endif