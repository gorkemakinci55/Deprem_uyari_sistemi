/*
 * interrupt_bma400.h
 *
 *  Created on: 25 Jun 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_INTERRUPT_BMA400_H_
#define INC_INTERRUPT_BMA400_H_

void mapping_gen1_interrupt_to_int1(struct bma400_dev* bma);
void interrupt_latching_selection(struct bma400_dev* bma, uint8_t latch_flag);
void generic1_interrupt_configuration(struct bma400_dev* bma);
void generic1_interrupt_to_inactivity(struct bma400_dev* bma);

#endif /* INC_INTERRUPT_BMA400_H_ */
