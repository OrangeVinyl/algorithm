/**
 * @description Stack을 이용한 간단한 풀이
 * slice 와 splice 함수의 사용법을 명확하게 숙지
 */

function solution(ingredient) {
    let answer = 0;
    const stack = []
    for (let i of ingredient) {
        stack.push(i)
        if (stack.slice(-4).join('') === "1231") {
            stack.splice(-4)
            answer += 1
        }
    }
    return answer;
}