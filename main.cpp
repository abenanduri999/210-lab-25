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
    auto startlr = high_resolution_clock::now(); 
    list<string> l1;
    for(int i = 0; i < CODES_SIZE; i++)
    {
        l1.push_back(codes[i]); 
    }
    auto endlr = high_resolution_clock::now(); 
    auto durationlr = duration_cast<milliseconds>(endlr - startlr);
    cout<<"Time taken: "<<durationlr.count()<<endl; 

    //auto startsr = high_resolution_clock::now(); 
    
    auto startvs = high_resolution_clock::now(); 
    sort(v1.begin(), v1.end()); 
    auto endvs = high_resolution_clock::now(); 
    auto durationvs = duration_cast<milliseconds>(endvs - startvs); 

    auto startls = high_resolution_clock::now(); 
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/