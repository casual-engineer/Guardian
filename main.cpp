#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string hostsFilePath = "C:\\Windows\\System32\\drivers\\etc\\hosts";

int main() {
    // Read hosts.txt into a dynamic array
    vector<string> hosts;
    ifstream inFile("hosts.txt");
    if (!inFile) {
        cerr << "Error: Unable to open hosts.txt\n";
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        hosts.push_back(line);
    }
    inFile.close();

    // Write contents of the dynamic array to the Windows hosts file
    ofstream outFile(hostsFilePath, ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open hosts file (" << hostsFilePath << ")\n";
        return 1;
    }

    for (const auto& host : hosts) {
        outFile << host << '\n';
        cout << "Writing: " << host << '\n';
    }
    outFile.close();

    cout << "Contents written to hosts file successfully.\n";
    return 0;
}
