using namespace std;
//y=(-h/w)*x+h;

long long solution(int w,int h) {
    long long answer = 1;
    double cnt=0;
    for(double x=0; x<w; x++){
//         소수에 대한 연산이 여러번 있을 경우 부정확한 값이 나올 수도 있음.
//         나누기보다 곱하기를 먼저 해준 후 나누기를 나중에 해주는 것이 더 정확.
        double y1=-(double)h*x/w+(double)h;
        double y2=-(double)h*(x+1)/w+(double)h;
        if((long long)y1!=y1) y1=(long long)y1+1;
        if((long long)y2!=y2) y2=(long long)y2;

        cnt+=(y1-y2);

    }

    answer=(long long)w*h-(long long)cnt;

    return answer;
}
