#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;



int main() {
	int num;
	cin >> num;
	
	vector<vector<int>> abilityTable;

	for (int i = 0; i < num; i++) {
		vector<int> tempVec;
		abilityTable.push_back(tempVec);
		for (int j = 0; j < num; j++) {
			int temp;
			cin >> temp;
			abilityTable[i].push_back(temp);
		}
	}

	vector<int> manList;
	for (int i = 0; i < num / 2; i++) {
		manList.push_back(0);
	}
	for (int i = num/2; i < num ; i++) {
		manList.push_back(1);
	}

	vector<int> teamStart;
	vector<int> teamLink;

	int sumTeamStart;
	int sumTeamLink;
	int min = 2000000000;
	int diff;
	do {
		

		sumTeamStart = 0;
		sumTeamLink = 0;

		teamStart.clear();
		teamLink.clear();

	

		for (int i = 0; i < manList.size(); i++) {
			if (manList[i] == 0) {
				teamStart.push_back(i);
			}
			else {
				teamLink.push_back(i);
			}
		}	

		for (int i = 0; i < num/2; i++) {
			for (int k = i + 1; k < num / 2; k++) {
				sumTeamStart += abilityTable[teamStart[i]][teamStart[k]];
				sumTeamStart += abilityTable[teamStart[k]][teamStart[i]];
			}
		}
		for (int i = 0; i < num / 2; i++) {
			for (int k = i + 1; k < num / 2; k++) {
				sumTeamLink += abilityTable[teamLink[i]][teamLink[k]];
				sumTeamLink += abilityTable[teamLink[k]][teamLink[i]];
			}
		}

		
		diff = abs(sumTeamLink - sumTeamStart);
		if (diff < min) {
			min = diff;
		}
	}
	while(next_permutation(manList.begin(), manList.end()));

	cout << min;
}