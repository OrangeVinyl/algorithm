/**
 *  @description 요격 시스템 문제
 *  @description 그리디 문제
 */

function solution(targets) {
    var answer = 0;
    let e = 0;
    targets.sort((a,b) => a[1] - b[1])
    
    for (let target of targets) {
        if (target[0] >= e) {
            answer += 1
            e = target[1]
        }
    }
    return answer;
}