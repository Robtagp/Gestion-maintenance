#pragma once
#include <iostream>
#include <vector>
#include <string>


class Interventions
{
    public:
    Interventions();
    Interventions(const std::vector<std::string>& Interv_Infos);

    std::string To_String() const;
    std::vector<std::string> Set_New_Intervention();
    
    const std::vector<std::string>& Get_Interv_Infos() const;

    private:
    std::vector<std::string> m_Interv_Infos;

    
};







