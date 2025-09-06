# Maintenance Management System

A C++ console application for managing equipment and interventions, with CSV file support.

## Features

- Add new equipment
- Display all equipment
- Add new interventions (linked to equipment)
- Display all interventions
- Save equipment and interventions to CSV files
- Load equipment and interventions from CSV files

## Build Instructions

```sh
g++ -std=c++17 -o gestion_maintenance source/main.cpp source/Maintenance_Manager.cpp source/Equipment.cpp source/Intervention.cpp
```

## Run

```sh
./gestion_maintenance
```

## Usage

Follow the menu in the console to manage your equipment and interventions.

## Author

Robtagp
