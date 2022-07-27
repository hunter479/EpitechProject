/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** rfc
*/

#ifndef RFC_H_
    #define RFC_H_


//CE QUON ENVOIE
//420 "id:042:INFO"
//404 "id:404:ERROR"

// CE QUON RECOIT
// "120 = Signup"
// "130 = login"

//METHODE BDD pour contact (pas encore fini)

#define rfc_signup  "120"
#define rfc_login   "130"

#define rfc_add         "200"
#define rfc_check       "201"
#define rfc_getContact  "202"
#define rfc_updateStatus "290"
#define rfc_statusOff "210"
#define rfc_getCall "220"

#endif /* !RFC_H_ */
