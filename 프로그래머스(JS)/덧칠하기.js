function solution(n, m, section) {
    let cnt = 0;
    let painted = 0;
    for (let block of section) {
        if (painted < block) {
            cnt++;
            painted = block + m - 1;
        }
    }
    return cnt;
}
