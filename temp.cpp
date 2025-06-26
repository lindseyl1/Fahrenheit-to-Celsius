/*
@author: Lindsey Langston
@Date: 06/04/2025
@Version: 1.0
Course: Programming Languages - CS210
Purpose of Application: To input values from "FahrenheitTemperature.txt"
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFS; //Input file stream
    ofstream outFS; //Output file stream
    string cityName; //First value (city name)
    int tempInFahr; //Second value (temperature in Fahrenheit)


    //Opening the Input file
    cout << "Opening the file FahrenheitTemperature.txt" << endl;
    inFS.open("FahrenheitTemperature.txt");


    if (!inFS.is_open()) { //If the input file is not open
        cout << "Could not open the file." << endl;
        return 1; //Exit with error code
    }
    cout << "File opened successfully." << endl;
    cout << "Reading values from the file..." << endl;

    //Reading values from the input file until end of file
    outFS.open("CelsiusTemperature.txt"); //Create and open the output file
    if (!outFS.is_open()) { //If the output file is not open
        cout << "Error opening the output file." << endl;
        return 1; //Exit with error code
    }

    // Read and convert each line
    while (inFS >> cityName >> tempInFahr) {
        int tempInCels = (tempInFahr - 32) * 5 / 9;
        outFS << cityName << " in Celsius: " << tempInCels << endl;
    }

    //Writing the values to the output file
    cout << "Writing values to the file CelsiusTemperature.txt" << endl;
    int tempInCels = (tempInFahr - 32) * 5 / 9; //Convert Fahrenheit to Celsius

    while (!inFS.eof()) { //While not end of file
        outFS << cityName << " Temperature in Celsius: " << tempInCels << endl; //Write to the output file
        if (inFS >> cityName >> tempInCels) { //Read next value
            continue; //Continue to next iteration
        }
    }
    
    
    cout << "Closing the file." << endl;
    inFS.close(); //Close the input file
    



}