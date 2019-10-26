#!/bin/bash
while true; 
	do
        read -p "BCSE!!> "  com;        
        for word in $com
        do
                options=${com//$word/}
                if [ $word == "dirnew" ]
                then
			if [ $# -eq 0 ]
			then 
				options="new"
			fi
                        mkdir $options
                elif [ $word == "editfile" ]
                then
                        vi $options
                elif [ $word == "info" ]
                then
                        ls -l $options
                elif [ $word == "exitnewshell" ]
                then
                        echo "Closing......"
			echo "Thank You"   
			exit 1               
                else
                        printf "%s: Command not found\n" $word
                fi                              
                break
        done
done


