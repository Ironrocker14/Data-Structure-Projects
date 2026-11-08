
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    if (infix.empty())
    {
        cout << "Invalid expression!";
        return 0;
    }

    bool needOperand = true;
    int brackets = 0;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isspace(ch))
            continue;

        if (isalnum(ch))
        {
            if (!needOperand)
            {
                cout << "Invalid expression!";
                return 0;
            }

            postfix += ch;
            needOperand = false;
        }
        else if (ch == '(')
        {
            if (!needOperand)
            {
                cout << "Invalid expression!";
                return 0;
            }

            s.push(ch);
            brackets++;
            needOperand = true;
        }
        else if (ch == ')')
        {
            if (needOperand || brackets == 0)
            {
                cout << "Invalid expression!";
                return 0;
            }

            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (s.empty())
            {
                cout << "Invalid expression!";
                return 0;
            }

            s.pop();
            brackets--;
            needOperand = false;
        }
        else if (isOperator(ch))
        {
            if (needOperand)
            {
                cout << "Invalid expression!";
                return 0;
            }

            while (!s.empty() && s.top() != '(' && (priority(s.top()) > priority(ch) || (priority(s.top()) == priority(ch) && ch != '^')))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
            needOperand = true;
        }
        else
        {
            cout << "Invalid character!";
            return 0;
        }
    }

    if (needOperand || brackets != 0)
    {
        cout << "Invalid expression!";
        return 0;
    }

    while (!s.empty())
    {
        if (s.top() == '(')
        {
            cout << "Invalid expression!";
            return 0;
        }

        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

