//SW Expert Academy
//1216. [S/W 문제해결 기본] 3일차 - 회문2

import java.util.ArrayList;
import java.util.Scanner;


public class 회문2_1216 {
	static int counting(String line) {
		int maximum=0;
        for(int i=0; i<100; i++){
            for(int j=99; j>i; j--){
                boolean isEqual = true;
                for(int idx=0, last=(j-i)/2; idx<=last; idx++){
                    if(line.charAt(i + idx) != line.charAt(j - idx)){
                        isEqual = false;
                    }
                }
                if(isEqual && maximum<(j-i)+1) maximum=j-i+1;
            }
        }
        return maximum;
    }
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=1; i<=10; i++) {
			int maximum=0;
			sc.nextLine();
			String[] arr = new String[100];
			for(int j=0; j<100; j++) {
				String s = sc.nextLine();
				arr[j]=s;
			}
//			가로 검색
			for(int y=0; y<100; y++) {
				int cnt = counting(arr[y]);
				if(maximum<cnt) maximum=cnt;				
					
			}
//			세로검색
			for(int x=0; x<100; x++) {
				String line = "";
				for(int y=0; y<100; y++)
					line+=arr[y].charAt(x);
			
				int cnt = counting(line);
					
				if(maximum<cnt) maximum=cnt;		
			
			}
			System.out.println("#"+i+" "+maximum);
		}
	}
}
