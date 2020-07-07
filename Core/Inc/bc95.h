/*
 * bc95.h
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_BC95_H_
#define INC_BC95_H_

#include "bc95_defs.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

const char *atStartString  = "/r/nNeul/r/lOK/r/l";

void set_bc95_uart_interface( struct bc95_dev *dev , void* intfPointer);
int8_t uart_register_write(void* intfPtr,  uint8_t spi_id, uint8_t reg_addr,
        uint8_t *reg_data, uint16_t length);
int8_t uart_register_read(void* intfPtr,  uint8_t spi_id, uint8_t reg_addr,
        uint8_t *reg_data, uint16_t length);

#endif /* INC_BC95_H_ */
