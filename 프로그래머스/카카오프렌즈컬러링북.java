class 카카오프렌즈컬러링북 {
	boolean visited[][];
	int cnt = 0;
	int Maxcnt=0;
	int numberOfArea=0;
//	상하좌우 순서로 i, j의 증가값
	int d_i[] = {-1, 1, 0, 0};
	int d_j[] = {0, 0, -1, 1};
	void visit(int i, int j, int m, int n, int color, int[][] picture){
		if(visited[i][j]==true) return;
		if(color!=picture[i][j]) return;
		visited[i][j]=true;
		cnt++;
		for(int idx=0; idx<4; idx++) {
			int i_idx = i+d_i[idx];
			int j_idx = j+d_j[idx];
			if(i_idx>=0 && i_idx<m && j_idx>=0 && j_idx<n) visit(i_idx, j_idx, m, n, color, picture);
		}
	}
    public int[] solution(int m, int n, int[][] picture) {
        int[] answer = new int[2];
        visited = new boolean [m][n];
        for(int i=0; i<m; i++)
        	for(int j=0; j<n; j++) {
        		if(picture[i][j]==0 || visited[i][j]==true) continue;
        		cnt=0;
        		visit(i, j, m, n, picture[i][j], picture);
        		numberOfArea++;
        		if(cnt>Maxcnt) Maxcnt = cnt;
        	}
        
        answer[0]=numberOfArea;
        answer[1]=Maxcnt;
        return answer;
    }
}