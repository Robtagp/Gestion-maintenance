#pragma once
#include <iostream>
#include <vector>
#include <string>

class Interventions
{
public:
    // Constructors
    Interventions();
    Interventions(const std::vector<std::string>& Interv_Infos);

    // Intervention representation
    std::string To_String() const;

    // Intervention creation
    std::vector<std::string> Set_New_Intervention();
    std::vector<std::string> Set_New_Intervention(const std::vector<std::string>& valid_ids);

    // Accessor
    const std::vector<std::string>& Get_Interv_Infos() const;

private:
    std::vector<std::string> m_Interv_Infos;

    
};







