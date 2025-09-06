// \file: main.cpp
// \author: Robtagp
// \project: mise a jours c++ 01.05.25
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Maintenance_Manager.hpp"


int main()
{
    Maintenance_Manager my_Maintenance_Manager;
    int Choice;

    std::cout << "=== Maintenance Management System ===" << std::endl;

    while (true)
    {
        std::cout << "\nChoose an Option:\n";
        std::cout << "1 - Add New Equipment\n";
        std::cout << "2 - Display Equipments\n";
        std::cout << "3 - Add New Intervention\n";
        std::cout << "4 - Display Interventions\n";
        std::cout << "5 - Save to CSV file\n";
        std::cout << "6 - Load CSV file\n";
        std::cout << "7 - Quit\n";
        std::cout << "Your choice: ";

        std::cin >> Choice;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (Choice == 1)
        {
            my_Maintenance_Manager.Add_New_Equipment();
        }
        else if (Choice == 2)
        {
            my_Maintenance_Manager.Display_Equipment_Data();
        }
        else if (Choice == 3)
        {
            my_Maintenance_Manager.Add_New_Intervention();
        }
        else if (Choice == 4)
        {
            my_Maintenance_Manager.Display_Interv_Data();
        }
        else if (Choice == 5)
        {
            my_Maintenance_Manager.Save_All_To_CSV();
            std::cout << "Data saved to CSV files." << std::endl;
        }
        else if (Choice == 6)
        {
            my_Maintenance_Manager.Load_All_From_CSV();
            std::cout << "Data loaded from CSV files." << std::endl;
        }
        else if (Choice == 7)
        {
            std::cout << "You quit, GoodBye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Wrong Option. Please enter a number between 1 and 7." << std::endl;
        }
    }

    return 0;
}




