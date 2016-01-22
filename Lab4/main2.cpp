///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 4/29/15
 * CS162_400_W2015_Lab4
 ***********************************************/
///

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sort(ifstream& input1, ifstream& input2, ofstream& output);

int main()
{
    string file1;
    string file2;
    string output;
    ifstream inputFile1;
    ifstream inputFile2;
    
    cout << "Name the first input file: ";
    cin >> file1;
    cout << endl;
    
    cout << "Name the second input file: ";
    cin >> file2;
    cout << endl;
    
    cout << "Name the output file." << endl;
    cin >> output;
    cout << endl;
    
    inputFile1.open (file1.c_str());
    inputFile2.open (file2.c_str());
    ofstream outputFile(output.c_str());
    
    cout << "Sending files to be sorted." << endl;
    sort(inputFile1, inputFile2, outputFile);
    
    inputFile1.close();
    inputFile2.close();
    outputFile.close();
    
    return 0;
}

/***********************************************
 *                    sort                     *
 *  Takes 2 input files and 1 output file as   *
 *  arguments, sorts the values and combines   *
 *  then into the output file.                 *
 ***********************************************/

void sort(ifstream& input1, ifstream& input2, ofstream& output)
{
    cout << "In sort function." << endl;  // check that the function is called correctly
    
    int value1, value2;
    input1 >> value1;
    input2 >> value2;
    
    
    while(!input1.eof() && !input2.eof())
    {
        if(value1 <= value2)
        {
            output << value1 << endl;
            input1 >> value1;
        }
        else
        {
            output << value2 << endl;
            input2 >> value2;
        }
    }
    while(!input1.eof())
    {
        output << value1 << endl;
        input1 >> value1;
    }
    while(!input2.eof())
    {
        output << value2 << endl;
        input2 >> value2;
    }
    
    cout << "Your files have been combined and sorted."  << endl;
    
}