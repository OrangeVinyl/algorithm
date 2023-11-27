function solution(babbling) {
  let answer = 0
  const pronounce = ['aya', 'ye', 'woo', 'ma']

  for (word of babbling) {
    for (babble of pronounce) {
      if (word.includes(babble.repeat(2))) {
        break
      }
      word = word.split(babble).join(' ')
    }
    if (word.split(' ').join('').length === 0) {
      answer += 1
    }
  }
  return answer
}

/**
 * @description 정규식을 이용한 풀이
 */

function solution(babbling) {
  const regexp1 = /(aya|ye|woo|ma)\1+/
  const regexp2 = /^(aya|ye|woo|ma)+$/

  return babbling.reduce(
    (ans, word) => (!regexp1.test(word) && regexp2.test(word) ? ++ans : ans),
    0
  )
}
