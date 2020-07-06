#include <bits/stdc++.h>
using namespace std;

const string NAME = "BRACKET";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

int Rand(int lo,int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    int n;

    if (testId < 2)
        n = 10;
    else if (testId < 8)
        n = 1000;
    else
        n = Rand(99000, 100000);

    if (testId < 2){
        for(int i=1;i<=n;i++){
            if (Rand(0, 1))
                input << '(';
            else
                input << ')';
        }
    }
    else if (testId < 8){
        for(int i=1;i<=100;i++){
            input << '(';
        }
        for(int i=101;i<=n;i++){
            if (Rand(0, 1 + testId % 2))
                input << '(';
            else
                input << ')';
        }
    }
    else{
        for(int i=1;i<=10000;i++){
            input << '(';
        }
        for(int i=10001;i<=n;i++){
            if (Rand(0, 1 + testId % 2))
                input << '(';
            else
                input << ')';
        }
    }
}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();

    rd.seed(randomSeed);
    for(int _ = 0; _ < NTEST; _++){
        string id;          // id of current test
        stringstream ss;
        ss << _;
        ss >> id;
       // cerr << _ << ' '  << endl;
        cout << "Making test: " << id << endl;
        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR " + NAME + "\\Test" + id).c_str()),
            input  = NAME+"\\Test" + id + '\\' + NAME + ".INP",
            output = NAME+"\\Test" + id + '\\' + NAME + ".OUT";
       

        ofstream inputFile(input.c_str());
        
        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}