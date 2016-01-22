///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/10/15
 * CS162_400_S2015_Lab6
 ***********************************************/
///

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sort(ifstream& input1, ofstream& output);
void linear(int val, ifstream& input1);
void binary(ifstream& input1, ofstream& output);

int main()
{
    string file1;
    string output;
    ifstream inputFile1;
    int selection = 0;
    int val = 0;
    
    
    cout << "Enter the name of the input file: ";
    cin >> file1;
    cout << endl;
    
    cout << "Select an option from the menu: " << endl;
    cout << "1) Search the input file using linear search" << endl;
    cout << "2) Sort the input file (accending order)" << endl;
    cout << "3) Search the sorted file using binary search" << endl;
    cout << "4) Quit" << endl;
    cin >> selection;
    
    
    
    inputFile1.open (file1.c_str());
    
    
    switch(selection)
    {
        case 1:
            cout << "Enter the value to search for in the input file: " << endl;
            cin >> val;
            linear(val, inputFile1);
            break;
            
        case 2:
            cout << "Name the output file." << endl;
            cin >> output;
            cout << endl;
            ofstream outputFile(output.c_str());
            sort(inputFile1, outputFile);
            outputFile.close();
            break;
    }
    
    
    
    
    inputFile1.close();
    
    
    return 0;
}

/***********************************************
 *                 linear                      *
 *  Sorts the input file for a user input val  *
 *  and returns to the user the position of    *
 *  the value in the input file.               *
 ***********************************************/

void linear(int val, ifstream& input1)
{
    vector <int> temp;
    int searchVal = val;
    int in;
    
    while(!input1.eof())
    {
        
        input1 >> in;
        temp.push_back(in);
    }
    
    for(int i = 0; i < temp.size(); i++)
    {
        if(searchVal == temp[i])
        {
            cout << "The value " << searchVal << " was found at position " << temp[i] << " in the input file." << endl;
        }
        else
        {
            cout << "The value was not found in the input file." << endl;
        }
    }
}



/***********************************************
 *                    sort                     *
 *  Takes an input file, sorts the values      *
 *  and prints the sorted values to the        *
 *  output file.                               *
 ***********************************************/

void sort(ifstream& input1, ofstream& output)
{
    vector <int> temp;
    int in;
    int t;
    
    
    // read in first line
    input1 >> in;
    temp.push_back(in);
    
    
    while(input1 >> in)
    {
        temp.push_back(in);
    }
    
    
    for (int i=0; i < temp.size(); i++)
    {
        for (int j=0; j<(temp.size()-1); j++)
        {
            
            if(temp[j] > temp[j + 1])
            {
                t = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = t;
            }
        }
        
    }
    
    
    for(int j = 0; j < temp.size(); j++)
    {
        output << temp[j] << endl;
    }
    
    cout << "The file has been sorted and printed to the output file." << endl;
}