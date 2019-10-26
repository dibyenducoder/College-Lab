#!/bin/bash

while true; 
	do
        read -p "BCSE!!> "  command;        
        for word in $command
        do
                options=${command//$word/}
                if [ $word == "dirnew" ]
                then
                        mkdir $options
                elif [ $word == "editfile" ]
                then
                        vi $options
                elif [ $word == "info" ]
                then
                        ls -l $options
                elif [ $word == "exitnewshell" ]
                then
                        exit                  
                else
                        printf "%s: Command not found\n" $word
                fi                              
                break
        done
done
exit
