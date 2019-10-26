#!/bin/bash

j="y"

while [ $j = "y" ]
do

        #i="y"

        read -p "Enter first content "  userv1
        read -p "Enter second content " userv2

        if [[ $userv1 == [a-zA-Z] ]] || [[ $userv2 == [a-zA-Z] ]]; then
        echo "Non numeric input variable"
        exit
        fi

        i=1
        choice=0
        
        while [ $i ]
        do
                echo "1.Add :"
                echo "2.Substruct :"
                echo "3.Multiplication :"
                echo "4.Division :"
                #echo "Enter Your Choice :"
                choice=$((choice+1))
                
                lim=5
                if [ $choice -ge $lim ];
                then
                        break
                
                #read choice
                else 
                        case "$choice" in 
                                "1")

                                  echo -n  "addition of userv1 and userv2 = "
                                  awk "BEGIN {print ($userv1+$userv2)}"

                                  echo -n  "addition of userv2 and userv1 = "
                                  awk "BEGIN {print ($userv2+$userv1)}"
                                  
                                  ;;

                                "2")

                                  echo -n "substruction of userv1 and userv2 =  "
                                  awk "BEGIN {print ($userv1-$userv2)}"

                                  echo -n "substruction of userv2 and userv1 =  "
                                  awk "BEGIN {print ($userv2-$userv1)}"
                                  ;;

                                "3")
                                  
                                  echo -n "multiplication of userv1 and userv2 = "
                                  awk "BEGIN {print ($userv1*$userv2)}"

                                  echo -n "multiplication of userv2 and userv1 = "
                                  awk "BEGIN {print ($userv2*$userv1)}"
                                  ;;

                                "4")
                #div=$( echo " $a/$b " | bc -l)
                                  if [ "$userv2" -eq 0 ]; 
                                  then
                                          echo "Division by 0 not possible "
                                          
                                 else 
                                        echo -n "Division of userv1 and userv2  = "
                                        awk "BEGIN {print ($userv1/$userv2)}"
                                fi

                                if [ "$userv1" -eq 0 ]; then
                                        
                                        
                                          echo "Division by 0 not possible "
                                          
                                 else 
                                        echo -n "Division of userv2 and userv1  = "
                                        awk "BEGIN {print ($userv2/$userv1)}"
                                fi

                                  ;;

                                *)echo "Wrong choice "
                                ;;

                        esac

                        sleep 1
                fi
                
        done 
        echo "Thank You !"

        echo "Do you want to continue to input ?"
        echo "Press y for Yes and any other key to exit the program "
                read j 

                if [ $j != "y" ]
                then 
                        exit
                fi
done



