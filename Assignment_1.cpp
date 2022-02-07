------------------ Searching and Sorting ------------------------

#include <string.h>
#include<iostream>
using namespace std;

class student
{
public:
    int roll;
    int i, n, j;
    char name[200];
    float SGPA;

    void read_data();
    void display_data();
    void roll_bubble_sort(class student s[100], int n);
    void quick_SGPA_sort(class student s[100], int lb, int ub);
    int partition(student s[50], int lb, int ub);
    void linear_rollsearch(class student s[100], int n);
    void linear_SGPA_search(class student s[100], int n);
    void binary_name_search(int n, student s[50]);
};

/*
------------------------------------------------
 read data
Input : null parameter
Output:Array ofstudents data will be displayed
------------------------------------------------
 */

void student ::read_data()
{
    cout<< "\n Enter the roll number of student  : ";
    cin>> roll;
    cout<< "\n Enter the Name of student  : ";
    cin>> name;
    cout<< "\n Enter SGPA of student  : ";
    cin>> SGPA;
}

/*
------------------------------------------------
 Display data
output : Display data get in the function read data
------------------------------------------------
*/

void student ::display_data()
{
    cout << roll << "\t\t";
    cout << "\t\t" << name;
    cout << "\t\t\t\t" << SGPA << "\n";
}

/*
------------------------------------------------
bubble sort
Input:Array of students of size 100 and n as a index number
Output:Sort the data by roll no data
------------------------------------------------
*/

void student::roll_bubble_sort(class student s[100], int n)
{
    int i, j;
    class student temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[j].roll > s[j + 1].roll)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

/*
------------------------------------------------
Quick sort
Input:Array of students of size 100 and lower bound and upper bound as a index number
Output:Sort the SGPA data 
------------------------------------------------
*/

void student ::quick_SGPA_sort(student s[100], int lb, int ub)
{
    int j;
    if (lb < ub)
    {
        j = partition(s, lb, ub);
        quick_SGPA_sort(s, lb, j - 1);
        quick_SGPA_sort(s, j + 1, ub);
    }
}

/*
------------------------------------------------
partition
Input:Array of students of size 100 and lower bound and upper bound as a index number
output
------------------------------------------------
*/

int student ::partition(student s[100], int lb, int ub)
{
    float p;
    class student temp;
    int down, up;
    p = s[lb].SGPA;
    down = lb;
    up = ub;
     while(down<up)
    {
        while (s[down].SGPA <= p && down < up)
            down++;
        while (s[up].SGPA > p)
            up--;
        if (down < up)
        {
            temp = s[down];
            s[down] = s[up];
            s[up] = temp;
        }
    }
    temp = s[up];
    s[up] = s[lb];
    s[lb] = temp;
    return up;
}

/*
------------------------------------------------
linear_roll_search
Input:Array of students of size 100 and n as a index number
output:Search the roll no data
------------------------------------------------
*/

void student::linear_rollsearch(class student s[100], int n)
{
    int flag = 0;
    int r;
    cout << "\nEnter the Roll no. do you want to search\n";
    cin >> r;
    for (i = 0; i <= n; i++)
    {
        if (r == s[i].roll)

        {
            cout << "Record Found\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            s[i].display_data();
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Record Not Found\n";
    }
}

/*
------------------------------------------------
linear_SGPA_search
Input:Array of students of size 100 and n as a index number
output: search the GSPA data
------------------------------------------------
*/

void student::linear_SGPA_search(class student s[100], int n)
{
    int flag = 0;
    int flag1 = 0;
    int flag2 = 0;
    float r;
    cout << "\nEnter the SGPA do you want to search";
    cin >> r;
    for (i = 0; i <= n; i++)
    {
        if (r == s[i].SGPA)
        {
            flag1++;
            if (flag1 == 1)
            {
                cout << "\nRecord Found\n";
                cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            }
            s[i].display_data();
            flag2++;
        }
    }
    if (flag2 > 1)
    {
        cout << "\nThere are total " << flag2 << " Students whose SGPA is " << r << "\n\n";
    }
    if (flag2 == 1)
    {
        cout << "\nThere is only " << flag2 << " Student whose SGPA is " << r << "\n\n";
    }
    if (flag2 == 0)
    {
        cout << "Record Not Found\n";
    }
}

/*
------------------------------------------------
binary_name_search
Input:Array of students of size 100 and n as a index number
output:search the name data
------------------------------------------------
*/

void student ::binary_name_search(int n, student s[50])
{
    char Name[20];
    cout << "\nEnter the Name you want to find: ";
    cin >> Name;
    int l = 0, h = n - 1, mid = (l+h)/2, count = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (strcmp(s[mid].name, Name) == 0)
        {
            cout << "Record Found.\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            cout<<s[mid].roll<<"\t\t\t\t"<<s[mid].name<<"\t\t\t\t"<<s[mid].SGPA<<"\n";
            count = 1;
            break;
        }
        else if (strcmp(s[mid].name, Name) < 0)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    if (count == 0)
    {
        cout << "\nRecord not found.";
    }
}

int main()
{
    class student s1[100], s2;
    int n, i, r, search, d, z, f, k = 0, g = 0, t = 0;
    cout << "\n Enter the No. of Student records do you want to read\t:\n ";
    cin >> n;
    do
    {
        do
        {
            if (g == 0 || f == 100 || t == 100)
            {
                if (k == 0)
                {
                    cout << "Enter 1 to store data\n";
                    k++;
                }

                else
                {
                    cout << "Enter 1 to update data\n";
                }
                cout << "Enter 2 - print data as it is \n";
                cout << "Enter 3 - sort data by Roll no.\n";
                cout << "Enter 4 - sort data by SGPA.\n";
                cout << "Enter 5 - sort data by Both methds.\n";
                cout << "Enter 6 - search Name. \n";
                cout << "Enter 7 - search Roll no. \n";
                cout << "Enter 8 - search SGPA \n";
                cin >> z;
                if (z == 1 || z == 2 || z == 3 || z == 4 || z == 5 || z == 6 || z == 7 || z == 8)
                {
                    f++;
                }
                g++;
            }
            if (z >= 9 || z <= 0)
            {
                cout << "Please provide correct input \n Do you Want to Enter option Again then please Enter 198 else press Anything \n";
                cin >> f;
            }
        } while (f == 100);

        switch (z)
        {
        case 1:
        {
            for (i = 0; i < n; i++)
            {
                s1[i].read_data();
            }
            break;
        }
        case 2:
        {
            cout << "\n Record Of Students before sort as follows:\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            for (i = 0; i < n; i++)
            {
                s1[i].display_data();
            }
            break;
        }
        case 3:

        {
            cout << "\n Record Of Students Roll no. in Ascending order:\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            s2.roll_bubble_sort(s1, n);
            for (i = 1; i <= n; i++)
            {
                s1[i].display_data();
            }
            break;
        }
        case 4:
        {
            cout << "\n Record Of Student SGPA in Decending order:\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            s2.quick_SGPA_sort(s1, 0, n );
            for (i = n; i >= 1; i--)
            {
                s1[i].display_data();
            }
            break;
        }
        case 5:
        {
            cout << "\n Record Of Students Roll no. in Ascending order:\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            s2.roll_bubble_sort(s1, n);
            for (i = 1; i <= n; i++)
            {
                s1[i].display_data();
            }
            cout << "\n\n";
            cout << "\n Record Of Student SGPA in Ascending order:\n\n";
            cout << "Roll No.\t\t\tName\t\t\t\tSGPA\n\n";
            s2.quick_SGPA_sort(s1, 0, n );
            for (i = 1; i <= n; i++)
            {
                s1[i].display_data();
            }
            break;
        }
        case 6:
        {
            s2.binary_name_search(n, s1);
            break;
        }
        
        case 7:
        {
            s2.linear_rollsearch(s1, n);
            break;
        }
        case 8:
        {
            s2.linear_SGPA_search(s1, n);
            break;
        }
        default:
        {
            cout << "Please enter valid input\n";
        }
        }
        cout << "\n\n Do you Want to continue then please Enter 123 else press Anything \n";
        cin >> t;
    } while (t == 100);
    return 0;
}

output:


 Enter the No. of Student records do you want to read   :
 2
Enter 1 to store data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
1

 Enter the roll number of student  : 11

 Enter the Name of student  : tt


 Enter SGPA of student  : 12

 Enter the roll number of student  : 90

 Enter the Name of student  : rr

 Enter SGPA of student  : 76


 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
2

 Record Of Students before sort as follows:

Roll No.                        Name                            SGPA

11                               tt                               12
90                               rr                                76


 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
3

 Record Of Students Roll no. in Ascending order:

Roll No.                        Name                            SGPA

11                             tt                              12
90                             rr                              76


 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
4

 Record Of Student SGPA in Decending order:

Roll No.                        Name                            SGPA

90                              rr                              76
11                              tt                              12


 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
5

 Record Of Students Roll no. in Ascending order:

Roll No.                        Name                            SGPA

11                              tt                              12
90                              rr                              76



 Record Of Student SGPA in Ascending order:

Roll No.                        Name                            SGPA

11                              tt                              12
90                              rr                              76



 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
6

Enter the Name you want to find: tt
Roll No.                        Name                            SGPA

11                              tt                              12
 
Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
7

Enter the Roll no. do you want to search
11
Roll No.                        Name                            SGPA

11                              tt                               12


 Do you Want to continue then please Enter 123 else press Anything 
123
Enter 1 to update data
Enter 2 - print data as it is 
Enter 3 - sort data by Roll no.
Enter 4 - sort data by SGPA.
Enter 5 - sort data by Both methds.
Enter 6 - search Name. 
Enter 7 - search Roll no. 
Enter 8 - search SGPA 
8

Enter the SGPA do you want to search 12


Roll No.                        Name                            SGPA

11                              tt                              12

There are total 1 Students whose SGPA is 12



 Do you Want to continue then please Enter 123 else press Anything 
^C

...Program finished with exit code 0
Press ENTER to exit console.
Process exited after 6.93 seconds with return value 0



