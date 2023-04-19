/**
 * @param {Int} k score에 최대로 들어갈 점수
 * @param {Int} m 한 상자에 들어가는 사과의 수
 * @param {[]} score 사과들의 점수
 * @returns 
 */

function solution(k, m, score) {
    let answer = 0;
      score.sort((a, b) => a - b);
      while (score.length >= m) {
        let box = [];
        for (let i = 0; i < m; i++) {
          box.push(score.pop());
        }
        answer += Math.min(...box) * m;
      }
      return answer;
    }

const solution = (_, m, s) => { // 매개변수는 underscore(_)로 표시됨
    s.sort() // 배열 s를 오름차순으로 정렬
      .filter((_, i) => !((s.length - i) % m)) // 배열 s에서 m의 배수 위치의 요소만 선택
      .reduce((a, v) => a + v, 0) // 선택된 요소를 모두 더함
      * m; // 합계에 m을 곱해서 결과값을 계산함
  };