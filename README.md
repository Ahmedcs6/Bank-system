# Bank System

A simple C++ banking system project with file-based storage and terminal interface.
this project required from mr Mohamed Abuhdhoud Course 7 but i built it with oop paradigm
---

## Project Structure

```
.
├── CMakeLists.txt             # CMake configuration file
├── build
│   ├── clients.txt            # Database file storing clients info
│   ├── mainMenu.txt           # Text layout for main menu
│   └── transactionsMenu.txt   # Text layout for transactions menu
├── include
│   └── include.h              # Header file
└── src
    └── main.cpp               # Main application source code
```
---

## Build Instructions (CMake)

### Requirements:
- A C++ compiler (like `g++`)
- CMake

### Steps to build:

```bash
# Step 1: Generate build files with CMake
cd build
cmake ..

# Step 4: Compile the project
make
```

This will create an executable file (`Bank`) inside the `build/` folder.

---

##  How to Run

After building the project:

```bash
./Bank
```

 **Make sure these files are in the same directory when running:**
- `clients.txt`
- `mainMenu.txt`
- `transactionsMenu.txt`

---

## Features

- Simple CLI interface
- Create and manage bank accounts
- Perform basic transactions
- Store and load client data from file
- Menu layout loaded from external `.txt` files

---

## Author

**Ahmed Mahmoud**  
[GitHub: @AhmedCs6](https://github.com/AhmedCs6)

