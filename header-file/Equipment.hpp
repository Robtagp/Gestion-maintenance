#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Maintenance_Manager.hpp"

class Equipment
{
public:
    // Constructors
    Equipment();
    Equipment(const std::vector<std::string>& Gear_Infos, const bool& is_Found);

    // Equipment creation and representation
    std::vector<std::string> Set_New_Gear();
    std::string To_String() const;

    // Equipment identification
    bool Find_Equipment_ID(Maintenance_Manager& my_Maintenance_Manager);

private:
    std::vector<std::string> m_Gear_infos;
    bool m_is_Found;
};







