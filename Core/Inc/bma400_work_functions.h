/*
 * bma400_work_functions.h
 *
 *  Created on: 19 Apr 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_BMA400_WORK_FUNCTIONS_H_
#define INC_BMA400_WORK_FUNCTIONS_H_

#include "main.h"

void quick_start_device_check(struct bma400_dev* bma, void* intfPointer);
void sleep_mode_to_normal_mode(struct bma400_dev* bma);
void reading_acceleration_data(struct bma400_dev* bma, struct bma400_sensor_data* accel);
void init_activity_interrupt_on_gen1(struct bma400_dev* bma);



#endif /* INC_BMA400_WORK_FUNCTIONS_H_ */
