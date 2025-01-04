function solution(points, routes) {
    var answer = 0;
    
    const graph = [];
    for (let i = 0; i <= 100; i++) {
      const row = [];
      for (let j = 0; j <= 100; j++) {
        row.push(0);
      }
      graph.push(row);
    }
    
    var routesCur = [];
    for (let i = 0; i < routes.length; i++){
        var tmp = [];
        tmp.push(points[routes[i][0]-1][0]);    // y좌표
        tmp.push(points[routes[i][0]-1][1]);    // x좌표
        tmp.push(1);
        routesCur.push(tmp);
    }
    
    // 0초에서의 위험 상황 판단
    for (let i = 0; i < routesCur.length; i++){
        if (graph[routesCur[i][0]][routesCur[i][1]] === 1){
            answer++;
        }
        graph[routesCur[i][0]][routesCur[i][1]]++;
    }
    
    while (routesCur.length){
        resetGraph(graph);
        for (let i = 0; i < routesCur.length; i++){
            // 마지막 포인트에 도착한 경우
            if (routesCur[i][2] === routes[i].length){
                routesCur.splice(i, 1);
                routes.splice(i, 1);
                i--;
                continue;
            }
            var nextY = points[routes[i][routesCur[i][2]]-1][0];
            var nextX = points[routes[i][routesCur[i][2]]-1][1];
            if (routesCur[i][0] < nextY){
                routesCur[i][0]++;
            }
            else if (routesCur[i][0] > nextY){
                routesCur[i][0]--;
            }
            else if (routesCur[i][1] < nextX){
                routesCur[i][1]++;
            }
            else {
                routesCur[i][1]--;
            }
            // 이동 후 좌표에 도착한 경우
            if (routesCur[i][0] === nextY && routesCur[i][1] === nextX){
                routesCur[i][2]++;
            }
            // 충돌 가능성이 있는 경우
            if (graph[routesCur[i][0]][routesCur[i][1]] === 1){
                answer++;
            }
            graph[routesCur[i][0]][routesCur[i][1]]++;
        }
    }
    
    
    return answer;
}

function resetGraph(graph){
    for (let i = 0; i < graph.length; i++) {
      for (let j = 0; j < graph[i].length; j++) {
          graph[i][j] = 0;
      }
    }
}

