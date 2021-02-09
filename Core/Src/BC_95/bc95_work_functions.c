/*
 * bc95_work_functions.c
 *
 *  Created on: 4 Jul 2020
 *      Author: gorkem.akinci
 */

#include "bc95_work_functions.h"
#include "string.h"



//void init_bc95_interface(struct bc95_dev * bc95, void* intfPointer){
//
//    bc95->intf_ptr = intfPointer;
//    bc95->write = uart_register_write;
//    bc95->read = &uart_register_read;
////    bc95->read_it = uart_register_read_it;
//
//}

void bc95_at_start_check(struct bc95_dev *bc95){

    char *atStateCheck = malloc(sizeof(char)* 200);
    int8_t halStatusCheck,count = 0;
    //halStatusCheck = bc95->read(bc95->intf_ptr,atStateCheck,200,100);

    halStatusCheck = uart_register_read(bc95->intf_ptr,atStateCheck,200,100);
//    while(halStatusCheck == 3){
//        if(count = 5){
//            printf("BC95 ATCommands don't work");
//            break;  // TODO call function who try to reboot bc95
//        }
//        else{
//            halStatusCheck = uart_register_read(bc95->intf_ptr,atStateCheck,200,100);
//        }
//        ++count;
//    }
    if(halStatusCheck == HAL_OK){
        int comparisonResult = strcmp(atStateCheck,atCommandReady);
        if(comparisonResult == 0){
            printf("BC95 is ready for AT command operation");
        }
    }
    free (atStateCheck);
    return;
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

void set_manually_register_on_network(struct bc95_dev *bc95){

    char config[100];// "=AUTOCORRECT,FALSE";
    memset(config,0x00,100);
    int dl = strlen(configureUeBehaviour);
    int x=0;
    if(dl<99)// Check for possible overflow, 99th byte reserved=1 byte for '\0'
    while (x<dl){ config[x]=configureUeBehaviour[x]; x++; }
    if(x<100) config[x]=0;
    else printf("overflow");
    uint8_t* atCommandMessage = strcat(config, "=AUTOCORRECT,FALSE" );
    send_at_command(atCommandMessage,bc95);

}

void reboot_module_by_software(struct bc95_dev *bc95){

    send_at_command(rebootModule,bc95);

}

void set_functionality_mode(uint8_t functionalityFlag, struct bc95_dev *bc95){

    if(functionalityFlag = 0){
        //minimum functionality
        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, functionality );
        atCommandMessage = strcat(atCommandMessage,"=0");
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);
    }
    else if(functionalityFlag = 1){
        //full functionality
        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, functionality );
        atCommandMessage = strcat(atCommandMessage,"=1");
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);
    }
    else{
        printf("error");
    }

}

/*void set_eDRX_mode(struct bc95_dev *bc95, uint8_t eDrxModeFlag,AotTypeEdrx aotTypeEdrx){

    if(eDrxModeFlag == 0){
        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, eDrxMode);
        atCommandMessage = strcat(atCommandMessage,"0");
        switch(aotTypeEdrx){
        case EC_GSM_IoT:
            atCommandMessage = strcat(atCommandMessage,",1");
            break;
        case GSM:
            atCommandMessage = strcat(atCommandMessage,",2");
            break;
        case UTRAN:
            atCommandMessage = strcat(atCommandMessage,",3");
            break;
        case E_UTRAN1:
            atCommandMessage = strcat(atCommandMessage,",4");
            break;
        case E_UTRAN2:
            atCommandMessage = strcat(atCommandMessage,",5");
            break;
        }
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);


    }
    else if(eDrxModeFlag == 1){

        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, eDrxMode);
        atCommandMessage = strcat(atCommandMessage,"=1");
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);

    }
    else{
        return;
    }

    return;
}*/

void trigger_network_attachment(struct bc95_dev *bc95, uint8_t networkAttachmentFlag){

    if(networkAttachmentFlag == 0){
        //detach
        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, trigNetworkAttachment);
        atCommandMessage = strcat(atCommandMessage,"=0");
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);

    }
    else if(networkAttachmentFlag == 1){
        //attach
        char* atCommandMessage = (char*)malloc(50*sizeof(char));
        memset(atCommandMessage,0,50);
        atCommandMessage = strcat(atCommandMessage, trigNetworkAttachment);
        atCommandMessage = strcat(atCommandMessage,"=1");
        send_at_command(atCommandMessage,bc95);
        free(atCommandMessage);
    }
    else {
        return;
    }
    return;
}


/*int query_network_attachment(struct bc95_dev *bc95){

    char* atCommandMessage = (char*)malloc(50*sizeof(char));
    char receviedAtCommand[50];
    memset(atCommandMessage,0,50);
    atCommandMessage = strcat(atCommandMessage, trigNetworkAttachment);
    atCommandMessage = strcat(atCommandMessage,"?");

    send_at_command(atCommandMessage  , bc95 );
    read_at_command(bc95,receviedAtCommand);
    char* NetworkDetached[11] = "AT+CGATT:0";
    char* NetworkAtached[11] = "AT+CGATT:1";
    if(strcmp(receviedAtCommand,NetworkDetached) == 0){
        return 0;
    }
    else if(strcmp(receviedAtCommand,NetworkAtached) == 1){
        return 1;
    }
    else{
        return 0;
    }
}*/


void bc95_test_IP_network_connectivity_to_remote_host(){



}
