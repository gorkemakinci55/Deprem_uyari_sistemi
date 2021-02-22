/*
 * at_commands.cpp
 *
 *  Created on: 21 Nov 2020
 *      Author: gorkem.akinci
 */


#include "at_commands.h"


const char* atCommandReady = "Neul \r\n";
const char* productInfo = "ATI";
const char* echoMode = "ATE";
const char* reqManufaturerId = "AT+CGMI";
const char* dateAndTime = "AT+CCLK";
const char* ping = "AT+NPING";
const char* connectionStatus = "AT+CSCON";
const char* configureUeBehaviour = "AT+NCONFIG";
const char* rebootModule = "AT+NRB";
const char* functionality = "AT+CFUN";
const char* eDrxMode = "AT+CEDRXS";
const char* trigNetworkAttachment = "AT+CGATT";
