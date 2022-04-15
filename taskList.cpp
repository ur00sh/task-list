/*
Author: Urosh Petrovic
Date: 16th April 2022
Project: Interactive task list with real-time data
Description: Provides whether a user has completed or not completed self-declared tasks, with real-time data written in a .txt file
Language: C++ 
*/

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

//setting up current time
string currentTime() 
{
    time_t tt;
    struct tm*st;

    tt = time(NULL);
    st = localtime(&tt);
    return asctime(st);
}

int main (void)
//beginning of the program
{
    //declaring variables
    int scorePos, scoreNeg, score;
    char c1, c2, c3, c4, c5;
    string date;
    string task1, task2, task3, task4, task5;
    //declaring a .txt file
    fstream file;
    //start writing and reading .txt file
    file.open("check.txt", ios::out | ios::in);

    date = currentTime();
    cout<<"Date and time: "<<date<<endl;
    //prints out date in the .txt file
    file << date << endl;
    //user input of tasks (5 tasks per day)
    cout<<"List of tasks:"<<endl;
    
    cout<<"Task 1: ";
    cin>>task1;
    
    cout<<"Task 2: ";
    cin>>task2;
    
    cout<<"Task 3: ";
    cin>>task3;
    
    cout<<"Task 4: ";
    cin>>task4;
    
    cout<<"Task 5: ";
    cin>>task5;
    
    //checks if tasks were completed
    cout<<"Type 'y' if you completed the task, type 'n' if you didn't."<<endl;
    cout<<"Did you complete task number 1? ("<<task1<<")"<<endl;
    cout<<"Answer: ";
    cin>>c1;
    conf1:
    if (c1 == 'y') {
        scorePos+=1;
        //writes in .txt file if the task has been completed
        file << "Task 1: " << task1  << " - task completed" << endl;
    }
    else if (c1 == 'n') {
        scoreNeg+=1;
        //writes in .txt file if the task has been completed
        file << "Task 1: " << task1  << " - task not completed" << endl;
    }
    else {
        cout<<"Error: Invalid data. Please, try again."<<endl;
        goto conf1;
    }
    cout<<"Did you complete task number 2? ("<<task2<<")"<<endl;
    cout<<"Answer: ";
    cin>>c2;
    conf2:
    if (c2 == 'y') {
        scorePos+=1;
        file << "Task 2: " << task2  << " - task completed" << endl;

    }
    else if (c2 == 'n') {
        scoreNeg+=1;
        file << "Task 2: " << task2  << " - task not completed" << endl;
    }
    else {
        cout<<"Error: Invalid data. Please, try again."<<endl;
        goto conf2;
    }

    cout<<"Did you complete task number 3? ("<<task3<<")"<<endl;
    cout<<"Answer: ";
    cin>>c3;
    conf3:
    if (c3 == 'y') {
        scorePos+=1;
        file << "Task 3: " << task3  << " - task completed" << endl;
    }
    else if (c3 == 'n') {
        scoreNeg+=1;
        file << "Task 3: " << task3  << " - task not completed" << endl;
    }
    else {
        cout<<"Error: Invalid data. Please, try again."<<endl;
        goto conf3;
    }

    cout<<"Did you complete task number 4? ("<<task4<<")"<<endl;
    cout<<"Answer: ";
    cin>>c4;
    conf4:
    if (c4 == 'y') {
        scorePos+=1;
        file << "Task 4: " << task4  << " - task completed" << endl;
    }
    else if (c4 == 'n') {
        scoreNeg+=1;
        file << "Task 4: " << task4  << " - task not completed" << endl;
    }
    else {
        cout<<"Error: Invalid data. Please, try again."<<endl;
        goto conf4;
    }

    cout<<"Did you complete task number 5? ("<<task5<<")"<<endl;
    cout<<"Answer: ";
    cin>>c5;
    conf5:
    if (c5 == 'y') {
        scorePos+=1;
        file << "Task 5: " << task5  << " - task completed" << endl;
    }
    else if (c5 == 'n') {
        scoreNeg+=1;
        file << "Task 5: " << task5  << " - task not completed" << endl;
    }
    else {
        cout<<"Error: Invalid data. Please, try again."<<endl;
        goto conf5;
    }
    //scoring system
    score = scorePos - scoreNeg;
    cout<<"Completed tasks: "<<scorePos<<endl;
    cout<<"Non completed tasks: "<<scoreNeg<<endl;
    cout<<"Score: "<<score<<endl;

    //writes score in .txt file
    file << "Completed tasks: " << scorePos << endl;
    file << "Not completed tasks: " << scoreNeg << endl;
    file << "Score: " << score << endl;

    //finish writing and reading .txt file
    file.close();
    
    return 0;
}
