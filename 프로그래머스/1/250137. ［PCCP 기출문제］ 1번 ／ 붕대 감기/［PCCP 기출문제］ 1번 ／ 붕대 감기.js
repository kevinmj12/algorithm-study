function solution(bandage, health, attacks) {
    var answer = 0;
    
    
    answer = health;
    answer -= attacks[0][1];

    if (answer <= 0){
        answer = -1;
        return answer;
    }
    
    for (let i = 1; i < attacks.length; i++){
        var cur_atk_time = attacks[i][0];
        var prev_atk_time = attacks[i-1][0];
        
        answer += (cur_atk_time - prev_atk_time - 1) * bandage[1];
        answer += Math.trunc((cur_atk_time - prev_atk_time - 1) / bandage[0]) * bandage[2];
        if (answer > health){
            answer = health;
        }
        
        answer -= attacks[i][1];
        if (answer <= 0){
            answer = -1;
            break;
        }
    }
    
    return answer;
}