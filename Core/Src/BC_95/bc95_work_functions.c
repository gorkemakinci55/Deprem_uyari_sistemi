/*
 * bc95_work_functions.c
 *
 *  Created on: 4 Jul 2020
 *      Author: gorkem.akinci
 */

#include "bc95_work_functions.h"


void init_bc95_interface(struct bc95_dev * bc95,void* intfPointer){

    bc95->intf_ptr = intfPointer;
    bc95->write = uart_register_write;
    bc95->read = uart_register_read;

}
void bc95_at_start_check(struct bc95_dev *bc95){

    char *atStateCheck = malloc(sizeof(char)* 200);
    int8_t halStatusCheck,count = 0;
    halStatusCheck = uart_register_read(bc95->intf_ptr,atStateCheck,200,100);
    while(halStatusCheck == 3){
        if(count = 5){
            printf("BC95 ATCommands don't work");
            break;
        }
        else{
            halStatusCheck = uart_register_read(bc95->intf_ptr,atStateCheck,200,100);
        }
        ++count;
    }
    if(halStatusCheck == HAL_OK){
        int comparisonResult = strcmp(atStateCheck,atCommandReady);
        if(comparisonResult == 0){
            printf("BC95 is ready for AT command operation");
        }
    }
}



void bc95_connection_status(struct bc95_dev * bc95){

    // Connection status AT command is AT+CSCON

//    const *char atCommand = CONNECTION_STATUS;
//    enum unsolicityStatus unsolicity = ENABLE_UNSOLICITYRESULTCODE;
//    uint8_t* atResponse;
//    set_at_cscon_status(unsolicity , atResponse );
//    get_at_cscon_status();

}

void bc95_establish_network_connection(){

}


void bc95_test_IP_network_connectivity_to_remote_host(){





}
