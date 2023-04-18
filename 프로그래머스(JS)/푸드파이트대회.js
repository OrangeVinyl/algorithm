/**
 * @discription reverse()와 slice()를 이해하고 JS에서 배열의 인자를 삽입, 삭제하는 과정을 이해
 */

function solution(food) {
    let answer = [];
    
    for (let i = 1 ; i < food.length ; i++) {
        if (food[i] === 1) continue;
        
        let t = 0;
        do {
            answer.push(i);
            t ++;
        } while (t < Math.floor(food[i] / 2)) 
    }
    
    answer.push(0);
    answer = [...answer, ...answer.slice(0,-1).reverse()].join('');    
        
    return answer;
}