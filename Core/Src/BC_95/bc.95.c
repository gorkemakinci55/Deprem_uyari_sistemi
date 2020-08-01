/*
 * bc.95.c
 *
 *  Created on: 1 Jul 2020
 *      Author: gorkem.akinci
 */

#include "bc95.h"


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


int8_t uart_register_read(UART_HandleTypeDef* intfPtr, uint16_t dataSize,
        uint8_t *reg_data, uint32_t timeOut){

    HAL_StatusTypeDef BC95HalStatus = HAL_OK;
    BC95HalStatus = HAL_UART_Receive(intfPtr,reg_data,dataSize,timeOut);
    if(BC95HalStatus == HAL_OK){
        printf("UART_register_read_succesful");
    }
    else if(BC95HalStatus == HAL_TIMEOUT){
        printf("UART_register_read_timeout");
    }
    else{
        printf("UART_register_read_error");
    }


}



void at_command_send(const char* AT_command, uint8_t* AT_response, void* intfPtr){

    //Send AT command data and wait response
    uint8_t AT_commandSize = strlen(AT_command);
  //  uart_register_write((UART_HandleTypeDef*)intfPtr,);
    HAL_DELAY(10);
  //  uart_register_read();

}


