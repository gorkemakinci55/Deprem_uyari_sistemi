/*
 * bc.95.c
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#include "bc95.h"
#include <string.h>
#include <stdio.h>


int8_t uart_register_write(UART_HandleTypeDef* intfPtr, uint16_t dataSize,
        uint8_t *reg_data, uint32_t timeOut){

    HAL_StatusTypeDef BC95HalStatus = HAL_OK;
    BC95HalStatus = HAL_UART_Transmit(intfPtr, reg_data, dataSize ,timeOut);
    if(BC95HalStatus == HAL_OK){
        printf("UART_register_write_succesful");
    }
    else if(BC95HalStatus == HAL_TIMEOUT){
        printf("UART_register_write_timeout");
    }
    else{
        printf("UART_register_write_error");
    }

    return BC95HalStatus;
}


int8_t uart_register_read(UART_HandleTypeDef intfPtr, uint16_t dataSize,
        uint8_t *reg_data, uint32_t timeOut){

    HAL_StatusTypeDef BC95HalStatus = HAL_OK;
    BC95HalStatus = HAL_UART_Receive(&intfPtr,reg_data,dataSize,timeOut);
    if(BC95HalStatus == HAL_OK){
        printf("UART_register_read_succesful");
    }
    else if(BC95HalStatus == HAL_TIMEOUT){
        printf("UART_register_read_timeout");
    }
    else{
        printf("UART_register_read_error");
    }

    return BC95HalStatus; //burayı tekrar düşün

}

int8_t uart_register_read_it(UART_HandleTypeDef* intfPtr, uint16_t dataSize,
        uint8_t *reg_data){

    HAL_StatusTypeDef BC95HalStatus = HAL_OK;
    BC95HalStatus = HAL_UART_Receive_IT(intfPtr,reg_data,dataSize);

    return BC95HalStatus;
}



void send_at_command(const char* AT_command, struct bc95_dev *dev){

    //Send AT command data and wait response
    uint16_t AT_commandSize = strlen(AT_command); // At command size
    uint32_t timeOut = 10; // Timeout 10 ms
//    dev->write(dev->intf_ptr,(uint8_t)AT_command,AT_commandSize,timeOut); // send AT command

}

char* read_at_command(struct bc95_dev *dev,char* receivedData){

    uint32_t timeOut = 10; // Timeout 10 ms
    uint8_t Size = 50;
//    dev->read(dev->intf_ptr,receivedData,Size,timeOut);
    return receivedData;

}


