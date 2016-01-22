///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/2/15
 * CS162_400_S2015_Lab5
 ***********************************************/
///

#include <iostream>
#include <fstream>
#include <string>
#include "Filter.h"
using namespace std;

int main()
{
    cout << "CS162_400_S2015 Lab5: Created by Matt Mayberry" << endl;
    string file1;
    string out1;
    ifstream in;
    
    
    cout << "Enter the name of your input file: ";
    cin >> file1;
    cout << endl;
    
    cout << "Name the output file." << endl;
    cin >> out1;
    
    in.open (file1.c_str());
    ofstream out(out1.c_str());

    int selection = 0;
    
    cout << "Select how to proceed (1 - 5): " << endl;
    cout << "1) Send unchanged input data to output file. " << endl;
    cout << "2) Encrypt input data and send to output file. " << endl;
    cout << "3) Transform input data to uppercase and send to output file. " << endl;
    cout << "4) Ciphertext input data and send to output file. " << endl;
    cout << "5) Quit. " << endl;
    cin >> selection;
        

    
    if (selection == 1)
    {
        Unchanged unchange;
        unchange.doFilter(in, out);
    }
    
    if (selection == 2)
    {
        Encryption encrypt;
        int shiftKey;
        cout << "Enter the shift key for the encryption cipher: " << endl;
        cin >> shiftKey;
        encrypt = Encryption(shiftKey);
        encrypt.doFilter(in, out);
    }
    
    if (selection == 3)
    {
        Uppercase upper;
        upper.doFilter(in, out);
    }
        
    if (selection == 4)
    {
        Ciphertext cipher;
        int shiftKey;
        cout << "Enter the shift key for the encryption cipher: " << endl;
        cin >> shiftKey;
        cipher = Ciphertext(shiftKey);
        cipher.doFilter(in, out);
    }
    
    in.close();
    out.close();
    
    return 0;
        
}
