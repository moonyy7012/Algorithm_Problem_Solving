#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<int> dq;  //vector�� �޸� �յڷ� ���� ���� ����
	for (int i = 0, len = priorities.size(); i < len; i++)
		dq.push_back(priorities[i]);

	while (true) {
		if (*max_element(dq.begin(), dq.end()) == dq[0]) { //���� ���� ������ �߿䵵�� ���� ���� ������ �� 
			if (location == 0) { //�� ������ ��û ������ ��� ��������
				answer++;
				break;
			}
			dq.pop_front(); //��û���� �ƴ� ��� �μ�Ǿ� ��Ͽ��� �����ǰ� ��û ������ �ε����� ��ĭ ������ �̵�
			location--;
			answer++;
		}
		else {// ���� ���� ������ ���� �߿䵵 ���� ������ �ƴ� �� �ڷ� �̵�
			dq.push_back(dq[0]);
			dq.pop_front();
			location = location == 0 ? dq.size() - 1 : location - 1; //��û���� ��ġ�� ���� �ε��� �̵�
		}

	}

	return answer;
}