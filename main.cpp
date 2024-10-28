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
    
    //READINGS
     
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
    
    // SORTINGS

    auto startvs = high_resolution_clock::now(); 
    sort(v1.begin(), v1.end()); 
    auto endvs = high_resolution_clock::now(); 
    auto durationvs = duration_cast<milliseconds>(endvs - startvs); 

    auto startls = high_resolution_clock::now(); 
    l1.sort();
    auto endls = high_resolution_clock::now(); 
    auto durationls = duration_cast<milliseconds>(endls - startls); 

    //INSERTIONS
    
    auto startvi = high_resolution_clock::now(); 
    int middle = v1.size() / 2; 
    v1.insert(v1.begin(), middle, "TESTCODE"); 
    auto endvi = high_resolution_clock::now(); 
    auto durationvi = duration_cast<milliseconds>(endvi - startvi); 

    auto startli = high_resolution_clock::now();  
    int mid_of_list = l1.size() / 2; 
    auto it = l1.begin(); 
    advance(it, mid_of_list);
    l1.insert(it, "TESTCODE");
    auto endli = high_resolution_clock::now(); 
    auto durationli = duration_cast<milliseconds>(endli - startli); 

    auto startsi = high_resolution_clock::now(); 
    //int mid_of_set = s1.size() / 2; 
    //auto it_s = s1.begin();
    //advance(it_s, mid_of_set);
    s1.insert ("TESTCODE"); // assignment just said insert into the set 
    auto endsi = high_resolution_clock::now(); 
    auto durationsi = duration_cast<milliseconds>(endsi - startsi); 


    // DELETIONS

     auto startvd = high_resolution_clock::now(); 
     v1.erase(v1.begin() + 10000); 
     auto endvd = high_resolution_clock::now();
     auto durationvd = duration_cast<milliseconds>(endvd - startvd); 

     auto startld = high_resolution_clock::now();
     auto l_it = l1.begin();
     advance(l_it, mid_of_list); 
     l1.erase(l_it);
     auto endld = high_resolution_clock::now();
     auto durationld = duration_cast<milliseconds>(endld - startld);

     auto startsd = high_resolution_clock::now();
     auto s_it = s1.begin();
     advance(s_it, mid_of_list); 
     s1.erase(s_it);
     auto endsd = high_resolution_clock::now();
     auto durationsd = duration_cast<milliseconds>(endsd - startsd);  






    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/