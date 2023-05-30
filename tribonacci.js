function tribonacci(signature, n) {
  /**
   * This function determine an array n of the tribonacci sequence. In a tribonacci 
   * sequence each number is equal to the sum of the three precedent numbers for n > 3.
   */

  if (n <= 3) {
    return (n === 0) ? []
    : (n === 1) ? [1]
    : (n === 2) ? [signature[0], signature[1]]
    : signature;
  }
  
  let a = tribonacci(signature, n-1);
  let j = a.length;
  signature.push(a[j-3] + a[j-2] + a[j-1]);
  return signature;  
}