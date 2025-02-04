const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs.readFileSync(filePath).toString().trim().split("\n");
const [n, m] = input[0].split(" ").map(Number);

let destroyers = new Array(n + 1).fill(0);

for (let i = 1; i <= n; i++) {
  let arr = input[i].split(" ").map(Number);
  for (let j = 0; j < m; j++) {
    if (arr[j] == 1) {
      destroyers[i]++;
    }
  }
}

let atk1 = input[n + 1].split(" ").map(Number);
let atk2 = input[n + 2].split(" ").map(Number);

for (let i = atk1[0]; i <= atk1[1]; i++) {
  destroyers[i] = Math.max(destroyers[i] - 1, 0);
}
for (let i = atk2[0]; i <= atk2[1]; i++) {
  destroyers[i] = Math.max(destroyers[i] - 1, 0);
}

let answer = 0;
for (let i = 1; i <= n; i++) {
  answer += destroyers[i];
}

console.log(answer);
