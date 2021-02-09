/*
 * bc95_work_functions.h
 *
 *  Created on: 4 Jul 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_BC95_WORK_FUNCTIONS_H_
#define INC_BC95_WORK_FUNCTIONS_H_

#include "bc95.h"
#include "bc95_defs.h"
#include "at_commands.h"

//void init_bc95_interface(struct bc95_dev *bc95,void* intfPointer);
void bc95_at_start_check(struct bc95_dev *bc95);
void bc95_connection_status(struct bc95_dev *bc95);
void bc95_test_IP_network_connectivity_to_remote_host();
void bc95_establish_network_connection();
void set_manually_register_on_network(struct bc95_dev *bc95);
void reboot_module_by_software(struct bc95_dev *bc95);
void set_functionality_mode(uint8_t functionalityFlag, struct bc95_dev *bc95);
void set_eDRX_mode(struct bc95_dev *bc95, uint8_t eDrxModeFlag);

#endif /* INC_BC95_WORK_FUNCTIONS_H_ */
