#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace std::chrono; 

const int CODES_SIZE = 20000; 

int main() {

    ifstream input("codes.txt");
    string codes[CODES_SIZE]; 
    int i = 0; 
    while(input >> codes[i++])
    input.close(); 
    
    
    list<string> l1; 
    set<string> s1; 
    
    auto startvr = high_resolution_clock::now(); 
    vector<string> v1; 
    for(int i = 0; i < CODES_SIZE; i++)
    {
        v1.push_back(codes[i]);
    }
    auto endvr = high_resolution_clock::now(); 
    auto durationvr = duration_cast<milliseconds>(endvr - startvr); 

    cout<<"time taken: "<<durationvr.count()<<endl; 

    auto 

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/