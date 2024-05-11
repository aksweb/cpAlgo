#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to perform operation on operands
int performOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

// Function to generate three-address code for a mathematical expression
vector<string> generateTAC(string expr)
{
    vector<string> tac;    // List of three-address instructions
    stack<int> operands;   // Stack to hold operands
    stack<char> operators; // Stack to hold operators
    int tempVarCount = 1;

    for (char c : expr)
    {
        if (c == ' ') // Skip spaces
            continue;
        else if (isdigit(c))
        {
            // Convert char to int and push onto operands stack
            operands.push(c - '0');
        }
        else if (isOperator(c))
        {
            // Process operators
            while (!operators.empty() && operators.top() != '(' &&
                   ((c != '*' && c != '/') ||
                    (operators.top() == '*' || operators.top() == '/')))
            {
                // Generate TAC for top operator and operands
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Generate TAC instruction
                string tempVar = "t" + to_string(tempVarCount++);
                tac.push_back(tempVar + " = " + to_string(a) + " " + op + " " + to_string(b));
                // Push the result onto operands stack
                operands.push(performOperation(a, b, op));
            }
            // Push the current operator onto operators stack
            operators.push(c);
        }
        else if (c == '(')
        {
            // Push left parenthesis onto operators stack
            operators.push(c);
        }
        else if (c == ')')
        {
            // Process right parenthesis
            while (!operators.empty() && operators.top() != '(')
            {
                // Generate TAC for top operator and operands
                int b = operands.top();
                operands.pop();
                int a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Generate TAC instruction
                string tempVar = "t" + to_string(tempVarCount++);
                tac.push_back(tempVar + " = " + to_string(a) + " " + op + " " + to_string(b));
                // Push the result onto operands stack
                operands.push(performOperation(a, b, op));
            }
            // Pop left parenthesis
            operators.pop();
        }
    }
    // Process remaining operators in stack
    while (!operators.empty())
    {
        // Generate TAC for top operator and operands
        int b = operands.top();
        operands.pop();
        int a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        // Generate TAC instruction
        string tempVar = "t" + to_string(tempVarCount++);
        tac.push_back(tempVar + " = " + to_string(a) + " " + op + " " + to_string(b));
        // Push the result onto operands stack
        operands.push(performOperation(a, b, op));
    }
    return tac;
}

int main()
{
    string expr = "2 + 3 * 4"; // Dummy input

    vector<string> tac = generateTAC(expr);

    cout << "Three-address code instructions:" << endl;
    for (const string &instruction : tac)
    {
        cout << instruction << endl;
    }

    return 0;
}
