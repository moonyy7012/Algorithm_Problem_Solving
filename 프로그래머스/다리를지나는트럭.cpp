#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> pass(bridge_length, 0);
	int sum = 0;
	for (int i = 0; i < truck_weights.size(); i++) {
		while (1) {
			if (pass[0]) {
				sum -= pass[0];
			}
			for (int j = 1; j < bridge_length; j++)
				pass[j - 1] = pass[j];

			pass[bridge_length - 1] = 0;

			if (sum + truck_weights[i] <= weight) {
				pass[bridge_length - 1] = truck_weights[i];
				sum += truck_weights[i];
				answer++;
				break;
			}
			else {

				answer++;
			}

		}

	}
	answer += bridge_length;




	return answer;
}