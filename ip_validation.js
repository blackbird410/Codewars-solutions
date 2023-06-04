/**
 * Task
 * --------------------------------------------------------------------------------
 * Write an algorithm that will identify valid IPv4 addresses in dot-decimal format. 
 * IPs should be considered valid if they consist of four octets, with values between 0 and 255, inclusive.
 */

function isValidIP(str) {
  if (/([a-z]|\s)/i.test(str) || 
      /^\./.test(str) || 
      /\.$/.test(str)||
      /(\.){2}/.test(str)) return false;
  
  let arr = str.split('.');
  if (arr.length !== 4) return false;
  
  for (o of arr) {
    if (/^[0]./.test(o)) return false;
    let n = parseInt(o);
    if (n < 0 || n > 255) return false;
  }
  return true;
}


let ips =  [
  "105.244.169.164",
  ".236.28.59",
  "123.456.789.0",
  "056.1.2.3",
  "195.286.144.132" 
];

for (ip of ips) {
    console.log(isValidIP(ip));
}