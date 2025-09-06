#include "Maintenance_Manager.hpp"
#include "Equipment.hpp"
#include "Intervention.hpp"
#include <iostream>
#include <fstream>

// --- Constructors ---

// Constructs a manager with existing equipment and intervention data
Maintenance_Manager::Maintenance_Manager(const std::vector<std::string>& Equipment_Data, const std::vector<std::string>& Interv_Data)
    : m_Equipment_Data(Equipment_Data),
      m_Interv_Data(Interv_Data)
{
}

// Default constructor
Maintenance_Manager::Maintenance_Manager()
{
}

// --- Equipment Management ---

// Adds a new equipment to the list and stores it in memory
void Maintenance_Manager::Add_New_Equipment()
{
    Equipment my_Equipment;
    my_Equipment.Set_New_Gear();
    m_Equipment_Data.push_back(my_Equipment.To_String());
}

// Displays all registered equipment
const std::vector<std::string>& Maintenance_Manager::Display_Equipment_Data() const    
{
    for (int i = 0; i < m_Equipment_Data.size(); ++i)
    {
        std::cout << m_Equipment_Data[i] << std::endl; 
    }
    return m_Equipment_Data;
}

// Returns the equipment list (for internal use)
const std::vector<std::string>& Maintenance_Manager::Return_m_Equipment_data() const
{
    return m_Equipment_Data;
}

// --- Intervention Management ---

// Adds a new intervention to the list and stores it in memory
void Maintenance_Manager::Add_New_Intervention()
{
    Interventions my_Intervention;
    // Prepare the list of valid equipment IDs from existing equipment
    std::vector<std::string> valid_ids;
    for (const auto& equip_str : m_Equipment_Data) {
        size_t pos = equip_str.find(',');
        if (pos != std::string::npos)
            valid_ids.push_back(equip_str.substr(0, pos));
    }
    my_Intervention.Set_New_Intervention(valid_ids);
    m_Interv_Data.push_back(my_Intervention.To_String());
}

// Displays all registered interventions
const std::vector<std::string>& Maintenance_Manager::Display_Interv_Data() const    
{
    for (int i = 0; i < m_Interv_Data.size(); ++i)
    {
        std::cout << m_Interv_Data[i] << std::endl; 
    }
    return m_Interv_Data;
}

// Returns the intervention list (for internal use)
const std::vector<std::string>& Maintenance_Manager::Return_m_Interv_Data() const
{
    return m_Interv_Data;
}

// --- CSV File Operations ---

// Saves all equipment and interventions to their respective CSV files
void Maintenance_Manager::Save_All_To_CSV() const
{
    Save_Equipments_To_CSV("equipements.csv");
    Save_Interventions_To_CSV("interventions.csv");
}

// Loads all equipment and interventions from their respective CSV files
void Maintenance_Manager::Load_All_From_CSV()
{
    Load_Equipments_From_CSV("equipements.csv");
    Load_Interventions_From_CSV("interventions.csv");
}

// Saves the equipment list to a CSV file
void Maintenance_Manager::Save_Equipments_To_CSV(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file) { std::cerr << "Error opening " << filename << std::endl; return; }
    file << "Equipment ID,Brand,Date\n";
    for (const auto& equip_str : m_Equipment_Data) file << equip_str << "\n";
    file.close();
}

// Loads the equipment list from a CSV file
void Maintenance_Manager::Load_Equipments_From_CSV(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) { std::cerr << "Error opening " << filename << std::endl; return; }
    m_Equipment_Data.clear();
    std::string line; bool first_line = true;
    while (std::getline(file, line)) {
        if (first_line) { first_line = false; continue; }
        if (!line.empty()) m_Equipment_Data.push_back(line);
    }
    file.close();
}

// Saves the intervention list to a CSV file
void Maintenance_Manager::Save_Interventions_To_CSV(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file) { std::cerr << "Error opening " << filename << std::endl; return; }
    file << "Equipment ID,Date,Description,Employee\n";
    for (const auto& interv_str : m_Interv_Data) file << interv_str << "\n";
    file.close();
}

// Loads the intervention list from a CSV file
void Maintenance_Manager::Load_Interventions_From_CSV(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file) { std::cerr << "Error opening " << filename << std::endl; return; }
    m_Interv_Data.clear();
    std::string line; bool first_line = true;
    while (std::getline(file, line)) {
        if (first_line) { first_line = false; continue; }
        if (!line.empty()) m_Interv_Data.push_back(line);
    }
    file.close();
}




