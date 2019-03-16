#!/bin/bash
# The line above makes your script executable.
# You should write your tutorial in here.
# Include comments inline with your script explaining what is going on.

# You might start out by first saying the purpose of the script and
# demonstrating its usage.


##Bradford Egan
##Spring 2019
##Systems
##Mike Shaw


## Specific Usage:  sh addDatetime.sh gdax-BTCUSD-1h
## General Usage: sh addDatetime.sh "filename"


## Do not include file extension as a arguement.

## My script is intended to help me orgnize my CSV files of trading data.
## I have a lot of CSVs coming into a /Data folder, hour by hour with a generic
## name and I needed someway to organize them as they were all being saved
## to the file name. I wrote a python script (not included) that grabs
## hourly market data from a given exchange and saves it to a CSV file. It does
## this for every trading pair (aprox 39 pairs on the GDAX exchange) and writes to
## my local /Data folder. 

## The datafiles come in in CSV format, with the following header structure:
## Timestamp, Open, High, Low, Close, Volume inside the file. It is saved as 
## something generic like "gdax-BTCUSD-1h.csv" but I have no way of knowing what
## date / time the CSV file corresponds with without opening the file and checking
## the timestamp. The UNIX timestamp in each row corresponds to a particular hour
## of trading data. I decided to make a script that can grab the first timestamp, ## i.e. the hour the trading data begins at, and append it to the filename.
## Now Ill be able to tell exactly what hour the trading data begins at.
## Yes it is in UNIX time but this is what I desire because it will make it
## easy to search for particular trading data times.

## A CSV file will look something like this:
## Timestamp,Open,High,Low,Close,Volume
## 1551405600000,50.82,50.9,50.77,50.84,65.68
## 1551409200000,50.79,51.08,50.75,50.99,63.69
## 1551412800000,50.98,51.18,50.89,50.97,138.93
## 1551416400000,50.99,51.25,50.97,51.19,148.2
## 1551420000000,51.08,51.27,50.99,50.99,139.37
## 1551423600000,51.07,51.14,50.67,50.97,358.91
## 1551427200000,50.97,51.19,50.95,51.12,103.2
## 1551430800000,51.13,51.48,51.13,51.4,46.84

## Therefore I created this simple BASH script to go into the CSV file and grab
## the first Timestamp where the trading data starts at.

## I load the filename into a variable named file to begin with.
## Then I find second row of the CSV (which cuts off the uneeeded headers on row
## 1. Next I cut off the first 13 characters of the row, which is exactly 
## equivalent to the millisecond version of the UNIX timestamp. UNIX timestamp
## simply the ammount of seconds (10 digit) or milliseconds (13 digit) passed 
## since  00:00:00 Thursday, 1 January 1970, Coordinated Universal Time (UTC).
## At first I was appending normal datetime format but it makes much more sense
## to stick with a UNIX timestamp appended to the filename.

## Script next echos out the timestamp grabbed, and then appends it to a filename
## and then outputs this file.

## Ill probably be using this BASH file for my trading bot to help organize
## the constant influx of CSV market data I receive. I needed to help organize
## the CSVs someway and this BASH script will be great for such a use. Outputs
## a duplicate CSV with datetime added, so I'm sure to preserve original file, 
## for later archival purposes.
 
## Will be useful in preparing data for use on ML algorithms. Using this BASH
## script will make my life a lot easier when I try to keep track of CSV files.
## Now I can grab all market data for a given crypto exchange, organize CSVs 
## (thanks to my BASH script), train it on a series of algorithms /
## Machine Learning models, and predict output. Currently have a python script
## grabbing data, and training on a neural network, and need to just 
## update it to be able to make predictions on current market data. Then I
## simply need hook in the trading code and I should be good to go.





file="$1.csv"

timestamp=$(awk 'NR==2{print $1; exit}' $1.csv);
timestamp1=$( echo ${timestamp:0:13})


echo "Timestamp is: $timestamp1";
 
new_file=$1-$timestamp1.csv
echo "New FileName: " "$new_file"
 
cp $file $new_file
echo "Timestamp added to file."

