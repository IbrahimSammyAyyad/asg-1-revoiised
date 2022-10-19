//Ibrahim Sammy Ayyad, Data Structures ASSIGNEMNT 1
//Tues-Thurs 4:00-5:15 class.

using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

//print function to check array
void printa(int atp[]) {
    for (int i = 0; i < 19; i++) {
        cout << atp[i] << endl;
    }
}



//pretty much all of these functions utilize pointers to 
//create a new array, reassign it's values, and then
//perform one final action (add, delete, change, etc)

int add(int* x[], int orig[], int a) {
    int i;
    *x = new int[20];
    for (i = 0; i < 19; i++) {
        (*x)[i] = orig[i];
    }
    (*x)[i] = a;
    return 0;
}

int adelete(int* x[], int orig[], int t) {

    *x = new int[20];
    for (int i = 0; i < 19; i++) {
        (*x)[i] = orig[i];
    }

    (*x)[t] = 0;
    cout << "Deleted a_ints[" << t << "].\n";
    return 0;
}

int replace(int* x[], int orig[], int t, int r) {
    int hold;
    *x = new int[20];
    for (int i = 0; i < 19; i++) {
        (*x)[i] = orig[i];
    }
    hold = (*x)[t];
    (*x)[t] = r;
    cout << "Changed " << hold << " to " << (*x)[t] << endl;
    return 0;
}

void check_e(int fints[], int test) {
    for (int i = 0; i < 19; i++) {



        if (test == fints[i]) {
            cout << "Your number " << test << " was located at position " << i << ".\t";
            break;
        }
        else {


        }
    }

}


int* a_ints = new int[20];


ifstream ints1;



int main() {


    cout << "Reading floats" << endl;
    ints1.open("int_file.txt");


    cout << "first batch of input\n" << endl;
    try
    {

        while (ints1.eof() == false) {
            for (int i = 0; i < 19; i++) {
                string line;
                //float convline;

                //(getline(floats1, line));
                ints1 >> line;
                // istringstream iss(line);
                int convline = stoi(line);
                a_ints[i] = convline;
                cout << a_ints[i] << endl;

            }

        }

    }
    catch (...) {
        cout << "carry on\n";
    }

    cout << "running check function\n";
    check_e(a_ints, 34567);

    cout << "running change function\n";
    replace(&a_ints, a_ints, 3, 69696);

    cout << "running add function\n";
    add(&a_ints, a_ints, 42042);

    cout << "running print function\n";
    printa(a_ints);

    cout << "running delete function\n";
    adelete(&a_ints, a_ints, 0);

    cout << "running print function\n";
    printa(a_ints);


    ints1.open("int_file.txt");
    return 0;
}


