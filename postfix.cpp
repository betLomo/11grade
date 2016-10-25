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
                string tmp;
                tmp=Stack.top();
                Stack.pop();
                int i = atoi(tmp.c_str());
                cout << i << "+";

                string tmp2;
                tmp2 = Stack.top();
                Stack.pop();
                int j =atoi(tmp2.c_str());
				cout << j << "=";
                int end=i+j;
                cout << end << endl;

                string send;
                ss.clear();
                ss<<end;
                ss>>send;
                cout<<send<<endl;
                Stack.push(send);
            }
            if(word=="-")
            {
                string tmp;
                tmp=Stack.top();
                Stack.pop();
                int i = atoi(tmp.c_str());


                string tmp2;
                tmp2 = Stack.top();
                Stack.pop();
                int j =atoi(tmp2.c_str());
                cout << j << "-";
				cout << i << "=";
                int end=j-i;
                cout << end << endl;

                string send;
                ss.clear();
                ss<<end;
                ss>>send;
                cout<<send<<endl;
                Stack.push(send);
            }
            if(word=="*")
            {
                string tmp;
                tmp=Stack.top();
                Stack.pop();
                int i = atoi(tmp.c_str());
                cout << i << "*";

                string tmp2;
                tmp2 = Stack.top();
                Stack.pop();
                int j =atoi(tmp2.c_str());
                cout << j << "=";

                int end=i*j;
                cout << end << endl;

                string send;
                ss.clear();
                ss<<end;
                ss>>send;
                cout<<send<<endl;
                Stack.push(send);
            }
            if(word=="/")
            {
                string tmp;
                tmp=Stack.top();
                Stack.pop();
                int i = atoi(tmp.c_str());
                cout << i << "/";

                string tmp2;
                tmp2 = Stack.top();
                Stack.pop();
                int j =atoi(tmp2.c_str());
                cout << j << "=";

                int end=j/i;
                cout << end << endl;

                string send;
                ss.clear();
                ss<<end;
                ss>>send;
                cout<<send<<endl;
                Stack.push(send);
            }
        }
    }
    cout << Stack.top();

    return 0;
}

