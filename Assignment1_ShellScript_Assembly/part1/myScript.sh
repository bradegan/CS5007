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


## My script is intended to make a copy of given CSV file and normalize data by
## column. Will loop through columns, find min and max of columns data, and use 
## this to normalize all of repective columns data to between 0 and 1. Prepares
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
 
#current_time=$(date "+%Y.%m.%d-%H.%M.%S")

##rename 's/\.csv+/current_time.csv/' *


#awk 'NR==2{print $2} ' Old_file > New_file
 
current_time=$(date "+%Y.%m.%d-%H.%M.%S")
echo "Time is: $current_time"
 
new_file=$1.$current_time
echo "New FileName: " "$new_file"
 
cp $file $new_file.csv
#echo "Timestamp added to file."

