/*Напишите программу, которая вычисляет значение арифметического выражения, записанно‐
го в постфиксной форме. Выражение вводится с клавиатуры в виде символьной строки.*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stack>

using namespace std;

stringstream ss;

int getNumbers(stack <string> &A, int &i, int &j)
{
    string tmp;
    tmp=A.top();
    A.pop();
    i = atoi(tmp.c_str());
    cout << i << " ";

    string tmp2;
    tmp2 = A.top();
    A.pop();
    j =atoi(tmp2.c_str());
    cout << j << "=";

    return i;
    return j;
}

void inStack(stack <string> &A, int result)
{
    string send;
    ss.clear();
    ss<<result;
    ss>>send;
    cout<<send<<endl;
    A.push(send);
}

int main()
{
    stack <string> Stack;
    string postfix;
    string support;
    string word;

    getline (cin, postfix);

    stringstream count(postfix),ss;

    while(count>>support)
    {
        word=support;
        cout<<word<<endl;
        if (word!="+"&&word!="-"&&word!="*"&&word!="/")
            Stack.push (word);

        else
        {
            if(word=="+")
            {
                int number1=0;
                int number2=0;

                getNumbers(Stack, number1, number2);

                int end=number1+number2;
                cout << end << endl;

                inStack (Stack, end);
            }
            if(word=="-")
            {
                int number1=0;
                int number2=0;

                getNumbers(Stack, number1, number2);

                int end=number2-number1;
                cout << end << endl;

                inStack (Stack, end);
            }
            if(word=="*")
            {
                int number1=0;
                int number2=0;

                getNumbers(Stack, number1, number2);

                int end=number1*number2;
                cout << end << endl;

                inStack (Stack, end);
            }
            if(word=="/")
            {
                int number1=0;
                int number2=0;

                getNumbers(Stack, number1, number2);

                int end=number2/number1;
                cout << end << endl;

                inStack (Stack, end);

            }
        }
    }
    string top;
    top = Stack.top();
    Stack.pop();
    if (Stack.empty()==true)
        cout<<top;
    else cout << "ERROR";

    return 0;
}

