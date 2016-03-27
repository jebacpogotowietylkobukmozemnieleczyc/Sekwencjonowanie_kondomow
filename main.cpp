#include <iostream>
#include <vector>
#include <fstream>

#define A_BIN 0
#define C_BIN 1
#define G_BIN 2
#define T_BIN 3

#define OLI_LENGTH 10


using namespace std;

class OlinukleoLibrary{
private:
    vector<int> oliLib;
public:
    uint32_t stringIntoIntCoder(string sequence);
    string intIntoStringCoder(uint32_t codedNumber);
    void readFromFile(const char* fname);
    void printVector();
    void printVectorAsString();
};

uint32_t OlinukleoLibrary::stringIntoIntCoder(string sequence){
    uint32_t result = 0;

    for( int i = 0; i < sequence.length(); i++){
        switch(sequence.at(i)){
            case 'A': result = result | A_BIN;
                break;

            case 'C': result = result | C_BIN;
                break;

            case 'G': result = result | G_BIN;
                break;

            case 'T': result = result | T_BIN;
                break;
        }
        result = result<<2;
    }
    result = result>>2;

    return result;
}


string OlinukleoLibrary::intIntoStringCoder(uint32_t codedNumber){
    string result;

    for( int i = OLI_LENGTH-1; i >= 0; i--){
        switch( (codedNumber>>(i*2))&3){
            case A_BIN: result+="A";
                break;

            case C_BIN: result+="C";
                break;

            case G_BIN: result+="G";
                break;

            case T_BIN: result+="T";
                break;
        }
    }

    return result;
}

void OlinukleoLibrary::readFromFile(const char* fname){
    fstream file;
    int iterator = 0;
    string tmp;

    file.open(fname, ios::in);
    while (!file.eof()){
        file >> tmp;
        oliLib.push_back(OlinukleoLibrary::stringIntoIntCoder(tmp));
        iterator++;
    }
    file.close();

}

void OlinukleoLibrary::printVector(){
    for (int i = 0; i < oliLib.size(); i++){
        cout << oliLib[i] << endl;
    }
}

void OlinukleoLibrary::printVectorAsString(){
    for (int i = 0; i < oliLib.size(); i++){
        cout << OlinukleoLibrary::intIntoStringCoder(oliLib[i]) << endl;
    }
}


bool checkIfMatch(uint32_t leftOli, uint32_t rightOli){
    if ( (leftOli & ((1<<18)-1) ) == ( (rightOli>>2) & ((1<<18)-1)) ) return true;
    else return false;
}


int main(int argc, char *argv[]) {
    cout << "Test Kondoma" << endl;

    OlinukleoLibrary kondom;
    if (argc > 1) kondom.readFromFile(argv[1]);
    else kondom.readFromFile("E:\\QtPROJECTS\\sekwencjonowanie_kondomow\\data\\positive\\10.500+50");

    //kondom.printVectorAsString();

    cout << checkIfMatch(kondom.stringIntoIntCoder("ACGCGTTTAA"), kondom.stringIntoIntCoder("CGCCTTTAAT")) << endl;

    return 0;
}
