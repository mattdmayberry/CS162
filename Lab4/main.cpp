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
    ifstream inputFile1("File1.txt");
    ifstream inputFile2("File2.txt");
    
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
    ofstream outputFile;
    outputFile.open (output.c_str());
    
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
    
    int a, b;
    vector<int> in1, in2, out; //create a vectors for input streams
    
    while (!input1.eof())
    {
        input1 >> a;
        in1.push_back(a);
    }
    
    while (!input2.eof())
    {
        input2 >> b;
        in2.push_back(b);
    }
    
    //now in1 and in2 are vectors that have the numbers from the input files
    //input files numbers are sorted from low to high
    
    if (in1.size() > in2.size()) // check if input stream 1 is larger
    {
        for (int i = 0; i < in2.size(); i++)
        {
            if (in1[i] > in2[i]) //number at input vector 2 less that respective pos
            {                   //in input vector 1
                out.push_back(in2[i]);
            }
            else if(in1[i] == in2[i]) //numbers are equal
            {
                out.push_back(in1[i]);
                out.push_back(in2[i]);
            }
            else //number in 1 is less than that in vector 2
            {
                out.push_back(in1[i]);
            }
        }
        
        for (int i = in2.size(); i < in1.size(); i++)
        {
            out.push_back(in1[i]); //push remaining numbers from stream 1 into vector
        }
    }
    else //input stream 2 was larger
    {
        for (int i = 0; i < in1.size(); i++)
        {
            if (in1[i] > in2[i]) //number at input vector 2 less that respective pos
            {                   //in input vector 1
                out.push_back(in2[i]);
            }
            else if(in1[i] == in2[i]) //numbers are equal
            {
                out.push_back(in1[i]);
                out.push_back(in2[i]);
            }
            else //number in 1 is less than that in vector 2
            {
                out.push_back(in1[i]);
            }
        }
        
        for (int i = in1.size(); i < in2.size(); i++)
        {
            out.push_back(in1[i]); //push remaining numbers from stream 2 into vector
        }
        
    }
    
    //send vector contents to output file
    for (int i = 0; i < out.size(); i++)
    {
        output << out[i] << endl;
        cout << out[i] << endl;
    }
    
    cout << "Your files have been sorted." << endl;
}