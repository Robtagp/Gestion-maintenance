#include "Intervention.hpp"
#include <iostream>


Interventions::Interventions(const std::vector<std::string>& Interv_Infos)
    :m_Interv_Infos(Interv_Infos)
{

}

Interventions::Interventions()
{

}

std::string Interventions::To_String() const
{
    std::string result;
    for (size_t i = 0; i < m_Interv_Infos.size(); ++i) {
        result += m_Interv_Infos[i];
        if (i != m_Interv_Infos.size() - 1) {
            result += ",";
        }
    }
    return result;
}


std::vector <std::string> Interventions::Set_New_Intervention()
{

    std::vector<std::string> Ask_for = 
    {        
        "Equipment ID:",
        "Date:        ",
        "Description: ",
        "Employee:    ",
    };
    std::string input;

    m_Interv_Infos.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Register New Intervention :" << std::endl;
    for(const auto& Ask_for : Ask_for)
    {
        std::cout << Ask_for;
        std::getline(std::cin, input);
        m_Interv_Infos.push_back(input);
    }
    std::cout << "New Intervention Added" << std::endl;

    return m_Interv_Infos;
}


const std::vector<std::string>& Interventions::Get_Interv_Infos() const
{
    std::vector<std::string> Interv_Labels = 
    {
        "Equipment ID:",
        "Date:        ",
        "Description: ",
        "Employee:    ",
    };
    
    std::cout << "Intervention Infos :" << std::endl;
    for(int i = 0; i < m_Interv_Infos.size(); ++i)
    {
        std::cout << Interv_Labels[i] << m_Interv_Infos[i] << std::endl; 
    }

    return m_Interv_Infos;
}




