#include <iostream>
using namespace std;

// شمسی به میلادی
void sol_to_gre(int year, int month, int day, string kabise) {

    cout << year << " " << month << " " << day << endl;

    // variables:
    string n_month;
    int n_year;

    // conditions for month
    if (month == 1){
        if (day <=11 && day >= 1){
            n_month = "March";
        } else if (day <= 31 && day >= 12) {
            n_month = "April";
        }
    }
    else if (month == 2){
        if (day <= 10 && day >= 1){
            n_month = "April";
        } else if(day >= 11 && day <= 31) {
            n_month = "May";
        }
    }
    else if (month == 3){
        if (day <= 10 && day >= 1){
            n_month = "May";
        } else if (day >= 11 && day <= 31){
            n_month = "June";
        }
    }
    else if (month == 4){
        if (day <= 9 && day >= 1){
            n_month = "June";
        } else if (day >= 10 && day <= 31){
            n_month = "July";
        }
    }
    else if (month == 5){
        if (day <= 9 && day >= 1) {
            n_month = "July";
        } else if (day >= 10 && day <= 31){
            n_month = "August";
        }
    }
    else if (month == 6){
        if (day <= 9 && day >= 1){
            n_month = "August";
        } else if (day >= 10 && day <= 30) {
            n_month = "September";
        }
    }
    else if (month == 7){
        if (day <= 8 && day >= 1){
            n_month = "September";
        } else if (day >= 9 && day <= 30){
            n_month = "October";
        }
    }
    else if (month == 8){
        if (day <= 9 && day >= 1){
            n_month = "October";
        } else if (day >= 10 && day <= 30){
            n_month = "November";
        }
    }
    else if (month == 9){
        if (day <= 9 && day >= 1){
            n_month = "November";
        } else if (day >= 10 && day <= 30){
            n_month = "December";
        }
    }
    else if (month == 10){
        if (day <= 10 && day >= 1){
            n_month = "December";
        } else if (day >= 11 && day <= 30){
            n_month = "January";
        }
    }
    else if (month == 11){
        if (day <= 11 && day >= 1){
            n_month = "January";
        } else if (day >= 12 && day <= 30){
            n_month = "February";
        }
    }
    else if (month == 12){
        if (day <= 9 && day >= 1 ){
            n_month = "February";
        } else if (day >= 10 && day <= 30){
            n_month = "March";
        }
    }

    // what's the year:
    n_year = year + 622;

    // the number of day
    int shamsi_days[] = {31,31,31,31,31,31,30,30,30,30,30,29};

    // days between 1 march and your birthday:
    int passed_days = 0;
    for (int i = 0; i < month-1; i++){
        passed_days += shamsi_days[i];
    }
    passed_days += day;

    // adding the number of passed_days to 21march:
    int miladi_days[] = {31,30,31,30,31,31,30,31,30,31,31,28};
    string monthes_english[] = {
        "March","April","May","June","July","August",
        "September","October","November","December",
        "January","February"
    };

    int m = 0;
    int d = 21;

    while(passed_days > 0){
        int remain = miladi_days[m] - d + 1;
        if(passed_days <= remain){
            d += passed_days - 1;
            break;
        } else {
            passed_days -= remain;
            m++;
            d = 1;
        }
    }

    // result
    cout << "\n\n" << "shamsi---> " << year << "/" << month << "/" << day << endl;

    // condition if the year was kabise:
    if(kabise == "y" && month > 2){
        d +=1;
        cout << "miladi---> " << d << " " << n_month << " " << n_year << endl;
    } else {
        cout << "miladi---> " << d << " " << n_month << " " << n_year << endl;
    }
}

// میلادی به شمسی
void miladi_to_shmasi(int g_year, int g_month, int g_day, string kabise){
    int shamsi_days[] = {31,31,31,31,31,31,30,30,30,30,30,29};
    string shamsi_months[] = {"Farvardin","Ordibehesht","Khordad","Tir","Mordad","Shahrivar",
                              "Mehr","Aban","Azar","Dey","Bahman","Esfand"};

    int miladi_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // بررسی کبیسه میلادی
    if(kabise == "y") miladi_days[1] = 29;

    // روز سال میلادی
    int day_of_year = g_day;
    for(int i=0; i<g_month-1; i++) day_of_year += miladi_days[i];

    // سال شمسی
    int s_year = g_year - 621;

    // شروع سال شمسی در روز سال میلادی
    int start_day = 80; // 21 March
    if(kabise == "y") start_day = 81;

    int s_day_of_year;
    if(day_of_year >= start_day){
        s_day_of_year = day_of_year - start_day + 1;
    } else {
        s_year--;
        s_day_of_year = day_of_year + 365 - (start_day-1);
        if(kabise == "y") s_day_of_year++;
    }

    // پیدا کردن ماه و روز شمسی
    int s_month = 0, s_day = 0, remaining = s_day_of_year;
    for(int i=0; i<12; i++){
        if(remaining <= shamsi_days[i]){
            s_month = i;
            s_day = remaining;
            break;
        } else {
            remaining -= shamsi_days[i];
        }
    }

    cout << "\nMiladi ---> " << g_day << "/" << g_month << "/" << g_year << endl;
    cout << "Shamsi ---> " << s_day << "/" << (s_month+1) << "/" << s_year
         << " (" << shamsi_months[s_month] << ")" << endl;
}

// main
int main() {
    int opt;
    cout << "Welcome to date converter tool!\n";
    cout << "[1] Solar to Gregorian\n[2] Gregorian to Solar\n[3] Help\n[0] Exit\n\n";
    cin >> opt;

    if(opt == 1){
        int year, month, day;
        string kabise;
        cout << "Enter year, month, day (Solar): ";
        cin >> year >> month >> day;
        cout << "Is it leap year? [y/n]: ";
        cin >> kabise;
        sol_to_gre(year, month, day, kabise);
    }
    else if(opt == 2){
        int year, month, day;
        string kabise;
        cout << "Enter year, month, day (Gregorian): ";
        cin >> year >> month >> day;
        cout << "Is it leap year? [y/n]: ";
        cin >> kabise;
        miladi_to_shmasi(year, month, day, kabise);
    }
    else if(opt == 0){
        cout << "Bye!" << endl;
    }
    else if(opt == 3){
      cout << "help page!\nthis is the order of month in Gregorian:" << endl;
      cout << "1->January\n2->February\n3->March\n4->April\n5->May\n6->June\n7->July\n8->August\n9->September\n10->October\n11->November\n12->December\n" << endl;
    }
    else{
        cout << "Unknown option!" << endl;
    }

    cout << "\n\ndeveloped by Amirreza Azizi" << endl;
}

