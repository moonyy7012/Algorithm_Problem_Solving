////SW Expert Academy
//1217. [S/W 문제해결 기본] 4일차 - 거듭 제곱

import java.util.Scanner;

public class 거듭제곱_1217 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=1; i<=10; i++) {
			 int n = sc.nextInt();
			 int a = sc.nextInt();
			 int b = sc.nextInt();
			 int ans=1;
			 for(int j=0; j<b; j++)
				 ans=ans*a;
			 
			 System.out.println("#"+i+" "+ans);
		}
	}

}
