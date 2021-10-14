// SW Expert Academy
//1210. [S/W 문제해결 기본] 2일차 - Ladder1
import java.util.Scanner;

public class Ladder1_1210 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=1; i<=10; i++) {
			int t = sc.nextInt();
			int[][] arr = new int[100][100];
			int end_j = 0;
			for(int j=0; j<100; j++) {
				for(int k=0; k<100; k++) {
					arr[j][k] = sc.nextInt();
					if(arr[j][k]==2) {end_j = k;}
				}
			}
			int y=99, pasttp = 1;
			while(y>0) {
				if(end_j+1<100 && arr[y][end_j+1]==1 && pasttp!=2) {
					pasttp=3;
					while(end_j+1<100 && arr[y][end_j+1]==1)end_j+=1;
					continue;
				}
				if(end_j-1>=0 && arr[y][end_j-1]==1 && pasttp!=3) {
					pasttp=2;
					while(end_j-1>=0 && arr[y][end_j-1]==1)end_j-=1;
					continue;
				}
				if(arr[y-1][end_j]==1) {
					pasttp=1;
					y-=1;
				}
				
			}
			System.out.println("#"+i+" "+end_j);
		}
		
	}
}
