#!/bin/bash
MY_LINE1=19
MY_LINE2=42
cut -d":" -f 1 | sed -n "2~2p"  | rev | sort -r | head -n "$MY_LINE2" | tail -n "$MY_LINE1" | paste -sd " " |  sed -e "s/\>/,/g" | sed -e "s/,$/./g"  
 
