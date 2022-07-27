#!/bin/bash
blih -u nicolas.ah-leung@epitech.eu repository create "$1"
blih -u nicolas.ah-leung@epitech.eu repository setacl "$1" ramassage-tek r
blih -u nicolas.ah-leung@epitech.eu repository getacl "$1"
