///kamruzzaman leeon 2018-1-60-252
///Md. Nadim    2018-1-60-161
///CSE360 PROJECT
///EWU

#include <bits/stdc++.h>

using namespace std;
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);


/**Explaination of ios_base----> https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull**/


#define ll long long int

/// Functions
bool Digit(char leo);
bool Operator(char leo);
int precision(char leo);
void Addition();
void Substraction();
void Multiplication();
void Division();
void Calculator(char leo);
void PostFix_Operation(string nadim_string);
void postFix();
void inFix();
void init();
stack<ll>Stack;
string str;

void init()
{
    while (!Stack.empty())
        Stack.pop();
}

void Calculator(char leo)
{
    if (leo=='+')
        Addition();
    else if (leo=='-')
        Substraction();
    else if (leo=='*')
        Multiplication();
    else if (leo=='/')
        Division();
}

bool Digit(char leo)
{
    if(leo>='0' && leo<='9')
        return true;
    return false;
}

bool Operator(char leo)
{
    if(leo=='+' || leo=='-' || leo=='*' || leo=='/')
        return true;
    return false;
}

int precision(char leo)
{
    if(leo=='*' || leo=='/')
        return 2;
    else if(leo=='+' || leo=='-')
        return 1;
    else
        return -1;
}

void Addition()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1+operand2;
    Stack.push(operation);
}

void Substraction()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1-operand2;
    Stack.push(operation);
}

void Multiplication()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    operand1=Stack.top();
    Stack.pop();
    operation=operand1*operand2;
    Stack.push(operation);
}

void Division()
{
    ll operand1,operand2,operation;
    operand2=Stack.top();
    Stack.pop();
    if (operand2)
    {
        operand1=Stack.top();
        Stack.pop();
        operation=operand1/operand2;
        Stack.push(operation);
    }
    else
        cout << "\n\tWrong equation!!!\n\n\tInput Correctly Again!\n\n";
}


void PostFix_Operation(string nadim_string)
{
    int l=nadim_string.length();
    for(int i=0; i<l; i++)
    {
        if(nadim_string[i]==' ')
            continue;

        if(Operator(nadim_string[i]))
            Calculator(nadim_string[i]);

        else if(Digit(nadim_string[i]))
        {
            ll opp=0;
            while(i<l && Digit(nadim_string[i]))
            {
                opp=(opp*10)+(nadim_string[i]-'0');
                i++;
            }
            i--;
            Stack.push(opp);
        }
    }
    cout << "\n\tResult: " << Stack.top() << endl << endl;
}

void postFix()
{
    printf("\nEnter The PostFix Equation(Please maintain space) : ");
    cin.ignore();///The cin.ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
    getline(cin,str);
    PostFix_Operation(str);
}

void inFix()
{
    stack<char> st;
    string ns;

    printf("\nEnter The inFix Equation (Please maintain space) :");
    cin.ignore();///The cin.ignore() function is used which is used to ignore or clear one or more characters from the input buffer.
    getline(cin,str);///taking infix  equation from user to str string type

    st.push('N');
    int l=str.length();
    for(int i=0; i<l; i++)
    {
        if(Digit(str[i]))
            ns+=str[i];

        else if (str[i]==' ')
            ns+=' ';

        else if(str[i]=='(')
            st.push('(');

        else if(str[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                ns+=st.top();
                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }
        else
        {
            while(st.top()!='N' && precision(str[i])<=precision(st.top()))///check 110 to 117
            {
                ns+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(st.top()!='N')
    {
        ns+=st.top();
        st.pop();
    }
    PostFix_Operation(ns);
}

int main()
{

    int choice,j=1;
    for (int i=1; i<=j; i++)
    {
        init();
        cout << "\n\n\tEnter Your Expression(It's work only for integer number):\n"
             << "\t\t1. Infix Input\n"
             << "\t\t2. Postfix Input\n"
             << "\tEnter Choice: ";
        cin >> choice;
        if(choice==1)
            inFix();///154 line
        else if(choice==2)
            postFix();
        else
            cout << "\n\n\tWrong Choice.you have to choice between 1 & 2 \n\n";

        cout << "Do you want to continue??? y/n: ";
        char leo;
        cin >> leo;
        if(leo=='y' || leo=='Y')
            j++;
    }
}
