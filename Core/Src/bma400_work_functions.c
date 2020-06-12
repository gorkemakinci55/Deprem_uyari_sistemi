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

void sleep_mode_to_normal_mode(struct bma400_dev* bma){

    int8_t rslt = 0;
    uint8_t powerMode;
    rslt = bma400_get_power_mode(&powerMode,bma);
    if(rslt == BMA400_OK){


        if(powerMode == 0x00){
            printf("Device is on Sleep Mode");
        }
        else if(powerMode == 0x01){
            printf("Device is on Low power Mode");
            return ;
        }
        else if(powerMode == 0x02){
            printf("Device is on Normal Mode");
            return ;
        }
        else {
            printf("Device Status register gives error");
            return ;
        }
        powerMode = 0x02;
        rslt = bma400_set_power_mode(&powerMode,bma);
        return ;
    }
    else{
        return;
    }

}

void reading_acceleration_data (struct bma400_dev* bma, struct bma400_sensor_data* accel){
    uint8_t data_sel = 0;
    int8_t rslt = 0;
    uint8_t powerMode,chip_id = 0;
    rslt = bma400_get_regs(BMA400_CHIP_ID_ADDR,&chip_id,1,bma);
    if(rslt == BMA400_OK){
        if(chip_id != bma->chip_id){
            printf("Error,chip_id isnt correct");
        }
        else{
            rslt = bma400_get_power_mode(&powerMode,bma);
            if(powerMode == 0x00){
                printf("Powermode is on sleep,no accel data");

            }
            else if(powerMode == 0x01){
                printf("Powermode is on low");
            }
            else{
                printf("Powermode is on normal, there is accel data");
                bma400_get_accel_data(data_sel,accel,bma);
            }
        }
    }




}
