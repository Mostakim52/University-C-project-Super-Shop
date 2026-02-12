# 🏪 AGORA Super Shop Management System

A comprehensive C-based Super Shop Management System with complete inventory and employee management capabilities.

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Data Files](#data-files)
- [Team](#team)
- [License](#license)

## 🎯 Overview

AGORA Super Shop Management System is a console-based application designed to manage a super shop's daily operations. It provides a complete solution for managing inventory, employees, billing, and tracking profits.

## ✨ Features

### 📦 Item Management
| Feature | Description |
|---------|-------------|
| **Display Items** | View all items with name, quantity, price, manufacturer, and area |
| **Add Item** | Add new items to the inventory |
| **Delete Item** | Remove items from the inventory |
| **Update Item** | Modify item information (name, quantity, price, manufacturer, area) |
| **Search Item** | Search items by name with partial matching |
| **Low Quantity Alert** | View items with quantity ≤ 10 |
| **Area-based Search** | Find items in specific areas |

### 👥 Employee Management
| Feature | Description |
|---------|-------------|
| **Display Employees** | View all employees with details (name, DOB, area, join date, NID, salary) |
| **Add Employee** | Add new employees to the system |
| **Delete Employee** | Remove employees from the system |
| **Update Employee** | Modify employee information |
| **Search Employee** | Search employees by name |
| **Area-based Search** | Find employees working in specific areas |

### 💰 Billing & Finance
- **Billing System**: Create bills with multiple items, quantities, and total calculation
- **Profit Tracking**: View weekly profit reports

### 🎨 User Interface
- ASCII art welcome screen with animation
- Color-coded console output (cyan for welcome, yellow for menu)
- Formatted table displays for easy reading

## 📁 Project Structure

```
University-C-project-Super-Shop/
├── Project.c              # Main application source code
├── README.md              # Project documentation
├── intro.txt              # ASCII art animation file
├── items.txt              # Inventory data file
├── employees.txt          # Employee data file
├── profits.txt            # Profit data file
└── Project contributions.xlsx  # Team contributions tracking
```

## 🚀 Getting Started

### Prerequisites
- GCC Compiler (or any C compiler)
- Windows Operating System (uses `system("cls")` for clearing screen)

### Compilation & Running

```bash
# Navigate to the project directory
cd University-C-project-Super-Shop

# Compile the project
gcc Project.c -o Project.exe

# Run the application
./Project.exe
```

### Initial Setup
The program expects the following data files to exist:
- `items.txt` - Inventory records
- `employees.txt` - Employee records
- `profits.txt` - Weekly profit data
- `intro.txt` - Welcome animation

Sample file formats:

**items.txt:**
```
3

Item1
50
150.00
Manufacturer1
Warehouse-A

Item2
30
200.50
Manufacturer2
Warehouse-B
```

**employees.txt:**
```
2

John Doe
15/05/1990
Dhaka
01/01/2020
123456789012
25000

Jane Smith
20/08/1995
Chittagong
15/03/2021
987654321098
30000
```

## 📖 Usage

### Main Menu Options

| Option | Function |
|--------|----------|
| 1 | Display all items |
| 2 | Display all employees |
| 3 | Add a new item |
| 4 | Add a new employee |
| 5 | Delete an item |
| 6 | Delete an employee |
| 7 | Search for an item |
| 8 | Show low quantity items (≤10) |
| 9 | Search for an employee |
| 10 | Search items by area |
| 11 | Search employees by area |
| 12 | Change item information |
| 13 | Change employee information |
| 14 | Create a bill |
| 15 | View weekly profits |
| 16 | Exit the program |

### Key Functions

#### Billing System (Option 14)
1. Displays all available items
2. Prompts for number of items to purchase
3. Enter item serial numbers and quantities
4. Generates formatted bill with total
5. Updates inventory automatically

#### Low Quantity Alert (- Automatically identifiesOption 8)
 items with quantity ≤ 10
- Useful for inventory replenishment planning

## 👥 Team

This project was developed as a university group project by:

- **Orthy Soha** - [Facebook](https://www.facebook.com/orthy.soha)
- **Rezwan Karim Antor** - [Facebook](https://www.facebook.com/profile.php?id=100008637528824)
- **Tanzim Mostafa Opurbo** - [Facebook](https://www.facebook.com/opurbo.29.tmo)

## 📝 Notes

- All data is persisted in text files for easy backup and transfer
- The system uses case-insensitive searching for user convenience
- Input validation is implemented for most user inputs
- The program automatically saves changes to files after modifications

## 🔧 Technical Details

- **Language**: C
- **Data Storage**: Text files (CSV-like format)
- **Max Items**: 1000
- **Max Employees**: 1000
- **Compiler**: GCC/MinGW recommended

## 📄 License

This project is open source and available for educational purposes.
