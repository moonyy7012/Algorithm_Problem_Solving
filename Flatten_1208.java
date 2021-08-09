// SW Expert Academy
// 1208. [S/W 문제해결 기본] 1일차 - Flatten
import java.util.Scanner;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;

class Flatten_1208 {
	public static void main(String args[]) throws Exception {
		Scanner scan = new Scanner(System.in);
		for (int test_case = 1; test_case <= 10; test_case++) {
			int ans = 0;

			int maxcnt = scan.nextInt();

			ArrayList<Integer> a = new ArrayList<>();
			for (int i = 0; i < 100; i++) {
				a.add(scan.nextInt());
			}

			int maximum = 0, minimum = 0;
			int max_id = 0, min_id = 0;
			while (maxcnt >= 0) {
				maximum = Collections.max(a);
				minimum = Collections.min(a);
				for (int i = 0; i < a.size(); i++) {
					if (a.get(i) == maximum) {
						max_id = i;
					}
					if (a.get(i) == minimum) {
						min_id = i;
					}
				}

				ans = maximum - minimum;
				if (ans <= 1)
					break;
				a.set(max_id, maximum - 1);
				a.set(min_id, minimum + 1);
				maxcnt--;
			}

			System.out.println("#" + test_case + " " + ans);

		}
	}
}