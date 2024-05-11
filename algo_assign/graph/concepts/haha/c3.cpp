#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateTAC(string while_loop)
{
    vector<string> tac; // List of three-address instructions
    string condition, body;

    // Parsing the input while loop
    size_t pos_open_bracket = while_loop.find("{");
    size_t pos_close_bracket = while_loop.find("}");
    condition = while_loop.substr(6, pos_open_bracket - 7);                                   // Extracting condition
    body = while_loop.substr(pos_open_bracket + 1, pos_close_bracket - pos_open_bracket - 2); // Extracting body

    // Generating TAC
    tac.push_back("L1: if " + condition + " goto L2");
    tac.push_back(body);
    tac.push_back("goto L1");
    tac.push_back("L2:");

    return tac;
}

int main()
{
    string while_loop = "while (a < 10) { a = a + 1; }"; // Dummy input

    vector<string> tac = generateTAC(while_loop);

    cout << "Three-address code instructions:" << endl;
    for (const string &instruction : tac)
    {
        cout << instruction << endl;
    }

    return 0;
}
