
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int rank;

    string name, gender, boyName, numBoys, girlName, numGirls;

    cout << "Enter the name you would like to search up: ";
    getline(cin, name);

    cout << "Choose the gender of your name ('male' or 'female'): ";
    getline(cin, gender);

    ifstream inputStream;

    inputStream.open("babyNames2022.txt");
    if (inputStream.fail()){
        cout << "Failed to open file." << endl;
        return 1;
    }

    while (inputStream >> rank >> boyName >> numBoys >> girlName >> numGirls) {
        if (gender == "male" && name == boyName){
            cout << name << " is rank " << rank <<  " in popularity. Also there were " << numBoys << " boys born with that name." << endl;
            break;
        }
        else if (gender == "female" && name == girlName) {
            cout << name << " is rank " << rank <<  " in popularity. Also there were " << numGirls << " girls born with that name." <<  endl;
            break;
        }

    }


    if (inputStream.eof()){
       if(gender == "male"){
           cout << name << " was not among the top 1000 boy names in popularity. " << endl;
       }
       else if (gender == "female"){
           cout << name << " was not among the top 1000 girl names in popularity. " << endl;
       }
    }
    inputStream.close();
    
}