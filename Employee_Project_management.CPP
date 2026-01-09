#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdio.h>
#include <iomanip.h>
#include <stdlib.h>
class ProjectTeam;
class TeamMember
{
    int teamid;
    char fullname[20];
    char mobile[20];
    char skillset[20];
    char role[20];

public:
    void getData();
    void heading();
    void showData();
    void addTeamMember();
    void displayTeamMember();
    void editTeamMember();
    void deleteTeamMember();
    int get()
    {
        return teamid;
    }
};

class Project
{
    int pcode, tid;
    char custname[20];
    char projectname[20];
    char startdate[20];
    char enddate[20];

public:
    void getData();
    void heading();
    void showData();
    void addProject();
    void displayProject();
    void assignProject();
    void editProject();
    void deleteProject();
    void assign(int);
    void disassign();
    int get()
    {
        return pcode;
    }
};

class ProjectTeam
{
    int procd, tmid;

public:
    ProjectTeam() {}
    ProjectTeam(int x, int y)
    {
        procd = x;
        tmid = y;
    }
    void show()
    {
        cout << "Project id" << procd;
        cout << "Team id" << tmid;
    }
};

void TeamMember ::getData()
{
    cout << "Enter ID: ";
    cin >> teamid;
    cout << "\nEnter Full Name: ";
    cin.ignore();
    cin.get(fullname, 20);
    cout << "\nEnter Mobile: ";
    cin.ignore();
    cin.get(mobile, 20);
    cout << "\nEnter Skill Set: ";
    cin.ignore();
    cin.get(skillset, 20);
    cout << "\nEnter Role: ";
    cin.ignore();
    cin.get(role, 20);
}
void TeamMember ::showData()
{
    cout.setf(ios::left);
    cout << setw(7) << teamid;
    cout << setw(15) << fullname;
    cout << setw(15) << mobile;
    cout << setw(15) << skillset;
    cout << setw(15) << role << endl;
}
void TeamMember ::heading()
{
    cout.setf(ios::left);
    cout << setw(7) << "ID";
    cout << setw(15) << "Full Name";
    cout << setw(15) << "Mobile";
    cout << setw(15) << "Skill Set";
    cout << setw(15) << "Role" << endl;
}
void TeamMember ::addTeamMember()
{
    ofstream fteam;
    fteam.open("TeamMember.dat", ios::out | ios::app | ios::binary);
    getData();
    fteam.write((char *)&this, sizeof(TeamMember));
    fteam.close();
    cout << "\nData added sucessfully\n";
}
void TeamMember ::displayTeamMember()
{
    ifstream fteam;
    fteam.open("TeamMember.dat", ios::in | ios::binary);
    cout << "\n\n *****TEAM MEMBER DETAILS***** \n\n";
    heading();
    while (fteam.read((char *)&this, sizeof(TeamMember)))
    {
        showData();
    }
    fteam.close();
}
void TeamMember ::editTeamMember()
{
    fstream fteam;
    fteam.open("TeamMember.dat", ios::binary | ios::in | ios::out);
    if (!fteam)
    {
        cout << "Error opening file for updating.\n";
        return;
    }

    int s_teamid;
    cout << "Enter Team ID you want to edit: \n";
    cin >> s_teamid;
    int found = 0;

    while (fteam.read((char *)&this, sizeof(TeamMember)))
    {
        int loc = fteam.tellg();
        if (teamid == s_teamid)
        {
            found = 1;
            showData();
            cout << "Enter new details:\n";
            getData();
            fteam.seekg(loc - sizeof(TeamMember));
            fteam.write((char *)&this, sizeof(TeamMember));
            break;
        }
    }
    fteam.close();

    if (found == 0)
        cout << "No Record Found\n";
}
void TeamMember ::deleteTeamMember()
{
    ifstream fteam;
    ofstream ftemp, ftrash;
    fteam.open("TeamMember.dat", ios::in | ios::binary);
    ftemp.open("Storage.dat", ios::out | ios::binary);
    ftrash.open("TeamTrash.dat", ios::out | ios::binary);

    int s_teamid;
    cout << "Enter Team ID you want to delete: \n";
    cin >> s_teamid;
    int found = 0;

    while (fteam.read((char *)&this, sizeof(TeamMember)))
    {
        if (teamid == s_teamid)
        {
            found = 1;
            showData();
            ftrash.write((char *)&this, sizeof(TeamMember));
        }
        else
        {
            ftemp.write((char *)&this, sizeof(TeamMember));
        }
    }
    fteam.close();
    ftemp.close();
    ftrash.close();
    remove("TeamMember.dat");
    rename("Storage.dat", "TeamMember.dat");
    if (found == 0)
        cout << "\nNo Record Found\n";
    else
        cout << "\nRecord Deleted\n";
}

void Project ::getData()
{
    cout << "Enter Project Code: ";
    cin.ignore();
    cin >> pcode;
    cout << "\nEnter Customer Name: ";
    cin.ignore();
    cin.get(custname, 20);
    cout << "\nEnter Project Name: ";
    cin.ignore();
    cin.get(projectname, 20);
    cout << "\nEnter Start Date: ";
    cin.ignore();
    cin.get(startdate, 20);
    cout << "\nEnter End Date: ";
    cin.ignore();
    cin.get(enddate, 20);
}
void Project ::showData()
{
    cout.setf(ios::left);
    cout << setw(7) << pcode;
    cout << setw(15) << custname;
    cout << setw(15) << projectname;
    cout << setw(15) << startdate;
    cout << setw(15) << enddate << endl;
}
void Project ::heading()
{
    cout.setf(ios::left);
    cout << setw(7) << "PCode";
    cout << setw(15) << "Customer Name";
    cout << setw(15) << "Project Name";
    cout << setw(15) << "Start Date";
    cout << setw(15) << "End Date" << endl;
}
void Project ::addProject()
{
    ofstream fproject;
    fproject.open("Project.dat", ios::out | ios::app | ios::binary);
    getData();
    fproject.write((char *)&this, sizeof(Project));
    fproject.close();
    cout << "\nData added sucessfully\n";
}
void Project ::displayProject()
{
    ifstream fproject;
    fproject.open("Project.dat", ios::in | ios::binary);
    cout << "\n\n ***** PROJECT DETAILS ***** \n\n";
    heading();
    while (fproject.read((char *)&this, sizeof(Project)))
    {
        showData();
    }
    fproject.close();
}

void Project ::assign(int selectedPCode)
{
    TeamMember tt;
    fstream fteam;
    fteam.open("TeamMember.dat", ios::binary | ios::in);
    if (!fteam)
    {
	cout << "Error opening file for updating.\n";
	return;
    }
    int pcd = selectedPCode;
    int tid;
    cout << "\nEnter the Team Id to whom the Project is to be assigned: \n";
    cin>>tid;
    cout<<"PROJECT ASSIGNED";
    int found = 0;

    while (fteam.read((char *)&tt, sizeof(TeamMember)))
    {
	// int loc=fteam.tellg();
	//	int ttget=tt.get();
	//	cout<<ttget;
	//	cout<<"abcdw";
	getch();
	if (tt.get() == tid)
	{
	    found = 1;
	    break;
	}
    }
    if (found != 1)
    {
     int g=1;
    }
    else
    {
	ProjectTeam pt(pcd, tid);
	ofstream fpteam;
	fpteam.open("ProjectTeam.dat", ios::out | ios::app | ios::binary);
	fpteam.write((char *)&pt, sizeof(ProjectTeam));
	fpteam.close();
	cout << "\nData added sucessfully\n";
    }
}

void Project::assignProject()
{
    ifstream fproject;
    fproject.open("Project.dat", ios::in | ios::binary);
    cout << "\n\n ***** PROJECT DETAILS ***** \n\n";
    heading();
    while (fproject.read((char *)&this, sizeof(Project)))
    {
	showData();
    }
    fproject.close();

    // Step 2: Enter Project Code
    int selectedPCode;
    cout << "\nEnter Project Code: ";
    cin >> selectedPCode;
    fstream fproject1;
    fproject1.open("Project.dat", ios::binary | ios::in);
    int projectFound = 0;
    while (fproject1.read((char *)&this, sizeof(Project)))
    {
	if (get() == selectedPCode)
	{
	    projectFound = 1;
	    cout << "\nSelected Project:\n";
	    heading();
	    showData();
	    assign(selectedPCode);
	    break;
	}
    }
    fproject1.close();

    if (projectFound == 0)
    {
	cout << "No Project found with this code.\n";
	return;
    }
}
void Project::disassign()
{
    ProjectTeam ob;
    ifstream fpro;
    fpro.open("ProjectTeam.dat", ios::in | ios::binary);
    cout << "\n\n ***** ASSIGN PROJECT DETAILS ***** \n\n";
    while (fpro.read((char *)&ob, sizeof(Project)))
    {
	ob.show();
    }
    fpro.close();
}
/*
    // Step 3: Display current team members for selected project
    cout << "\nCurrent Team Members in Project " << selectedPCode << ":\n";
    ifstream fprojectteam("ProjectTeam.dat", ios::binary | ios::in);
    TeamMember tempMember;
    int teamMemberFound = 0;

    while (fprojectteam.read((char*)&tempMember, sizeof(TeamMember))) {
    if (tempMember.teamid == 101) {
        tempMember.showData();
        teamMemberFound = 1;
    }
    }
    fprojectteam.close();
    if (teamMemberFound==0) {
    cout << "No team members assigned to this project.\n";
    }

    // Step 4: Add or Delete Team Members
    cout << "\nChoose an option:\n";
    cout << "1. Add Team Member to Project\n";
    cout << "2. Delete Team Member from Project\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
    // Add Team Member to Project
    ofstream fprojectteam("ProjectTeam.dat", ios::binary | ios::app);
    if (!fprojectteam) {
        cout << "Error opening ProjectTeam file.\n";
        return;
    }

    int teamIdToAdd;
    cout << "Enter Team Member ID to add to Project " << selectedPCode << ": ";
    cin >> teamIdToAdd;

    fprojectteam.write((char*)&teamIdToAdd, sizeof(teamIdToAdd));
    fprojectteam.write((char*)&selectedPCode, sizeof(selectedPCode));
    fprojectteam.close();
    cout << "Team member added successfully.\n";

    } else if (choice == 2) {
    // Delete Team Member from Project
    ifstream fprojectteam("ProjectTeam.dat", ios::binary | ios::in);
    ofstream ftemp("Temp.dat", ios::binary | ios::out);

    int teamIdToDelete;
    cout << "Enter Team Member ID to delete from Project " << selectedPCode << ": ";
    cin >> teamIdToDelete;

    int currentProjectId, currentTeamId;
    int memberDeleted = 0;

    while (fprojectteam.read((char*)&currentTeamId, sizeof(currentTeamId)) &&
           fprojectteam.read((char*)&currentProjectId, sizeof(currentProjectId))) {
        if (currentTeamId == teamIdToDelete && currentProjectId == selectedPCode) {
        memberDeleted = 1; // Skip writing to ftemp to delete
        } else {
        ftemp.write((char*)&currentTeamId, sizeof(currentTeamId));
        ftemp.write((char*)&currentProjectId, sizeof(currentProjectId));
        }
    }

    fprojectteam.close();
    ftemp.close();
    remove("ProjectTeam.dat");
    rename("Temp.dat", "ProjectTeam.dat");

    if (memberDeleted==1) {
        cout << "Team member deleted successfully.\n";
    } else {
        cout << "No matching team member found in project.\n";
    }
    } else {
    cout << "Invalid choice. Exiting.\n";
    }
    */

void Project::editProject()
{
    fstream fproject;
    fproject.open("Project.dat", ios::binary | ios::in | ios::out);
    if (!fproject)
    {
        cout << "Error opening file for updating.\n";
        return;
    }

    int s_pcode;
    cout << "Enter Project Code you want to edit: ";
    cin >> s_pcode;
    int found = 0;

    while (fproject.read((char *)&this, sizeof(Project)))
    {
        int loc = fproject.tellg();
        if (pcode == s_pcode)
        {
            found = 1;
            showData();
            cout << "Enter new details:\n";
            getData();
            fproject.seekg(loc - sizeof(Project));
            fproject.write((char *)&this, sizeof(Project));
            cout << "Record updated successfully.\n";
            break;
        }
    }

    if (found == 0)
        cout << "No Record Found\n";

    fproject.close();
}

void Project ::deleteProject()
{
    ifstream fproject;
    ofstream ftemp, ftrash;
    fproject.open("Project.dat", ios::in | ios::binary);
    ftemp.open("Storage.dat", ios::out | ios::binary);
    ftrash.open("ProjectTrash.dat", ios::out | ios::binary);

    int s_pcode;
    cout << "Enter Project ID you want to delete: \n";
    cin >> s_pcode;
    int found = 0;

    while (fproject.read((char *)&this, sizeof(Project)))
    {
        if (pcode == s_pcode)
        {
            found = 1;
            showData();
            ftrash.write((char *)&this, sizeof(Project));
        }
        else
        {
            ftemp.write((char *)&this, sizeof(Project));
        }
    }
    fproject.close();
    ftemp.close();
    ftrash.close();
    remove("Project.dat");
    rename("Storage.dat", "Project.dat");
    if (found == 0)
        cout << "\nNo Record Found\n";
    else
        cout << "\nRecord Deleted\n";
}

void resetDatabase()
{
    ofstream fteam;
    fteam.open("TeamMember.dat", ios::binary | ios::out);
    if (!fteam)
    {
        cout << "Error opening file for writing.\n";
        return;
    }
    fteam.close();

    ofstream fproject;
    fproject.open("Project.dat", ios::binary | ios::out);
    if (!fproject)
    {
        cout << "Error opening file for writing.\n";
        return;
    }
    fproject.close();

    ofstream fprojectteam;
    fprojectteam.open("ProjectTeam.dat", ios::binary | ios::out);
    if (!fprojectteam)
    {
        cout << "Error opening file for writing.\n";
        return;
    }
    fprojectteam.close();
    cout << "\nDatabase Reset\n";
}

void TeamMemberOptions()
{
    TeamMember t1;
    int ch;
    do
    {
        system("cls");
        cout << "...............PROJECT MANAGEMENT CRM..............\n";
        cout << "======================================================\n";
        cout << "0. Back to Main Menu\n";
        cout << "1. Add Team Member\n";
        cout << "2. Display Team Members\n";
        cout << "3. Edit Team Member\n";
        cout << "4. Delete Team Member\n";

        cout << "Enter your choice  : ";
        cin >> ch;

        if (!cin)
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        system("cls");
        switch (ch)
        {
        case 1:
            t1.addTeamMember();
            break;
        case 2:
            t1.displayTeamMember();
            break;
        case 3:
            t1.editTeamMember();
            break;
        case 4:
            t1.deleteTeamMember();
            break;
        }
        if (ch != 0)
            system("pause");
    } while (ch != 0);
}

void ProjectOptions()
{
    Project p1;
    int ch;
    do
    {
        system("cls");
        cout << "...............PROJECT MANAGEMENT CRM..............\n";
        cout << "======================================================\n";
        cout << "0. Back to Main Menu\n";
        cout << "1. Add Project\n";
        cout << "2. Display Project\n";
        cout << "3. Assign Project to Team\n";
        cout << "4. Display Assigned Projects\n";
        cout << "5. Edit Project\n";
        cout << "6. Delete Project\n";

        cout << "Enter your choice  : ";
        cin >> ch;

        if (!cin)
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        system("cls");
        switch (ch)
        {
        case 1:
            p1.addProject();
            break;
        case 2:
            p1.displayProject();
            break;
        case 3:
            p1.assignProject();
            break;
        case 4:
            p1.disassign();
            break;
        case 5:
            p1.editProject();
            break;
        case 6:
            p1.deleteProject();
            break;
        }
        if (ch != 0)
            system("pause");
    } while (ch != 0);
}

void MainOptions()
{
    int ch;
    do
    {
        system("cls");
        cout << "...............PROJECT MANAGEMENT CRM..............\n";
        cout << "======================================================\n";
        cout << "0. Exit from Program\n";
        cout << "1. Manager Team Members\n";
        cout << "2. Manage Projects\n";
        cout << "3. Reset Database\n";

        cout << "Enter your choice  : ";
        cin >> ch;

        if (!cin)
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        system("cls");
        switch (ch)
        {
        case 1:
            TeamMemberOptions();
            break;
        case 2:
            ProjectOptions();
            break;
        case 3:
            resetDatabase();
            break;
        }
        if (ch != 0)
            system("pause");
    } while (ch != 0);
}

void main()
{
    MainOptions();
}
