#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> lowerToUpper(const string& str, string currentString, int i, vector<string>& finalResult)
{
    if(i == str.size())
    {
        finalResult.push_back(currentString);
        return finalResult;
    }

    lowerToUpper(str,currentString + str[i],i +1,finalResult);

    if (str[i] >= 97 && str[i] <= 122)
        lowerToUpper(str,currentString + char(str[i] -32),i+1,finalResult);
    return finalResult;
}
void print(string & input)
{
    for(auto& i : input) {
        cout<<i;
    }
    cout<<"\n";
}
void print(vector<string> str)
{
    for(auto& i : str)
    {
        cout<<"[ "<<i<<"] ";
    }
    cout<<"\n";
}
int main()
{
    string input;
    getline(cin,input);
    print(input);
    vector<string> result;
    print(lowerToUpper(input,"",0,result));

    return 0;
}