#!/bin/sh

crt_dir="certs"
##CA##
ca_name=area-ca
##CERT##
cert_name=area

function gen_ca {
    printf "Area CA\n"
    printf "Private Key\n"
    openssl genrsa -out "$ca_name".key 4096

    printf "\nRequest\n"
    openssl req -new -config "$ca_name".config -key "$ca_name".key -out "$ca_name".csr

    printf "\nExtension\n"
    openssl x509 -days 365 -signkey "$ca_name".key -in "$ca_name".csr -extfile "$ca_name".ext -req -out "$ca_name".crt
}

function gen_cert {
    printf "\nArea CERT\n"
    printf "Private Key\n"
    openssl genrsa -out "$cert_name".key 4096

    printf "\nRequest\n"
    openssl req -new -config "$cert_name".config -key "$cert_name".key -out "$cert_name".csr

    printf "\nExtension\n"
    openssl x509 -days 365 -extfile "$cert_name".ext -CA "$ca_name".crt -CAkey "$ca_name".key -in "$cert_name".csr -req -out "$cert_name".crt -set_serial 1
}

function gen_dhparam {
    openssl dhparam -out dhparam.pem 2048
}

gen_ca
gen_cert
gen_dhparam
mkdir $crt_dir
mv dhparam.pem $crt_dir
mv *.crt $crt_dir
mv *.csr $crt_dir
mv *.key $crt_dir