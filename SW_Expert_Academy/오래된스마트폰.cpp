#include <iostream>
using namespace std;
int n, o, m;
int numbers[11]; // ���� �� �ִ� ���� �迭
char operators[5];  //���� �� �ִ� ������ �迭 
int want; // ���ϴ� �����
int best[1000]; //�� ���ڸ� ����� �� ������ �ּ� Ƚ��
int used[1000];
int group[1000]; //����(int)���� ���� �迭  
int grpCnt; 
int groupNumCnt[1000]; //������ ���� ����
int groupUsed[1000]; //0~999 �� ����� ���� �� �ִ� ������ �迭��-> 1
void init() //�ʱ⼼��
{
	for (int i = 0; i < 1000; i++) {
		best[i] = 99;
		used[i] = 0;
	}
	for (int i = 0; i < grpCnt; i++) 
		best[group[i]] = groupNumCnt[i]; //������ ������ �ּ�Ƚ��->���� ����
	
}
int getCalResult(int a, char oper, int b)
{
	if (oper == '*') return a * b;
	if (oper == '-') return a - b;
	if (oper == '/') return a / b;
	return a + b;
}
//������ ������ ���� �� �ִ� �ּ� Ŭ�� Ƚ�� ���ϱ�
void getMinClickCnt(int clickCnt, int now) //now: ù��° �ǿ�����, clickCnt: ù��°�ǿ����ڸ� ����� �� �ּ� Ŭ��Ƚ��
{
	for (int x = 0; x < o; x++) {
		for (int i = 0; i < grpCnt; i++) {
			int num = group[i];  //�ι�° �ǿ�����
			int nextCnt = clickCnt + groupNumCnt[i] + 1;  //'now * num' ������ Ŭ��Ƚ��
			if (nextCnt > m - 1) break;  //�ִ�Ƚ�� ������ ��
			if (operators[x] == '/' && num == 0) continue;  //������ �� 0�̸� X
			int next = getCalResult(now, operators[x], num);  //���갪

			//���갪�� �ִ���� �Ѿ���ʴ��� ����
			if (operators[x] == '+' && next > 999) break;  
			if (operators[x] == '-' && next < 0) break;
			if (operators[x] == '*' && next > 999) break;
			
			if (used[next] == 1) continue;//�̹� ���� ���갪�̹Ƿ� �Ѿ
			//���� Ƚ���� best���� �� ������ ����
			if (best[next] <= nextCnt) continue;
			best[next] = nextCnt;
			used[next] = 1;  //���� �߰�������̶�� used�迭�� 1����(�Ŀ� �Ȱ��� �������� �� ������ �ּ�Ƚ���� �ƴϹǷ� ����)
			getMinClickCnt(nextCnt, next);
			used[next] = 0;
		}
	}
}
//next�� ������ int�� ���ڸ� ���� �� groupUsed�迭 �ش�����ε��� ��ġ�� 1�� ���� ->�ݺ�
void dfs(int now)  
{
	for (int i = 0; i < n; i++) {
		int next = now * 10 + numbers[i];  
		if (next > 999) continue;  //999���� ����
		if (groupUsed[next] == 1) continue; //�̹� ���� ����
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
	dfs(0); //���� �����
	for (int i = 0; i < 1000; i++) {
		if (groupUsed[i] == 0) continue;
		group[grpCnt] = i;  //���� ���� group�迭�� ����
		if (i < 10) groupNumCnt[grpCnt] = 1;   //������ ���̸� groupNumCnt�� ����
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
		if (best[want] != 99) ans = best[want]; //���� ������ ������ ���̸�ŭ�� �̹� �ּ��̹Ƿ� init()���� ���̷� ���������Ƿ� �ٷ� ��.
		else { //�ѹ��� ���� �� X, ���� �ʿ�
			for (int i = 0; i < grpCnt; i++) {
				getMinClickCnt(groupNumCnt[i], group[i]);  
			}
			ans = best[want] + 1; //best������ '=' Ŭ��Ƚ�� 1�� ���� ���� ������
		}

		if (best[want] == 99) ans = -1;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}



