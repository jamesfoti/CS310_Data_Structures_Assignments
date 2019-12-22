/*
 Lab 2
 James Foti
 Red ID: 820124143
 CS 310
 Professor Healey
 7/1/2019
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

void readFile(string fileName);
void printGraph();
void numOfVertices();
void numOfZeroInBoundEdges();
void numOfSelfEdges();
void numOfZeroOutBoundEges();
void contains(string vertexName);

vector<string> listOfVertices;
map<string, vector<string>> mapOfArrayOfVertices;
map<string, map<string, int>> mapOfMapOfVertices;

void readFile(string fileName) {
    string line;
    string firstPhrase, secondPhrase, thirdPhrase;
    int weight;
    
    cout<<"Text file: "<<endl;
    ifstream file(fileName);
    while(getline(file, line)) {
        cout<<line<<endl;
        firstPhrase = "\0";
        secondPhrase = "\0";
        thirdPhrase = "\0";
        
        stringstream ss(line);
        getline(ss, firstPhrase, ',');
        getline(ss, secondPhrase, ',');
        getline(ss, thirdPhrase, ',');
        
        if (firstPhrase == "\0" && secondPhrase == "\0" && thirdPhrase == "\0") {
            continue;
        }
        else if (firstPhrase == "\0" || secondPhrase == "\0" || thirdPhrase == "\0") {
            weight = -1;
        }
        else {
            istringstream iss (thirdPhrase);
            iss >> weight;
        }
        listOfVertices.push_back(firstPhrase);
        listOfVertices.push_back(secondPhrase);
        mapOfArrayOfVertices[firstPhrase].push_back(secondPhrase);
        mapOfMapOfVertices[firstPhrase][secondPhrase] = weight;
    }
    sort(listOfVertices.begin(), listOfVertices.end());
    listOfVertices.erase(unique(listOfVertices.begin(), listOfVertices.end()), listOfVertices.end());
}

void printGraph() {
    cout<<"Graph (Adjacency List):"<<endl;
    for (auto source : mapOfMapOfVertices) {
        cout<<"["<<source.first<<"]";
        for (auto dest : source.second) {
            if (dest.second == -1) {
                cout<<"";
            }
            else {
                cout<<" -> ["<<dest.first << ":" << dest.second<<"]";
            }
        }
        cout<<endl;
    }
}

void numOfVertices() {
    int numberOfVertices = 0;
    for (int i = 0; i < listOfVertices.size(); i++) {
        if (listOfVertices[i] == "\0") {
            continue;
        }
        else {
            numberOfVertices++;
        }
    }
    cout<<"Number of Vertices: "<<numberOfVertices<<"\n";
    cout<<"Vertices: ";
    for (int i = 0; i < listOfVertices.size(); i++) {
        if (listOfVertices[i] == "\0") {
            continue;
        }
        else {
            cout<<"["<<listOfVertices[i]<<"] ";
        }
    }
}

void numOfSelfEdges() {
    cout<<"Vertices with self edges: ";
    for(auto ii = mapOfArrayOfVertices.begin(); ii != mapOfArrayOfVertices.end(); ++ii){
        vector <string> inVect = ii->second;
        if (count(inVect.begin(), inVect.end(), (ii->first))) {
            cout<<"["<<ii->first<<"] ";
        }
    }
}

void numOfZeroInBoundEdges() {
    vector<string>inBoundVertices;
    cout<<"Vertices with ZERO inbound edges: ";
    for(auto ii = mapOfArrayOfVertices.begin(); ii != mapOfArrayOfVertices.end(); ++ii){
        vector <string> inVect = ii->second;
        for (unsigned j=0; j<inVect.size(); j++) {
            inBoundVertices.push_back(inVect[j]);
        }
    }
    for(auto ii = mapOfArrayOfVertices.begin(); ii != mapOfArrayOfVertices.end(); ++ii){
        if (find(inBoundVertices.begin(), inBoundVertices.end(), ii->first)!=inBoundVertices.end()) {
            continue;
        }
        else {
            cout<<"["<<ii->first<<"] ";
        }
    }
}

void numOfZeroOutBoundEges() {
    cout<<"Vertices with ZERO outbound edges: ";
    for(auto ii=mapOfArrayOfVertices.begin(); ii!=mapOfArrayOfVertices.end(); ++ii){
        vector <string> inVect = ii->second;
        for (unsigned j=0; j<inVect.size(); j++){
            if (mapOfArrayOfVertices.find(inVect[j]) == mapOfArrayOfVertices.end()) {
                if (inVect[j] == "\0") {
                    continue;
                }
                else {
                    cout<<"["<<inVect[j]<<"] ";
                }
            }
            else {
                continue;
            }
        }
    }
}

void contains(string vertexName) {
    cout<<"Searching....";
    for (int i = 0; i<listOfVertices.size(); i++) {
        if (listOfVertices[i] == vertexName && listOfVertices[i] != " " && listOfVertices[i] != "\0") {
            cout<<"["<<vertexName<<"] exists in the graph.";
            return;
        }
    }
    cout<<"["<<vertexName<<"] DOES NOT exist in the graph.";
}

int main() {
    cout<<"Enter name of file: ";
    string fileName;
    cin >> fileName;
    cout<<"\n";
    
    readFile(fileName);
    cout<<"\n";

    printGraph();
    cout<<"\n";
    
    numOfVertices();
    cout<<"\n";
    cout<<"\n";
    
    numOfSelfEdges();
    cout<<"\n";
    cout<<"\n";
    
    numOfZeroOutBoundEges();
    cout<<"\n";
    cout<<"\n";
    
    numOfZeroInBoundEdges();
    cout<<"\n";
    cout<<"\n";
    
    contains("A");
    cout<<"\n";
    cout<<"\n";
}
            
