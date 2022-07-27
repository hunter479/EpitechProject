/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** rfc
*/

#ifndef RFC_H_
    #define RFC_H_

#define rfc_120 "120 Service ready in 1 minutes.\r\n"
#define rfc_125 "125 Data connection already open; transfer starting.\r\n"
#define rfc_150 "150 File status okay; about to open data connection.\r\n"
#define rfc_200 "200 Command okay.\r\n"
#define rfc_214 "214 HELP\r\n"
#define rfc_220 "220 Service ready for new user.\r\n"
#define rfc_221 "221 Service closing control connection.\r\n"
#define rfc_226 "226 Closing data connection.\r\n"
#define rfc_227 "227 Entering Passive Mode (%s,%d,%d).\r\n"
#define rfc_230 "230 User logged in, proceed.\r\n"
#define rfc_250 "250 Requested file action okay, completed.\r\n"
#define rfc_257 "257 \"%s\"\r\n"
#define rfc_331 "331 Please specify the password.\r\n"
#define rfc_332 "332 Need account for login.\r\n"
#define rfc_421 "421 Service not available, closing control connection.\r\n"
#define rfc_425 "425 Use PORT or PASV first.\r\n"
#define rfc_450 "450 Requested file action not taken.\r\n"
#define rfc_500 "500 Command not implemented.\r\n"
#define rfc_501 "501 Syntax error in parameters or arguments."
#define rfc_503 "503 Login with USER first.\r\n"
#define rfc_530 "530 Not logged in.\r\n"
#define rfc_550 "550 Can't access this directory.\r\n"
#define rfc_XXX "XXX Error.\r\n"

#endif /* !RFC_H_ */
