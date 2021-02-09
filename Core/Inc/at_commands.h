/*
 * at_commands.h
 *
 *  Created on: 16 Jul 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_AT_COMMANDS_H_
#define INC_AT_COMMANDS_H_

const char* atCommandReady ;
const char* productInfo ;
const char* echoMode  ;
const char* reqManufaturerId ;
const char* dateAndTime ;
const char* ping ;
const char* connectionStatus ;
const char* configureUeBehaviour ;
const char* rebootModule ;
const char* functionality ;
const char* eDrxMode ;
const char* trigNetworkAttachment ;

typedef enum  {

    EC_GSM_IoT = 0,
    GSM,
    UTRAN,
    E_UTRAN1,
    E_UTRAN2

}AotTypeEdrx;


#endif /* INC_AT_COMMANDS_H_ */
