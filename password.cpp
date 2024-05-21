#include <iostream>
#include <string>
#include <cstdlib> //memory management[calloc,malloc,realloc,free],program control[exit,abort,atexit]
#include <ctime>
using namespace std;

/*
      => the rand() function will generate a psuedo-random integer between 0 and RAND_MAX. RAND_MAX is a constant that is defined in the <cstdlib> header representing the maximum value that the std::rand() can return back
      => srand(time(nullptr)) is used to seed the value for the random number generated that is unique for each second
      => rand() % size ensures that the given index lies within the range of the alphanumeric string i.e., 0 and 61 (both inclusive)
*/

string generatePassword(int length)
{
    string password = ""; // initializing the password string
    string alphanumeric = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int size = alphanumeric.size();
    int index;
    srand(time(nullptr));
    for (int i = 0; i < length; i++)
    {
        index = rand() % size;
        password += alphanumeric[index];
    }
    return password;
}

int main()
{
    int length;
    cout << "\nEnter the length of the password:  ";
    cin >> length;
    string password = generatePassword(length);
    cout << "Generated password ::   " << password;
    return 0;
}