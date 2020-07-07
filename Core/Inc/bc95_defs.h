/*
 * bc95_defs.h
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_BC95_DEFS_H_
#define INC_BC95_DEFS_H_


struct bc95_dev{

    /* Interface handle pointer */

	void *intf_ptr;

	/* bus read pointer function */

	bc95_com_fptr_t read;

	/*bus write pointer function */

	bc95_com_fptr_t write;

};


typedef int8_t (*bc95_com_fptr_t)(void *intfPtr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);

#endif /* INC_BC95_DEFS_H_ */
