#include <bits/stdc++.h>
using namespace std;

const string NAME = "QMUL";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 20;           // number of tests

mt19937_64 rd;

int Rand(int lo,int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    int n, q;

    if (testId < 2)
        n = 10,
        q = 10;
    else if (testId < 8)
        n = 1000, 
        q = 1000;
    else
        n = Rand(99000, 100000), 
        q = Rand(99000, 100000);

    input << n << '\n';
    for(int i=1;i<=n;i++)
        if (testId < 2)
            input << Rand(1, 10) << ' ';
        else{
            if (testId % 2 == 0)
                input << Rand(1, 1000000000) << ' ';
            else 
                input << Rand(1, 1000) << ' ';
        }
    input << '\n';
    input << q << '\n';
    for(int i=1;i<=q;i++){
        int l = Rand(1, n);
        int r = Rand(1, n);
        if (l > r)
            swap(l, r);
        input << l << ' ' << r << '\n';
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