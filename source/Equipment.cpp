#include "Equipment.hpp"
#include "Maintenance_Manager.hpp"
#include <iostream>
#include <limits>

// --- Constructors ---

// Constructs an equipment with given info and found status
Equipment::Equipment(const std::vector<std::string>& Gear_Infos, const bool& is_Found)
    : m_Gear_infos(Gear_Infos),
      m_is_Found(is_Found)
{
}

// Default constructor
Equipment::Equipment()
{
}

// --- Equipment Representation ---

// Converts equipment info to a CSV-formatted string
std::string Equipment::To_String() const
{
    std::string result;
    for (size_t i = 0; i < m_Gear_infos.size(); ++i) {
        result += m_Gear_infos[i];
        if (i != m_Gear_infos.size() - 1) {
            result += ",";
        }
    }
    return result;
}

// Creates a new equipment by asking user for input
std::vector<std::string> Equipment::Set_New_Gear()
{
    std::vector<std::string> Ask_for = {
        "Equipment ID: ",
        "Brand:        ",
        "Date:         ",
    };
    std::string input;

    m_Gear_infos.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter New Piece Of Gear References:" << std::endl;

    for (const auto& prompt : Ask_for)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        m_Gear_infos.push_back(input);
    }
    std::cout << "New Gear Registered" << std::endl;

    return m_Gear_infos;
}

// --- Equipment Identification ---

// Searches for an equipment ID in the manager's equipment data
bool Equipment::Find_Equipment_ID(Maintenance_Manager& my_Maintenance_Manager)
{
    size_t pos;
    m_is_Found = false;
    std::string IdRecherche;
    std::vector<std::string> Copy_mEquipment_Data;

    Copy_mEquipment_Data = my_Maintenance_Manager.Return_m_Equipment_data();
    std::cout << "Search For Equipment ID: ";
    std::cin >> IdRecherche;

    for (int i = 0; i < Copy_mEquipment_Data.size(); ++i)
    {
        if (Copy_mEquipment_Data[i].find(",") != std::string::npos)
        {
            pos = Copy_mEquipment_Data[i].find(",");
            if (IdRecherche == Copy_mEquipment_Data[i].substr(0, pos))
            {
                std::cout << "Equipment Found: " << Copy_mEquipment_Data[i] << std::endl;
                m_is_Found = true;
            }
        }
    }

    if (!m_is_Found)
    {
        std::cout << "No Equipment Found :( " << std::endl;
    }
    return m_is_Found;
}


