/*
 * spi_bma_interface.c
 *
 *  Created on: 16 Apr 2020
 *      Author: gorkem.akinci
 */

#include "spi_bma_interface.h"

int8_t spi_register_write(void* intfPtr,  uint8_t spi_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t length){

    if(spi_id == CHIP_1){

         HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);

            printf("spi_chip_select_pulled_down, transmit data");
            HAL_StatusTypeDef BMA400HalStatusSpi = HAL_OK;
            BMA400HalStatusSpi = HAL_SPI_Transmit(intfPtr, reg_addr, reg_data,length);
            if(BMA400HalStatusSpi == HAL_OK){
                printf("spi_register_write_succesful");
            }
            else if(BMA400HalStatusSpi == HAL_TIMEOUT){
                printf("spi_register_write_timeout");
            }
            else{
                printf("spi_register_write_error");
            }
         HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
    }
}

int8_t spi_register_read(void* intfPtr,uint8_t spi_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t length){

    if(spi_id == CHIP_1){

        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);

            printf("spi_chip_select_pulled_down, transmit data");
            HAL_StatusTypeDef BMA400HalStatusSpi = HAL_OK;
            BMA400HalStatusSpi = HAL_SPI_Receive(intfPtr, reg_addr, reg_data,length);
            if(BMA400HalStatusSpi == HAL_OK){
                printf("spi_register_read_succesful");
            }
            else if(BMA400HalStatusSpi == HAL_TIMEOUT){
                printf("spi_register_read_timeout");
            }
            else{
                printf("spi_register_read_error");
        }
    }
}

int8_t delay_function(int8_t delayTimer){

	HAL_Delay(delayTimer);
}

void set_bma400_interface(enum bma400_intf intf, struct bma400_dev *dev)
{
    switch (intf)
    {
        case BMA400_I2C_INTF:
            dev->intf_ptr = NULL; /* To attach your interface device reference */
           // dev->delay_ms = delay_ms;
            dev->dev_id = BMA400_I2C_ADDRESS_SDO_LOW;
            dev->read = spi_register_read;
            dev->write = spi_register_write;
            dev->intf = BMA400_I2C_INTF;
            break;
        case BMA400_SPI_INTF:
            dev->intf_ptr = NULL; /* To attach your interface device reference */
            dev->dev_id = CHIP_1; /* Could be used to identify the chip select line. */
            dev->delay_ms = delay_function;
            dev->read = spi_register_read;
            dev->write = spi_register_write;
            dev->intf = BMA400_SPI_INTF;
            break;
        default:
            printf("Interface not supported.\r\n");
    }
}

//void configure_dev_ptr(bma400_dev* devPtr){
//
////	devPtr->chip_id
////	devPtr->delay_ms
////	devPtr->dev_id
////	devPtr->write = spi_register_write;
//}
