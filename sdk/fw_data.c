#include "fw_data.h"
#include "fw_hw.h"
#include "tcpip_custom.h"

s32 data_send_measurements(void){
	
	u32 data;
	u32 len;

	if(hardware_get_data(&data, &len) != XST_SUCCESS){
		return XST_FAILURE;
	}

	ah_tcip_setflag_copy(0);
	if(tcpip_custom_push((void*) data, (u32)len) != XST_SUCCESS){
		return XST_FAILURE;
	}
	ah_tcip_setflag_copy(1);

	return XST_SUCCESS;
}

s32 data_send_temperatures(u16 temp_start, u16 temp_end){

	if(tcpip_custom_push((void*) &temp_start, 2) != XST_SUCCESS){
		return XST_FAILURE;
	}

	if(tcpip_custom_push((void*) &temp_end, 2) != XST_SUCCESS){
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

s32 data_check_sent(u8* returnVal){


	if(tcpip_custom_checkDataSent(returnVal) != XST_SUCCESS){
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

s32 data_reset_sent(u8 force){


	if(tcpip_custom_resetDataSent(force) != XST_SUCCESS){
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}

