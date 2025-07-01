#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Maintenance_Manager.hpp>


class Equipment
{
    public:
    Equipment();
    Equipment(const std::vector<std::string>& Gear_Infos,const bool& is_Found);
    
    std::vector<std::string> Set_New_Gear();
    std::string To_String() const;

    bool Find_Equipment_ID(Maintenance_Manager& my_Maintenance_Manager);
    
    private:
    
    std::vector<std::string> m_Gear_infos;
    bool m_is_Found;
    
};







