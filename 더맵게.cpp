#include <string>
#include <vector>
#include <queue>

using namespace std;
// (정렬 기능이 들어간 큐)우선순위 큐를 이용하여 해결.
// 우선순위 큐는 min heap과 max heap이 있어 데이터를 넣으면 자동으로 정렬이 됨.
//priority_queue<자료형, 구현체, 비교연산자> 
// 우선순위 큐는 원소 하나하나 직접 접근 못 함=> .top()을 이용해서만 접근 가능.
int solution(vector<int> scoville, int K) {
	int answer = 0;
	//     greater은 오름차순, less는 내림차순
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0, len = scoville.size(); i < len; i++)
		pq.push(scoville[i]);

	while (pq.size() > 1 && pq.top() < K) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a + 2 * b);
		answer++;
	}
	if (pq.top() < K) return -1;

	return answer;
}
