function tribonacci(signature, n) {
  if (n <= 3) {
    switch(n) {
      case 0:
        return [];
      case 1:
        return [1];
      case 2:
        return [signature[0], signature[1]];
      case 3:
        return signature;
      default:
        return [];
        break;
    }

  } else {
    let a = tribonacci(signature, n-1);
    let j = a.length;
    signature.push(a[j-3] + a[j-2] + a[j-1]);
    return signature;
  }
  
}

let a = tribonacci([1,1,1], 10);
let b = [1,1,1,3,5,9,17,31,57,105];
console.log(a == b);


/*
doTest([ [1,1,1], 10], [1,1,1,3,5,9,17,31,57,105]   )
doTest([ [0,0,1], 10], [0,0,1,1,2,4,7,13,24,44]     )
doTest([ [0,1,1], 10], [0,1,1,2,4,7,13,24,44,81]    )
doTest([ [1,0,0], 10], [1,0,0,1,1,2,4,7,13,24]      )
doTest([ [0,0,0], 10], [0,0,0,0,0,0,0,0,0,0]        )
doTest([ [1,2,3], 10], [1,2,3,6,11,20,37,68,125,230])
doTest([ [3,2,1], 10], [3,2,1,6,9,16,31,56,103,190] )
doTest([ [1,1,1],  1], [1])
*/