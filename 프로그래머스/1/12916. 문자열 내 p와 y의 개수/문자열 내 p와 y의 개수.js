function solution(s){
    var answer = true
    let pCnt = 0;
    let yCnt = 0;

    for (i = 0 ; i < s.length; i++) {
        if (s[i] === 'p' || s[i] === 'P') {
            pCnt += 1
        } else if (s[i] === 'y' || s[i] === 'Y') {
            yCnt += 1
        }
    }
    
    
    
    pCnt === yCnt ?  answer = true : answer = false
    
    return answer
}