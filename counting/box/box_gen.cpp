#include <bits/stdc++.h>
using namespace std;

const string NAME = "BOX";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

long long Rand(long long lo,long long hi){
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    if (testId == 0){
        input << "2\n1 1 1\n2 2 2";
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
            input << Rand(1, 10) << ' ' << Rand(1, 10) << ' ' << Rand(1, 10) << '\n';
        else if (testId < 8)
            input << Rand(1, (long long)1e3) << ' ' << Rand(1, (long long)1e3) << ' ' << Rand(1, (long long)1e3) << '\n';
        else
            input << Rand(1, (long long)1e5) << ' ' << Rand(1, (long long)1e5) << ' ' << Rand(1, (long long)1e5) << '\n';
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