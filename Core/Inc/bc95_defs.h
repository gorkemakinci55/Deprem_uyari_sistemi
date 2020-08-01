/*
 * bc95_defs.h
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#include "stm32l0xx_hal.h"

#ifndef INC_BC95_DEFS_H_
#define INC_BC95_DEFS_H_

typedef int8_t (*bc95_com_fptr_t)(void *intfPtr, uint8_t *pData, uint16_t Size, uint32_t Timeout);

enum unsolicityStatus{

    DISABLE_UNSOLICITY_RESULTCODE,
    ENABLE_UNSOLICITY_RESULTCODE
};

enum connectionStatus {
  // define bc95 connection status

    IDLE_STATE,
    CONNECTED_STATE

};

typedef struct bc95_dev{

    /* Interface handle pointer */

	void *intf_ptr;

	/* bus read pointer function */

	bc95_com_fptr_t read;

	/*bus write pointer function */

	bc95_com_fptr_t write;

};




#endif /* INC_BC95_DEFS_H_ */
