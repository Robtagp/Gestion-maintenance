#include "Intervention.hpp"
#include "Equipment.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

// --- Constructors ---

Interventions::Interventions(const std::vector<std::string>& Interv_Infos)
    : m_Interv_Infos(Interv_Infos)
{
}

Interventions::Interventions()
{
}

// --- Intervention Representation ---

// Converts intervention info to a CSV-formatted string
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

// --- Intervention Creation ---

// Creates a new intervention with equipment ID validation
std::vector<std::string> Interventions::Set_New_Intervention(const std::vector<std::string>& valid_ids)
{
    std::vector<std::string> Ask_for = {
        "Equipment ID:",
        "Date:        ",
        "Description: ",
        "Employee:    ",
    };
    std::string input;

    m_Interv_Infos.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Register New Intervention :" << std::endl;

    // Equipment ID input and validation
    bool id_ok = false;
    do {
        std::cout << Ask_for[0];
        std::getline(std::cin, input);
        id_ok = std::find(valid_ids.begin(), valid_ids.end(), input) != valid_ids.end();
        if (!id_ok) {
            std::cout << "Unknown equipment ID, please try again." << std::endl;
        }
    } while (!id_ok);
    m_Interv_Infos.push_back(input);

    // Input for other fields
    for (size_t i = 1; i < Ask_for.size(); ++i)
    {
        std::cout << Ask_for[i];
        std::getline(std::cin, input);
        m_Interv_Infos.push_back(input);
    }
    std::cout << "New Intervention Added" << std::endl;

    return m_Interv_Infos;
}

// --- Accessor ---

// Displays intervention info with labels and returns the info vector
const std::vector<std::string>& Interventions::Get_Interv_Infos() const
{
    std::vector<std::string> Interv_Labels = {
        "Equipment ID:",
        "Date:        ",
        "Description: ",
        "Employee:    ",
    };

    std::cout << "Intervention Infos :" << std::endl;
    for (int i = 0; i < m_Interv_Infos.size(); ++i)
    {
        std::cout << Interv_Labels[i] << m_Interv_Infos[i] << std::endl;
    }

    return m_Interv_Infos;
}




