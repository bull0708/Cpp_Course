// cl -GX testRead1.cpp   // vc6
// cl -EHsc testRead1.cpp // vc

#include <iostream>
#include <fstream>
using namespace std;

void main()
{
    char buf[50];
    fstream infile("ntou1.txt");

    if (!infile)
    {
        cout << "�L�k�}�� ntou1.txt\n";
        cout << "Press <enter> to continue ...\n";
        cin.getline(buf, 50, '\n');
        return;
    }

    char campusName[50];
    infile.getline(campusName, 50, '\n');
    cout << "�ǮզW��: " << campusName << endl;

    int numberOfColleges;
    infile >> numberOfColleges;
    infile.getline(buf, 50, '\n');    

    int iCol;
    for (iCol=0; iCol<numberOfColleges; iCol++)
    {
        char collegeName[50];
        infile.getline(collegeName, 50, '\n');
        cout << "  �ǰ|�W��: " << collegeName << endl;

        int numberOfDepartments;
        infile >> numberOfDepartments;
        infile.getline(buf, 50, '\n');

        int iDept;
        for (iDept=0; iDept<numberOfDepartments; iDept++)
        {
            char departmentName[50];
            infile.getline(departmentName, 50, '\n');
            cout << "    �Ǩt�W��: " << departmentName << endl;
        }
    }
    cout << "Press <enter> to continue ...\n";
    cin.getline(buf, 50, '\n');
}