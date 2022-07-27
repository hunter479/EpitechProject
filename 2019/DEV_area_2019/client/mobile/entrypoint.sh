#!/bin/bash

function copy_to_dest()
{
    cp /app/apk/client.apk /apk/client.apk
}

function build_apk()
{
    python3.7 -m http.server --directory dist &> /dev/null &
    sleep 1
    turtle build:android --type apk --public-url http://127.0.0.1:8000/android-index.json --output /app/apk/client.apk
    $(pkill python3.7)
}

function redo_file()
{
    if [ -f "/apk/client.apk" ]; then
        rm /apk/client.apk
        build_apk
        copy_to_dest
    else
        if [ -f "/app/apk/client.apk" ]; then
            rm /app/apk/client.apk
            build_apk
        else
            build_apk
        fi
        copy_to_dest
    fi
}

function get_file()
{
    if [ ! -f "/apk/client.apk" ]; then
        if [ ! -f "/app/apk/client.apk" ]; then
            build_apk
            copy_to_dest
        else
            copy_to_dest
        fi
    fi
}

if [ "$1" == "build" ]; then
    echo "Building the APK"
    redo_file
else
    echo "Retrieveing the APK"
    get_file
fi