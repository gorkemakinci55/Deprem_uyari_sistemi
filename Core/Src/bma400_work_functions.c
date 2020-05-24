/*
 * bma400_work_functions.c
 *
 *  Created on: 19 Apr 2020
 *      Author: gorkem.akinci
 */

#include "bma400_work_functions.h"

void quick_start_device_check(struct bma400_dev* bma, void* intfPointer){

	uint8_t rslt;

	set_interface(BMA400_SPI_INTF, bma, intfPointer);

	rslt = bma400_init(bma);



}
