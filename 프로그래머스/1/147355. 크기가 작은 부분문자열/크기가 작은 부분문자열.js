function solution(t, p) {
    const numP = Number(p);
    let cnt = 0;
    
    for (i = 0 ; i <= t.length - p.length; i++) {
        const slicedT = t.slice(i, i + p.length);
        const numT = Number(slicedT)
        
        if (slicedT <= numP) cnt++
    }
    
    return cnt
}