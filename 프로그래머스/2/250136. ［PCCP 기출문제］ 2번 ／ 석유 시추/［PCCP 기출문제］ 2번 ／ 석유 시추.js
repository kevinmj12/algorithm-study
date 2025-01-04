function solution(land) {  
    const row = land.length;
    const col = land[0].length;
    
    const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    let lands = new Array(col).fill(0);
    let visited = Array.from({ length: row }, () => new Array(col).fill(false));
    const landSet = new Set();
    
    function bfs(i, j) {
        const queue = [[i, j]];
        visited[i][j] = true;
        let size = 0;
        const columnSet = new Set();

        while (queue.length) {
          const [y, x] = queue.shift();
          size++;
          columnSet.add(x);

          for (const [dy, dx] of dir) {
            let nextY = y + dy;
            let nextX = x + dx;

            if (nextY < 0 || nextY >= row || nextX < 0 || nextX >= col || visited[nextY][nextX]) {
                continue;
            }
            if (land[nextY][nextX] === 1) {
              queue.push([nextY, nextX]);
              visited[nextY][nextX] = true;
            }
          }
        }

        for (const column of columnSet) {
          lands[column] += size;
        }
      }

    for (let r = 0; r < row; r++) {
        for (let c = 0; c < col; c++) {
            if (!visited[r][c] && land[r][c] === 1) {
                bfs(r, c); 
            }
        }
    }
    
    return Math.max(...lands);
}
