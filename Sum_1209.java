// SW Expert Academy
//1209. [S/W 문제해결 기본] 2일차 - Sum
import java.util.Scanner;

public class Sum_1209 {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		for(int i=1; i<=10; i++) {
			sc.nextInt();
			int[][] arr = new int[100][100];
			int maximum=0;
			for(int j=0; j<100; j++) {
				int sum=0;
				for(int k=0; k<100; k++) {
					arr[j][k] = sc.nextInt();
					sum+=arr[j][k];
				}
				if(maximum<sum) maximum=sum;
			}
			for(int k=0; k<100; k++) {
				int sum=0;
				for(int j=0; j<100; j++) {
					sum+=arr[j][k];
				}
				if(maximum<sum) maximum=sum;
			}
			System.out.println("#"+i+" "+maximum);
		}
	}
}
