#include <bits/stdc++.h>
using namespace std;

const string NAME = "LINE";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

int Rand(int lo,int hi){
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    if (testId == 0){
        input << "3\n0 0\n1 3\n1 2";
        return;
    }

    int t;
    if (testId < 2)
        t = 3;
    else if (testId < 8)
        t = 1000;
    else
        t = 100000;
    
    input << t << '\n';
    while(t--){
        if (testId < 2)
            input << Rand(0, 5) << ' ' << Rand(0, 5) << '\n';
        else if (testId < 8)
            input << Rand(0, 1000) << ' ' << Rand(0, 1000) << '\n';
        else
            input << Rand(0, 100000) << ' ' << Rand(0, 100000) << '\n';
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