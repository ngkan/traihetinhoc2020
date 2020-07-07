#include <bits/stdc++.h>
using namespace std;

const string NAME = "RECT2";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

long long Rand(long long lo,long long hi){
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    if (testId == 0){
        input << "2\n0 0 2 2\n1 1 3 3";
        return;
    }
    if (testId == 1){
        input << "2\n0 0 1 1\n1 1 2 2";
        return;
    }
    int t;
    if (testId < 5)
        t = 3;
    else if (testId < 10)
        t = 10;
    else
        t = 20;
    
    input << t << '\n';
    while(t--){
        int a, b, c, d;
        if (testId < 5){
            a = Rand(0, 10);
            b = Rand(0, 10);
            c = Rand(0, 10);
            d = Rand(0, 10);
        }
        else if (testId < 10){
            a = Rand(0, (int) 1e5);
            b = Rand(0, (int) 1e5);
            c = Rand(0, (int) 1e5);
            d = Rand(0, (int) 1e5);
        }
        else{
            a = Rand(0, (int) 1e9);
            b = Rand(0, (int) 1e9);
            c = Rand(0, (int) 1e9);
            d = Rand(0, (int) 1e9);
        }
        if (a > c)
            swap(a, c);
        if (b > d)
            swap(b, d);

        input << a << ' ' << b << ' ' << c << ' ' << d << '\n';
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