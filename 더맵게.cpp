#include <string>
#include <vector>
#include <queue>

using namespace std;
// (���� ����� �� ť)�켱���� ť�� �̿��Ͽ� �ذ�.
// �켱���� ť�� min heap�� max heap�� �־� �����͸� ������ �ڵ����� ������ ��.
//priority_queue<�ڷ���, ����ü, �񱳿�����> 
// �켱���� ť�� ���� �ϳ��ϳ� ���� ���� �� ��=> .top()�� �̿��ؼ��� ���� ����.
int solution(vector<int> scoville, int K) {
	int answer = 0;
	//     greater�� ��������, less�� ��������
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
