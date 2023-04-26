/**
 * @description 약수 갯수를 구하는 알고리즘을 정확히 알고 있어야 한다.
 * 1. 일반적으로 모든 숫자를 순회하며 약수 구하기
 * 2. 약수의 최댓값은 결국 약수를 구하고자 하는 수 / 2 이기 때문에 1부터 해당 수까지만 순회하면서 약수 구하기
 * 3. Math.sqrt() 를 이용하여 구하기
 */

function solution(number, limit, power) {
    const numberArray = []
    for (let i = 1 ; i <= number ; i++) {
        if (getDivisorsTotal(i) > limit) { 
            numberArray.push(power)
        } else {
               numberArray.push(getDivisorsTotal(i))
        }
    }  
    return numberArray.reduce((a,b) => a + b)
}

const getDivisorsTotal = (num) => {
    const divisors = [];
    for (let i = 1 ; i <= Math.sqrt(num) ; i++) {
        if (num % i === 0) { 
            divisors.push(i);
            if (num / i != i) divisors.push(num / i);
        }
    }
  
    return divisors.length
}