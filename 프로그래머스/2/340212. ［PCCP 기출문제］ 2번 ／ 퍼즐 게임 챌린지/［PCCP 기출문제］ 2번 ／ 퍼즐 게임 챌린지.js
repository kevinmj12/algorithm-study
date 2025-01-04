function solution(diffs, times, limit) {
    var answer = 0;
      
    var left = 1, right = 100000;
    while (left <= right){
        var mid = left + Math.trunc((right - left) / 2)
        
        var time = cal_time(diffs, times, mid)
        if (time > limit){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    answer = left;
    return answer;
}

function cal_time(diffs, times, level){
    var rtn = 0;
    
    for (let i = 0; i < diffs.length; i++){
        if (diffs[i] <= level){
            rtn += times[i]; 
        }
        else{
            rtn += (times[i] + times[i-1]) * (diffs[i]-level);
            rtn += times[i];
        }
    }
    return rtn;
}