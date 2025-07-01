#include "Maintenance_Manager.hpp"
#include "Equipment.hpp"
#include "Intervention.hpp"
#include <iostream>




Maintenance_Manager::Maintenance_Manager(const std::vector<std::string>& Equipment_Data,const std::vector<std::string>& Interv_Data)
    : m_Equipment_Data(Equipment_Data),
      m_Interv_Data(Interv_Data)
{

}

Maintenance_Manager::Maintenance_Manager()
{
    
}


void Maintenance_Manager::Add_New_Equipment()
{
    Equipment my_Equipment;
    my_Equipment.Set_New_Gear();
    m_Equipment_Data.push_back(my_Equipment.To_String());
}

void Maintenance_Manager::Add_New_Intervention()
{
    Equipment my_Equipment;
    bool is_Found;
    Interventions my_Intervention;
    is_Found = my_Equipment.Find_Equipment_ID(*this);

    
    if(is_Found)
    {
        my_Intervention.Set_New_Intervention();
        m_Interv_Data.push_back(my_Intervention.To_String());
    }
    else
    {
        std::cout << "unable to add intervention"<< std::endl;
    }
    

}


const std::vector<std::string>& Maintenance_Manager::Display_Equipment_Data() const    
{
    for(int i = 0; i < m_Equipment_Data.size(); ++i)
    {
        std::cout << m_Equipment_Data[i] << std::endl; 
    }

    return m_Equipment_Data;
}

const std::vector<std::string>& Maintenance_Manager::Display_Interv_Data() const    
{
    for(int i = 0; i < m_Interv_Data.size(); ++i)
    {
        std::cout << m_Interv_Data[i] << std::endl; 
    }

    return m_Interv_Data;
}




const std::vector<std::string>& Maintenance_Manager::Return_m_Equipment_data() const
{
    return m_Equipment_Data;
}

const std::vector<std::string>& Maintenance_Manager::Return_m_Interv_Data() const
{
    return m_Interv_Data;
}




