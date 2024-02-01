#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e, start;

vector<pair<int, int>> edges[300000]; // [시작 노드]{ 도착 노드 , 가중치 }

int dist[300000];

void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq; // <거리, 노드> 

    pq.push({ 0,start }); // 시작 노드의 거리 0 
    dist[start] = 0;

    while (!pq.empty())
    {
        int val = -pq.top().first; //현재 노드까지의 비용
        int now = pq.top().second; // 현재 노드
        pq.pop();

        if (dist[now] < val) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;

        for (int i = 0; i < edges[now].size(); i++)
        {
            int next = edges[now][i].first;
            int cost = val + edges[now][i].second; // 거쳐서 가는 노드의 비용을 계산
            // 현재노드까지 비용 + 다음 노드 비용
            if (cost < dist[next]) // 비용이 더 작다면 최단경로 테이블 값을 갱신.
            {
                dist[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> start;

    int head, tail, weight;
    for (int i = 0; i < e; i++) {
        cin >> head >> tail >> weight;

        edges[head].push_back({ tail, weight });
    }

    // 거리를 무한에 가까운 수로 초기화
    for (int& i : dist) {
        i = 2000000000;
    }

    dijkstra(start);

    // 모든 노드로 가기 위한 최단 거리를 출력
    for (int i = 1; i <= v; i++)
    {
        // 도달할 수 없는 경우, 무한(INFINITY)이라고 출력
        if (dist[i] == 2000000000) {
            cout << "INF" << '\n';
        }
        // 도달할 수 있는 경우 거리를 출력
        else {
            cout << dist[i] << '\n';
        }
    }
}