/*
 * at_commands.h
 *
 *  Created on: 16 Jul 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_AT_COMMANDS_H_
#define INC_AT_COMMANDS_H_

const char* atCommandReady = "\r\nNeul\r\nOK\r\n";
const char* productInfo = "ATI";
const char* echoMode = "ATE";
const char* reqManufaturerId = "AT+CGMI";
const char* dateAndTime = "AT+CCLK";
const char* ping = "AT+NPING";
const char* connectionStatus = "AT+CSCON";


#endif /* INC_AT_COMMANDS_H_ */
