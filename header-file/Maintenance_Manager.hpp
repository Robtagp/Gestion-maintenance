#pragma once
#include <iostream>
#include <vector>
#include <string>

class Maintenance_Manager
{
public:
    // Constructors
    Maintenance_Manager();
    Maintenance_Manager(const std::vector<std::string>& Equipment_Data, const std::vector<std::string>& Interv_Data);

    // Equipment management
    void Add_New_Equipment();
    const std::vector<std::string>& Display_Equipment_Data() const;
    const std::vector<std::string>& Return_m_Equipment_data() const;

    // Intervention management
    void Add_New_Intervention();
    const std::vector<std::string>& Display_Interv_Data() const;
    const std::vector<std::string>& Return_m_Interv_Data() const;

    // CSV operations
    void Save_All_To_CSV() const;
    void Load_All_From_CSV();
    void Save_Equipments_To_CSV(const std::string& filename) const;
    void Load_Equipments_From_CSV(const std::string& filename);
    void Save_Interventions_To_CSV(const std::string& filename) const;
    void Load_Interventions_From_CSV(const std::string& filename);

private:
    std::vector<std::string> m_Equipment_Data;
    std::vector<std::string> m_Interv_Data;
};

