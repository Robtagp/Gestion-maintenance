#pragma once
#include <iostream>
#include <vector>
#include <string>



class Maintenance_Manager
{
    public:
    Maintenance_Manager();
    Maintenance_Manager(const std::vector<std::string>& Equipment_Data,const std::vector<std::string>& Interv_Data);
   

    void Add_New_Equipment();
    void Add_New_Intervention();

    const std::vector<std::string>& Display_Equipment_Data() const;
    const std::vector<std::string>& Return_m_Equipment_data() const;

    const std::vector<std::string>& Display_Interv_Data() const;
    const std::vector<std::string>& Return_m_Interv_Data() const;    



    private:

    std::vector<std::string> m_Equipment_Data;
    std::vector<std::string> m_Interv_Data;




};

