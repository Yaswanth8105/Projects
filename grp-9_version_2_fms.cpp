//Will NOT run. Work in Progress
//Concepts used: Inheritance, Access  Specifiers, Inline functions, Constructor(for only child classes) ,Still working on Files 
#include <iostream>
#include <fstream>
using namespace std;

// Base Class: DiningSession
class DiningSession {

public:
    void enterSessionDetails(); 
	char data[10];
    void displaySessionDetails();
};

inline void DiningSession::enterSessionDetails(){
		ofstream fout;
		fout.open("first.txt");
		
		cout<<"* Welcome to Food Management System *"<<endl;
        cout << "Enter date: ";
        fout << data[0];
        cout << "Enter session type (Breakfast/Lunch/Dinner): ";
        fout
        cout << "Enter name of the student incharge: ";
        cin >> inchargeName;
        cout << "Enter day (Monday-Sunday): ";
        cin >> day;
        fout.close();
        ifstream fin("first.txt");
        while(fin){
        	fin.getline(data,10);
        	cout<<"\n"<<date;
		}
		fin.close();
}
inline void DiningSession::displaySessionDetails(){
        cout << "\nDate: " << date
             << "\nSession: " << sessionType
             << "\nStaff / Supervisor: " << inchargeName
             << "\nDay: " << day << endl;
}

// Derived Class 1: MealManagement
class MealManagement : public DiningSession {
public:
    void displayMenuForSession();
};
inline void MealManagement::displayMenuForSession(){
	        cout << "\nMenu for " << sessionType << " on " << day << ": ";
        if (sessionType == "Breakfast") {
            if (day == "Monday") {
                cout << "Bread Butter Milk";
            } else if (day == "Tuesday") {
                cout << "Idli Sambar Chutney";
            } else if (day == "Wednesday") {
                cout << "Pancakes Honey Juice";
            } else if (day == "Thursday") {
                cout << "Cornflakes Milk Banana";
            } else if (day == "Friday") {
                cout << "Poha Namkeen Tea";
            } else if (day == "Saturday") {
                cout << "Uttapam Chutney Sambar";
            } else if (day == "Sunday") {
                cout << "Oats Fruits Milk";
            } else {
                cout << "Invalid day!";
            }
        } else if (sessionType == "Lunch") {
            if (day == "Monday") {
                cout << "Rice Dal Salad";
            } else if (day == "Tuesday") {
                cout << "Veg Biryani Raita Papad";
            } else if (day == "Wednesday") {
                cout << "Jeera Rice Dal Tadka Pickle";
            } else if (day == "Thursday") {
                cout << "Paratha Curry Salad";
            } else if (day == "Friday") {
                cout << "Lemon Rice Curd Pickle";
            } else if (day == "Saturday") {
                cout << "Rajma Rice Onion Salad";
            } else if (day == "Sunday") {
                cout << "Veg Pulao Raita Papad";
            } else {
                cout << "Invalid day!";
            }
        } else if (sessionType == "Dinner") {
            if (day == "Monday") {
                cout << "Roti Paneer Soup";
            } else if (day == "Tuesday") {
                cout << "Chapati Bhaji Curd";
            } else if (day == "Wednesday") {
                cout << "Dosa Sambar Chutney";
            } else if (day == "Thursday") {
                cout << "Fried Rice Manchurian Soup";
            } else if (day == "Friday") {
                cout << "Dal Khichdi Papad Buttermilk";
            } else if (day == "Saturday") {
                cout << "Aloo Paratha Curd Pickle";
            } else if (day == "Sunday") {
                cout << "Chole Bhature Onions Lassi";
            } else {
                cout << "Invalid day!";
            }
        } else {
            cout << "Invalid session!";
        }
        cout << endl;
}
// Derived Class: SickMealPreparation
class SickMeal : public MealManagement {
public:
    string sufferingFrom;
    string studentID, studentName;
    string preparingStudentID, preparingStudentName;
    string sickItems[3];

public:
    SickMeal(){
    	string isSick;
        cout << "Is anyone sick in this session? (yes/no): ";
        cin >> isSick;

        if (isSick == "yes" || isSick == "YES") 
		{
            cout << "Enter sick student's ID: ";
            cin >> studentID;
            cout << "Enter sick student's name: ";
            cin >> studentName;
            cout << "Enter illness: ";
            cin >> sufferingFrom;
            cout << "Enter ID of the student preparing the sick meal: ";
            cin >> preparingStudentID;
            cout << "Enter name of the student preparing the sick meal: ";
            cin >> preparingStudentName;
            cout << "Enter 3 food items for the sick meal:\n";
            cin >> sickItems[0] >> sickItems[1] >> sickItems[2];
            cout << "Sick Meal Details:" << endl;
        	cout << "Sick Student: " << studentName << " (ID: " << studentID << ") suffering from " << sufferingFrom << endl;
        	cout << "Prepared by: " << preparingStudentName << " (ID: " << preparingStudentID << ")" << endl;
        	cout << "Meal Items: " << sickItems[0] << ", " << sickItems[1] << ", " << sickItems[2] << endl;
        }
        else
        	cout << "There is no sick student" << endl;	
	}

};


// Derived Class 2: StockManagement
class StockManagement : public DiningSession {
public:
    static void checkStock() {
        cout << "Checking stock availability... Stock is available." << endl;
    }
};

// Derived Class 3: Schedule
class Schedule : public DiningSession {
public:
    string studentNames[9];
    int numofDays = 0;
    string check;

public:
    void enterStudentNames();

    void AssignAndDisplaySchedule();
};
inline void Schedule::AssignAndDisplaySchedule(){
	        cout << "How many days do you want to assign duties for those students (maximum days are 2)? ";
        cin >> numofDays;

        if (numofDays > 2) {
            cout << "Maximum allowed days are 2. Setting it to 2." << endl;
            numofDays = 2;
        }

        string sessions[3] = {"Breakfast", "Lunch", "Dinner"};
        cout << "\nSchedule for Sessions:\n";

        for (int day = 0; day < numofDays; day++) {
            cout << "\nDay - " << day + 1 << ":\n";
            for (int sess = 0; sess < 3; sess++) {
                cout << sessions[sess] << " Assigned Students: ";
                if (sess + 2 < 9) {
                    cout << studentNames[sess] << ", "
                         << studentNames[sess + 1] << ", "
                         << studentNames[sess + 2] << endl;
                } 
				else 
				{
                    cout << "Not enough students available." << endl;
                }
            }
        }
    }
inline void Schedule::enterStudentNames(){
		cout<<"Do want to schedule the serving (yes/no)?"<<endl;
		cin>>check;
		if (check=="yes" || check=="Yes"){
			cout << "Enter names of 9 students for schedule rotation:\n";
        	for (int i = 0; i < 9; i++) {
            cout << "Student " << i + 1 << ": ";
            cin >> studentNames[i];
		}
		
}
}
// Sub-Derived Class: Duty
class Duty : public Schedule {
public:
	
    void trackDuties() {
        cout << "Tracking student duties..." << endl;
    }

    void updateDuties() {
        cout << "Updating student duties..." << endl;
    }

    void removeDuty() {
        cout << "Removing a student's duties..." << endl;
    }
};

// Main function
int main() 
{
	
    MealManagement meal;
    meal.enterSessionDetails();
    meal.displaySessionDetails();
    meal.displayMenuForSession();

    SickMeal sickMeal;

    StockManagement::checkStock();

    Schedule schedule;
    schedule.enterStudentNames();
    if (schedule.check=="yes" ||schedule.check=="Yes"){
    	schedule.AssignAndDisplaySchedule();
	}
    

    Duty duty;
    duty.trackDuties();
    duty.updateDuties();
    duty.removeDuty();

    return 0;
}

