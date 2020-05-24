/*
 * spi_bma_interface.h
 *
 *  Created on: 16 Apr 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_SPI_BMA_INTERFACE_H_
#define INC_SPI_BMA_INTERFACE_H_

#include "stm32l0xx_hal.h"
#include "bma400_defs.h"
#include "bma400.h"

int8_t spi_register_write(void* intfPtr,uint8_t spi_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);

int8_t spi_register_read(void* intfPtr,uint8_t spi_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);

void set_interface(enum bma400_intf intf, struct bma400_dev *dev, void* intfPointer);

//void configure_dev_ptr(bma400_dev* devPtr);

#endif /* INC_SPI_BMA_INTERFACE_H_ */
