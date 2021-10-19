#include <iostream>
using namespace std;
int n, o, m;
int numbers[11]; // 누를 수 있는 숫자 배열
char operators[5];  //누를 수 있는 연산자 배열 
int want; // 원하는 결과값
int best[1000]; //각 숫자를 만드는 데 누르는 최소 횟수
int used[1000];
int group[1000]; //만든(int)조합 담은 배열  
int grpCnt; 
int groupNumCnt[1000]; //각각의 조합 길이
int groupUsed[1000]; //0~999 중 계산기로 누를 수 있는 숫자의 배열값-> 1
void init() //초기세팅
{
	for (int i = 0; i < 1000; i++) {
		best[i] = 99;
		used[i] = 0;
	}
	for (int i = 0; i < grpCnt; i++) 
		best[group[i]] = groupNumCnt[i]; //조합의 누르는 최소횟수->조합 길이
	
}
int getCalResult(int a, char oper, int b)
{
	if (oper == '*') return a * b;
	if (oper == '-') return a - b;
	if (oper == '/') return a / b;
	return a + b;
}
//각각의 조합이 나올 수 있는 최소 클릭 횟수 구하기
void getMinClickCnt(int clickCnt, int now) //now: 첫번째 피연산자, clickCnt: 첫번째피연산자를 만드는 데 최소 클릭횟수
{
	for (int x = 0; x < o; x++) {
		for (int i = 0; i < grpCnt; i++) {
			int num = group[i];  //두번째 피연산자
			int nextCnt = clickCnt + groupNumCnt[i] + 1;  //'now * num' 까지의 클릭횟수
			if (nextCnt > m - 1) break;  //최대횟수 넘으면 끝
			if (operators[x] == '/' && num == 0) continue;  //나누는 수 0이면 X
			int next = getCalResult(now, operators[x], num);  //연산값

			//연산값이 최대범위 넘어가지않는지 조사
			if (operators[x] == '+' && next > 999) break;  
			if (operators[x] == '-' && next < 0) break;
			if (operators[x] == '*' && next > 999) break;
			
			if (used[next] == 1) continue;//이미 나온 연산값이므로 넘어감
			//구한 횟수가 best보다 더 적으면 저장
			if (best[next] <= nextCnt) continue;
			best[next] = nextCnt;
			used[next] = 1;  //나온 중간결과값이라면 used배열에 1저장(후에 똑같은 연산결과가 또 나오면 최소횟수가 아니므로 제외)
			getMinClickCnt(nextCnt, next);
			used[next] = 0;
		}
	}
}
//next에 조합한 int형 숫자를 담은 후 groupUsed배열 해당숫자인덱스 위치에 1값 저장 ->반복
void dfs(int now)  
{
	for (int i = 0; i < n; i++) {
		int next = now * 10 + numbers[i];  
		if (next > 999) continue;  //999넘지 않음
		if (groupUsed[next] == 1) continue; //이미 만든 조합
		groupUsed[next] = 1;
		dfs(next);
	}
}
void makeGroup() 
{
	for (int i = 0; i < 1000; i++) {
		group[i] = 0;
		groupUsed[i] = 0;
		groupNumCnt[i] = 0;
	}
	grpCnt = 0;
	dfs(0); //조합 만들기
	for (int i = 0; i < 1000; i++) {
		if (groupUsed[i] == 0) continue;
		group[grpCnt] = i;  //만든 조합 group배열에 저장
		if (i < 10) groupNumCnt[grpCnt] = 1;   //조합의 길이를 groupNumCnt에 저장
		else if (i < 100) groupNumCnt[grpCnt] = 2;
		else if (i < 1000) groupNumCnt[grpCnt] = 3;
		grpCnt++;
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> o >> m;

		for (int i = 0; i < n; i++) cin >> numbers[i];
		for (int i = 0; i < o; i++) {
			int o_input;
			cin >> o_input;
			if (o_input == 1) operators[i] = '+';
			else if (o_input == 2) operators[i] = '-';
			else if (o_input == 3) operators[i] = '*';
			else if (o_input == 4) operators[i] = '/';
		}
		cin >> want;
		makeGroup();
		init();
		int ans = 0;
		if (best[want] != 99) ans = best[want]; //만든 조합은 조합의 길이만큼이 이미 최소이므로 init()에서 길이로 저장했으므로 바로 답.
		else { //한번에 누를 수 X, 연산 필요
			for (int i = 0; i < grpCnt; i++) {
				getMinClickCnt(groupNumCnt[i], group[i]);  
			}
			ans = best[want] + 1; //best값에서 '=' 클릭횟수 1을 더한 값이 최종답
		}

		if (best[want] == 99) ans = -1;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}



