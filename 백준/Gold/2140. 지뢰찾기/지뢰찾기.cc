#include <iostream>

int xMove[8] = {-1,-1,-1,0,0,1,1,1};
int yMove[8] = {-1, 0, 1,-1,1,-1,0,1};

using namespace std;
//0, n-1만 확인
char map[101][101];

int main() {
	int n;
	cin >> n;
	char c;
	
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++){
			cin >> c;
			map[i][k] = c;
		}
	}
	
	for(int i = 1; i < n-1; i++)
	{
		for(int k = 1; k < n-1; k++){
			bool isBoom = true;
			for(int j=0; j<8; j++){
				int move_X = i + xMove[j];
				int move_Y = k + yMove[j];
				
				if(map[move_X][move_Y] == '0'){
					// 지뢰가 될 수 없다.
					map[i][k] = '-';
					isBoom = false;
				}
			}
			if(isBoom){ // 폭탄이면 주변 숫자 감소
				for(int j =0; j < 8; j++)
				{
					int move_X = i + xMove[j];
					int move_Y = k + yMove[j];
					
					
					if(map[move_X][move_Y] > '0' && map[move_X][move_Y] < '3')
					{
						map[move_X][move_Y]--;
					}
				}
			}
		}
	}
	
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		for(int k=0; k<n; k++){
			if(map[i][k] == '#')
			{
				cnt++;
			}
		}
	}
	
	cout << cnt;
}