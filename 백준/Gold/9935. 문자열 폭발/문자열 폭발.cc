#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
	string str;
	cin >> str;
	
	string bomb;
	cin >> bomb;
	
	
	char lastCh = bomb[bomb.size()-1];
	stack<char> st;
	for(auto& a : str)
	{
		st.push(a);
		
		
		if(st.top() == lastCh && st.size() >= bomb.size())
		{
			string temp;
			for(int i = 0; i < bomb.size(); i++)
			{
				temp += st.top();
				st.pop();
			}
			
			reverse(temp.begin(), temp.end());
			if(temp.compare(bomb) != 0){
				for(int j = 0; j < temp.size(); j++){
					st.push(temp[j]);
				}
			}
		}
	}
	
	string result;
	while(!st.empty())
	{
		result += st.top();
		st.pop();
	}
	
	reverse(result.begin(), result.end());
	if(result.size() == 0)
	{
		cout << "FRULA";
	}
	else{
		cout << result;
	}
	
	
}