#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateTAC(string if_else_statement)
{
    vector<string> tac; // List of three-address instructions
    string condition, then_clause, else_clause;

    // Parsing the input if-else statement
    size_t pos_if = if_else_statement.find("if");
    size_t pos_then = if_else_statement.find("then");
    size_t pos_else = if_else_statement.find("else");

    condition = if_else_statement.substr(pos_if + 3, pos_then - pos_if - 4);
    then_clause = if_else_statement.substr(pos_then + 5, pos_else - pos_then - 6);
    else_clause = if_else_statement.substr(pos_else + 5);

    // Generating TAC
    tac.push_back("L1: if " + condition + " goto L2");
    tac.push_back(then_clause);
    tac.push_back("goto L3");
    tac.push_back("L2: " + else_clause);
    tac.push_back("L3:");

    return tac;
}

int main()
{
    string if_else_statement = "if (a > b) then c = a else c = b"; // Dummy input

    vector<string> tac = generateTAC(if_else_statement);

    cout << "Three-address code instructions:" << endl;
    for (const string &instruction : tac)
    {
        cout << instruction << endl;
    }

    return 0;
}
