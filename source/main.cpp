// \file: main.cpp
// \author: Robtagp
// \project: mise a jours c++ 01.05.25
#include <iostream>
#include <vector>
#include <string>
#include "Maintenance_Manager.hpp"


int main()
{
    Maintenance_Manager my_Maintenance_Manager;
    int Choice; 
    
    while(true)
    {
        std::cout << "Choose an Option (1,2,3 or 4): ";
        std::cin >> Choice;
        if(Choice == 1)
        {
            my_Maintenance_Manager.Add_New_Equipment();
        }
        else if(Choice == 2)
        {
            my_Maintenance_Manager.Display_Equipment_Data();
        }
        else if(Choice == 3)
        {
            my_Maintenance_Manager.Add_New_Intervention();
        }
        else if(Choice == 4)
        {
            my_Maintenance_Manager.Display_Interv_Data();
        }
        else if (Choice == 5)
        {
            std::cout << "You quit, GoodBye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Wrong Option"<< std::endl;
        }

        std::cin.ignore();   
    }

        return 0;

}




