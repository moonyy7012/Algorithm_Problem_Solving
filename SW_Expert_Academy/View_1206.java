// SW Expert Academy
// 1206. [S/W 문제해결 기본] 1일차 - View
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.FileInputStream;

class View_1206 {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		for (int test_case = 1; test_case <= 10; test_case++) {

			int n = sc.nextInt();
			ArrayList<Integer> arr = new ArrayList<>();
			for (int i = 0; i < n; i++)
				arr.add(sc.nextInt());

			int ans = 0;
			for (int i = 2; i < arr.size() - 2; i++) {
				if (arr.get(i - 2) >= arr.get(i) || arr.get(i - 1) >= arr.get(i) || arr.get(i + 1) >= arr.get(i)
						|| arr.get(i + 2) >= arr.get(i)) {
					continue;
				}
				int h[] = new int[4];
				h[0] = arr.get(i - 2);
				h[1] = arr.get(i - 1);
				h[2] = arr.get(i + 1);
				h[3] = arr.get(i + 2);

				int maximum = 0;
				for (int j = 0; j < 4; j++)
					if (maximum < h[j])
						maximum = h[j];

				ans += arr.get(i) - maximum;
			}
			System.out.println("#" + test_case + " " + ans);

		}
		sc.close();
	}
}