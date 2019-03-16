#!/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.
##Bradford Egan
##Spring 2019
##Systems
##Mike


## My script is intended to help me orgnize my CSV files of trading data.
## I have a lot of CSVs coming into a /Data folder, hour by hour with a generic
## name and I needed someway to organize them.  Prepares
## data for use on ML algorithms.
## USAGE: ./myScript.sh  "gdax-BCHBTC-1h"


## First arguement
#cp "$1.csv" "$1_NORMALIZED.csv"
#max =0
#cat "$1_NORMALIZED.csv"|while IFS=, read -r col1 col2
 # do
  #  read -d, col1 col2 < <(echo $line)
   # echo "I got:$col1|$col2"
#  done 



file="$1.csv"

timestamp=$(awk 'NR==2{print $1; exit}' $1.csv);
timestamp1=$( echo ${timestamp:0:13})
#price = awk 'NR==2{print $2}' st="${1}" $1.csv;

echo $timestamp1;
 
#current_time=$(date "+%Y.%m.%d-%H.%M.%S")

##rename 's/\.csv+/current_time.csv/' *


#awk 'NR==2{print $2} ' Old_file > New_file
#current_time=$("$timestamp1")

##current_time=$(date "+%Y.%m.%d-%H.%M.%S")
#echo "Time is: $current_time"
 
new_file=$1.$timestamp1.csv
echo "New FileName: " "$new_file"
 
cp $file $new_file
#echo "Timestamp added to file."

