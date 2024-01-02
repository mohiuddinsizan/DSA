#include<iostream>
#include"stackfunctio.cpp"
using namespace std;

bool operatorcheck(char ch)
{
    if(ch=='+' || ch=='/' ||ch=='*' ||ch=='-')
        return true;
    else
        return false;
}

int precidence(char ch)
{
    if(ch=='/' || ch=='*')
        return 4;
    /*if(ch=='*')
        return 3;*/
    if(ch=='+' || ch=='-')
        return 2;
    /*if(ch=='-')
        return 1;*/
    else
        return 0;
}
bool validityCheck(const string & str)
{
    Stack<char> Paranthese(100);

    for(char c : str)
    {
        if (c == '(')
        {
            Paranthese.push(c);
        }
        else if (c == ')')
        {
            if (Paranthese.isEmpty() || Paranthese.topValue() != '(')
            {
                return false;
            }
            Paranthese.pop();
        }
    }
    return Paranthese.isEmpty();
}

double calculation(double op1,double op2,char c)
{
    if(c=='+')
        return op1+op2;
    if(c=='-')
        return op1-op2;
    if(c=='*')
        return op1*op2;
    if(c=='/')
        return op1/op2;
}

double expression(const string & str, bool & validity)
{
    validity = validityCheck(str );
    if(!validity)
    {
        return 0;
    }
    Stack<double> Number(1000);
    Stack<char> operato_r(1000);

    bool lastoperator = false;
    for(int i =0 ; i<str.length(); i++)
    {
        char c = str[i];
        if(c==' ')
            continue;
        if(c=='(')
        {
            //cout<<"hi"<<endl;
            operato_r.push(c);
            lastoperator = false;
        }
        else if(c>='0' && c<= '9')
        {
            string numStr;
            while((c>='0'  && c<='9') || c=='.')
            {
                numStr += c;
                i++;
                c=str[i];
            }
            double op = stod(numStr);
            Number.push(op);
            //cout<<op<<endl;
            lastoperator = false;
            //Number.print();
        }
        else if(c==')')
        {
            while(!operato_r.isEmpty() && operato_r.topValue()!='(')
            {
                char op = operato_r.topValue();
                operato_r.pop();

                double a2 = Number.topValue();
                Number.pop();
                //cout<<a2<<endl;

                double a1 = Number.topValue();
                Number.pop();
                //cout<<a1<<endl;

                double result = calculation(a1,a2,op);
                Number.push(result);
                //cout<<result<<endl;
            }
            if(!operato_r.isEmpty() && operato_r.topValue()=='(')
            {
                operato_r.pop();
            }
            lastoperator = false;
        }
        else if(operatorcheck(c))
        {
            if (c == '-')
            {
                // Check if it is a unary minus
                if (i == 0 || str[i - 1] == '(' || operatorcheck(str[i - 1]))
                {
                    operato_r.push(c);
                    lastoperator = true;
                    continue;
                }
            }
            /*if(lastoperator)
            {
                //cout<<"hi"<<endl;

                validity = false;
                return 0;

            }*/
            while(!operato_r.isEmpty() && operato_r.topValue() != '(' && precidence(operato_r.topValue())>=precidence(c))
            {
                char op = operato_r.topValue();
                operato_r.pop();

                double a2 = Number.topValue();
                Number.pop();
                //cout<<a2<<endl;

                double a1 = Number.topValue();
                Number.pop();
                //cout<<a1<<endl;

                double result = calculation(a1,a2,op);
                Number.push(result);
                //cout<<result<<endl;

                //cout<<"hello"<<endl;
            }
            operato_r.push(c);
            //operato_r.print();
            //cout<<operato_r.topValue()<<endl;
            // cout<<operato_r.length()<<endl;
            //cout<<operato_r.isEmpty()<<endl;
            lastoperator = true;

        }
        else
        {

            validity = false;
            return 0;
        }
    }
    //cout<<operato_r.isEmpty()<<endl;
    while (!operato_r.isEmpty())
    {
        //cout<<"hello"<<endl;
        char op = operato_r.topValue();
        operato_r.pop();

        double a2 = Number.topValue();
        Number.pop();
        //cout<<a2<<endl;

        double a1 = Number.topValue();
        Number.pop();
        //cout<<a1<<endl;

        double result = calculation(a1,a2,op);
        Number.push(result);
        //cout<<result<<endl;
    }
    return Number.topValue();
}
int main()
{
    string str;
    getline(cin,str);
    bool validity;
    double result = expression(str,validity);

    if(validity)
        cout<<result<<endl;
    else
        cout<<"Invalid Expresion ! "<<endl;

    return 0;
}
