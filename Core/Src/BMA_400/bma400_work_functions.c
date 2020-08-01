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

void init_activity_interrupt_on_gen1(struct bma400_dev* bma){   // function name is really bad, somebody should change it

    int8_t rslt = 0;
    uint8_t n_sett = 1; //there is only 1 sensor for now
    struct bma400_int_enable int_select;
    int_select.type = BMA400_GEN1_INT_EN;
    int_select.conf = BMA400_ENABLE;
    struct bma400_sensor_conf sensor_conf[1] = {0};
    sensor_conf[0].type = BMA400_GEN1_INT;

    // enable gen1 interrupt

    rslt = bma400_enable_interrupt(&int_select,n_sett,bma);

    // get_status_of_gen1

    rslt = bma400_get_sensor_conf(sensor_conf,n_sett, bma);

    if(sensor_conf[0].param.gen_int.int_chan == BMA400_INT_CHANNEL_2 || sensor_conf[0].param.gen_int.int_chan == BMA400_UNMAP_INT_PIN){
        //int1 not mapped and gen1 should be mapped to int1
        sensor_conf[0].param.gen_int.axes_sel = BMA400_XYZ_AXIS_EN;
        sensor_conf[0].param.gen_int.data_src = BMA400_DATA_SRC_ACC_FILT2;
        sensor_conf[0].param.gen_int.criterion_sel = BMA400_ACTIVITY_INT;
        sensor_conf[0].param.gen_int.evaluate_axes = BMA400_ALL_AXES_INT;
        sensor_conf[0].param.gen_int.ref_update = BMA400_EVERY_TIME_UPDATE;
        sensor_conf[0].param.gen_int.hysteresis = BMA400_HYST_48_MG;
        sensor_conf[0].param.gen_int.int_thres_ref_x = 1; // TODO: change them
        sensor_conf[0].param.gen_int.int_thres_ref_y = 1;
        sensor_conf[0].param.gen_int.int_thres_ref_z = 1;
        sensor_conf[0].param.gen_int.int_chan = BMA400_INT_CHANNEL_1;

        bma400_set_sensor_conf(sensor_conf,n_sett,bma); // gen1 configed and mapped to int1
    }



}
