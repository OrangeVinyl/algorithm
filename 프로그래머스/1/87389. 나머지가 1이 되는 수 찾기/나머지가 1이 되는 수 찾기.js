function solution(n) {
    var answer = 0;
    
    for (i = 2 ; i <1000000; i++) {
        if (n % i == 1) {
            answer = i;
            break;
        }
    }
    
    return answer;
}