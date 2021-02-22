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


void set_bc95_uart_interface( struct bc95_dev *dev , void* intfPointer);
int8_t uart_register_write(UART_HandleTypeDef* intfPtr, uint16_t dataSize,
        uint8_t *reg_data, uint32_t timeOut);
int8_t uart_register_read(UART_HandleTypeDef intfPtr, uint16_t dataSize,
        uint8_t *reg_data, uint32_t timeOut);



void send_at_command(const char* AT_command, struct bc95_dev *dev);
char* read_at_command(struct bc95_dev *dev,char* receivedData);

void receive_at_command_response(const char* AT_command, uint8_t* AT_response, void* intfPtr);



#endif /* INC_BC95_H_ */
