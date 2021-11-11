#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	deque<int> dq;  //vector와 달리 앞뒤로 삽입 삭제 가능
	for (int i = 0, len = priorities.size(); i < len; i++)
		dq.push_back(priorities[i]);

	while (true) {
		if (*max_element(dq.begin(), dq.end()) == dq[0]) { //가장 앞의 문서가 중요도가 가장 높은 문서일 때 
			if (location == 0) { //그 문서가 요청 문서일 경우 빠져나옴
				answer++;
				break;
			}
			dq.pop_front(); //요청문서 아닐 경우 인쇄되어 목록에서 삭제되고 요청 문서의 인덱스도 한칸 앞으로 이동
			location--;
			answer++;
		}
		else {// 가장 앞의 문서가 가장 중요도 높은 문서가 아닐 때 뒤로 이동
			dq.push_back(dq[0]);
			dq.pop_front();
			location = location == 0 ? dq.size() - 1 : location - 1; //요청문서 위치에 따른 인덱스 이동
		}

	}

	return answer;
}