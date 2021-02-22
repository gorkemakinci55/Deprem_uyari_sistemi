/*
 * mapping_gen1_interrupt_to_int1.c
 *
 *  Created on: 25 Jun 2020
 *      Author: gorkem.akinci
 */

#include  "interrupt_bma400.h"

void mapping_gen1_interrupt_to_int1(struct bma400_dev* bma,struct bma400_gen_int_conf int_config){

//    uint8_t gen1_int1 = 0;
//    gen1_int1 = 0x04;
//    int_config->
//    bma400_set_regs(BMA400_INT_MAP_ADDR,&gen1_int1,1,bma);

}

void interrupt_latching_selection(struct bma400_dev* bma, uint8_t latch_flag){

//    switch (latch_flag){
//    case 0:
//        bma400_set_regs(BMA400_INT_CONF_1_ADDR,&gen1_int1,1,bma);
//    case 1:
//
//    }
}

void generic1_interrupt_configuration(struct bma400_dev* bma){

    uint8_t gen1_config = 0;
    gen1_config = 0xFA;
    bma400_set_regs(BMA400_GEN1_INT_CONFIG_ADDR,&gen1_config,1,bma);

}

void generic1_interrupt_to_inactivity(struct bma400_dev* bma){

}


void set_threshold_interrupt(struct bma400_dev* bma){



}
