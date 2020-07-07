/*
 * bc.95.c
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#include "bc95.h"


int8_t uart_register_write(void* intfPtr,  uint8_t spi_id, uint8_t reg_addr,
        uint8_t *reg_data, uint16_t length){

    HAL_StatusTypeDef BC95HalStatus = HAL_OK;
    BC95HalStatus = HAL_SPI_Transmit(intfPtr, reg_addr, reg_data,length);
    if(BC95HalStatus == HAL_OK){
        printf("UART_register_write_succesful");
    }
    else if(BC95HalStatus == HAL_TIMEOUT){
        printf("UART_register_write_timeout");
    }
    else{
        printf("UART_register_write_error");
    }
}

int8_t uart_register_read(void* intfPtr,  uint8_t spi_id, uint8_t reg_addr,
        uint8_t *reg_data, uint16_t length){

}

void set_bc95_uart_interface(struct bc95_dev *dev , void* intfPointer){


    dev->read = uart_register_read;

    dev->write = uart_register_write;

}
