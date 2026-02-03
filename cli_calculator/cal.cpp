#include <iostream>
#include <cmath>
using namespace std;

// تابع برای محاسبه توان
double power(double base, int exponent) {
    double result = 1;
    // اگر توان منفی باشد
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    // محاسبه توان
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
// تابع برای عملگرهای ساده
void simple_operators() {
    double result = 0;
    double number = 0;
    char operation = '+'; // شروع با عملگر جمع
    char input[100]; // آرایه برای ورود   
    cout << "لطفاً عبارات عددی و عملگرها را وارد کنید:" << endl;
    // خواندن رشته ورودی
    cin.getline(input, 100);
    // بررسی ورود "ok" برای محاسبه
    if (input[0] == 'o' && input[1] == 'k' && input[2] == '\0') {
        cout << "هیچ عددی وارد نشده است." << endl;
        return;
    }
    // پردازش ورودی
    for (int i = 0; input[i] != '\0'; i++) {
        // چک کردن عدد
        if (isdigit(input[i]) || (input[i] == '-' && isdigit(input[i + 1]))) {
            number = 0; // بازنشانی عدد
            // تبدیل کاراکترهای عدد به عدد واقعی
            while (isdigit(input[i]) || input[i] == '.') {
                number = number * 10 + (input[i] - '0');
                i++;
            }
            i--; // برای جبران افزایش ایندکس در حلقه

            // محاسبه بر اساس عملگر
            if (operation == '+') result += number;
            else if (operation == '-') result -= number;
            else if (operation == '*') result *= number;
            else if (operation == '/') {
                if (number != 0) result /= number;
                else {
                    cout << "خطا: تقسیم بر صفر!" << endl;
                    return;
                }
            } else if (operation == '%') {
                result = static_cast<int>(result) % static_cast<int>(number);
            } else if (operation == '^') { // عملگر توان
                result = power(result, static_cast<int>(number)); // نتیجه و عدد حاضر را به توان می‌برد
            }
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                   input[i] == '/' || input[i] == '%' || input[i] == '^') {
            // چک کردن عملگر و ذخیره آن
            operation = input[i];
        } else if (input[i] != ' ') {
            cout << "خطا: عملگر پشتیبانی نمی‌شود!" << endl;
            return;
        }
    }

    // نمایش نتیجه
    cout << "نتیجه: " << result << endl;
}


void bitbyte_operators(string opt, int number) {
  int newnumber;
  if(opt == "--"){
    newnumber = number--;
    cout << newnumber << "--->" << number << endl; 
  } else if(opt == "++"){
    newnumber = number++;
    cout << newnumber << "--->" << number << endl;
  } else {
    cout << "wronge option!" << endl;
  }
}

void compare_operators(int fnumber, int snumber) {
    if(fnumber > snumber){
      cout << "number " << fnumber << " is greater than " << snumber << endl;
    } else if(fnumber < snumber){
      cout << "number " << snumber << " is greater than " << fnumber << endl;
    } else if(fnumber == snumber){
      cout << "number " << fnumber << " equals to " << snumber << endl;
    } else if(fnumber == snumber){
      cout << "number " << snumber << " equals to " << fnumber << endl;
    } else {
      cout << "operator is not valid" << endl;
    }
}

void equ_operator(int fnumber, int snumber){
  if(fnumber == snumber){
    cout << "numbers " << fnumber << " and " << snumber << " are equal" << endl;
  } else {
    cout << "numbers " << fnumber << " and " << snumber << " are not equal" << endl;
  } 
}

void absolute_operator(int number) {
  if(number < 0){
    cout << "the absolute value of " << number << " is " << -number << endl;
  } else {
    cout << "the absolute value of " << number << " is " << number << endl;
  }
}

void sin_operator(int number) {
  float radian = number * (M_PI / 180.0);
  float sinvalue = sin(radian);
  cout << "the sin of " << number << " is " << sinvalue << endl;
}
void cos_operator(int number) {
  float radian = number * (M_PI / 180.0);
  float cosvalue = cos(radian);
  cout << "the cos of " << number << " is " << cosvalue << endl;
}
//main function:
int main() {
    int fnumber, snumber;
    int option;
    string opt;
    int number;
    cout << "welcome to cli(command line) calculator!" << endl;
    cout << "[+]choose which option of math you wanna use: \n" << endl;
    cout << "[1]+\n[2]-\n[3]*\n[4]/\n[5]**\n[6]square\n[7]%\n[8]++\n[9]--\n[10]<\n[11]>\n[12]is equal\n[13]not equal\n[14]absolute value\n[15]sin\n[16]cos\n\n" << endl; 
    cin >> option;
    cin.ignore(); // برای جلوگیری از مشکل با getline بعدی
    switch (option) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            simple_operators();
            break; 
        case 8:
        case 9:
            cout << "[+]which option? -- or ++? -->" << endl;
            cin >> opt;
            cout << "[+]ok, enter your number-->" << endl;
            cin >> number;
            bitbyte_operators(opt,number);
            break;
        case 10:
        case 11:
            cout << "[+]enter first number-->" << endl;
            cin >> fnumber;
            cout << "[+]enter second number--->" << endl;
            cin >> snumber;
            compare_operators(fnumber,snumber);
            break;
        case 12:
        case 13:
            cout << "[+]enter first number-->" << endl;
            cin >> fnumber;
            cout << "[+]enter second number-->" << endl;
            cin >> snumber;
            equ_operator(fnumber,snumber);
            break;
        case 14:
            cout << "[+]enter your number--->" << endl;
            cin >> number;
            absolute_operator(number);
            break;
        case 15:
            cout << "[+]enter your number-->" << endl;
            cin >> number;
            sin_operator(number);
            break;
        case 16:
            cout << "[+]enter your number-->" << endl;
            cin >> number;
            cos_operator(number);
            break;
        default:
            cout << "option is not supported!" << endl;
            break;
    }
    cout << "\n\n\ndeveloped by Amirreza Azizi" << endl;
}
 
