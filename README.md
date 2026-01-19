# Project Management CRM (C++ Console Application)

A menu-driven **Project Management CRM system** built using **C++** that manages team members, projects, and project-to-team assignments using **binary file handling**.  
This application demonstrates foundational **Object-Oriented Programming (OOP)** concepts and persistent data storage in a console environment.

---

## Features


### 👥 Team Member Management
- Add new team members  
- View all team members in tabular format  
- Edit existing team member details  
- Delete team members (with backup to trash file)

### 📁 Project Management
- Add and display projects  
- Edit and delete project records  
- Assign projects to teams  

### 🔗 Project–Team Mapping
- Maintains project-to-team relationships using a dedicated mapping class  
- Ensures separation of concerns and better data organization  

### 🔄 Database Reset
- Clears all stored data files  
- Useful for testing and fresh starts  

---

## 🧠 Concepts Demonstrated

- Object-Oriented Programming (Classes and Objects)
- Binary file handling (`ifstream`, `ofstream`, `fstream`)
- CRUD operations
- Menu-driven console UI
- Data persistence
- Basic relational modeling

---

## 🛠️ Technology Stack

- **Language:** C++  
- **Compiler:** Turbo C++ / Borland C++ (legacy compatible)  
- **Libraries Used:**
  - `<iostream.h>`
  - `<fstream.h>`
  - `<iomanip.h>`
  - `<conio.h>`
  - `<stdlib.h>`

> ⚠️ Note: This project uses legacy headers for compatibility with Turbo C++.

---


## 🧱 Class Design

### TeamMember
Handles all operations related to team members:
- Team ID, Name, Mobile, Skill Set, Role
- Add, display, edit, and delete operations

### Project
Manages project information:
- Project code, customer name, project dates
- Project assignment to teams
- Full CRUD support

### ProjectTeam
Acts as a relational bridge between projects and teams:
- Stores project code and team ID pairs

---

## ▶️ How to Run

1. Open **Turbo C++ / Borland C++**
2. Create a new project
3. Paste the source code into `main.cpp`
4. Compile and run the program
5. Navigate using numeric menu options

---

## 📸 Sample Workflow

1. Add team members  
2. Create projects  
3. Assign projects to teams  
4. View assigned projects  
5. Edit or delete records as needed  

---

## 📈 Possible Improvements

- Upgrade to modern C++ (`<iostream>`, `string`, STL)
- Replace static arrays with dynamic memory allocation
- Support multiple team members per project
- Add search and filtering functionality
- Implement authentication and role-based access
- Convert to GUI or web-based application

---

## 🎓 Academic Relevance

This project is suitable for:
- C++ mini and major projects
- File handling demonstrations
- Object-Oriented Programming practical exams
- Beginner-level software development portfolios

---

## 👤 Author

Developed as a **C++ academic project** focused on demonstrating object-oriented programming and binary file-handling techniques.

⭐ If you find this project useful, consider starring the repository!


