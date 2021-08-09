// SW Expert Academy
// 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.FileInputStream;

class 최빈수구하기_1204 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			int t;
			t = sc.nextInt();
			ArrayList<Integer> score = new ArrayList<>();
			for (int i = 0; i < 1000; i++)
				score.add(sc.nextInt());

			int[] cnt = new int[101];
			for (int num : score)
				cnt[num]++;

			int ans = 0, maximum = 0;
			for (int i = 0; i < 101; i++) {
				if (maximum <= cnt[i]) {
					maximum = cnt[i];
					ans = i;
				}
			}

			System.out.println("#" + test_case + " " + ans);

		}
		sc.close();
	}
}