function solution(video_len, pos, op_start, op_end, commands) {
    var answer = '';
    
    var video_len_m = parseInt(video_len.substring(0, 2));
    var video_len_s = parseInt(video_len.substring(3, 5));
    var pos_m = parseInt(pos.substring(0, 2));
    var pos_s = parseInt(pos.substring(3, 5));
    var op_start_m = parseInt(op_start.substring(0, 2));
    var op_start_s = parseInt(op_start.substring(3, 5));
    var op_end_m = parseInt(op_end.substring(0, 2));
    var op_end_s = parseInt(op_end.substring(3, 5));
    
    // 시작 위치가 오프닝 사이에 존재하는 경우
    if (is_op(op_start_m, op_start_s, op_end_m, op_end_s, pos_m, pos_s)){
        pos_m = op_end_m;
        pos_s = op_end_s;
    }
    
    for (let i = 0; i < commands.length; i++){
        if (commands[i] === "next"){
            pos_s += 10;
            // 60초 이상일 경우
            if (pos_s >= 60){
                pos_m++;
                pos_s -= 60;
            }
            // 영상의 끝을 넘은 경우
            if (pos_m > video_len_m || (pos_m == video_len_m && pos_s > video_len_s)){
                pos_m = video_len_m;
                pos_s = video_len_s;
            }
            // 오프닝 사이에 존재하는 경우
            if (is_op(op_start_m, op_start_s, op_end_m, op_end_s, pos_m, pos_s)){
                pos_m = op_end_m;
                pos_s = op_end_s;
            }
        }
        else{
            pos_s -= 10;
            // 초가 음수인 경우
            if (pos_s < 0){
                pos_m--;
                pos_s += 60;
            }
            // 분이 음수인 경우
            if (pos_m < 0){
                pos_m = 0;
                pos_s = 0;
            }
            // 오프닝 사이에 존재하는 경우
            if (is_op(op_start_m, op_start_s, op_end_m, op_end_s, pos_m, pos_s)){
                pos_m = op_end_m;
                pos_s = op_end_s;
            }
        }
    }
    
    str_pos_m = String(pos_m);
    str_pos_s = String(pos_s);
    if (str_pos_m.length === 1){
        str_pos_m = "0"+str_pos_m;
    }
    if (str_pos_s.length === 1){
        str_pos_s = "0"+str_pos_s;
    }
    
    answer = str_pos_m + ":" + str_pos_s;
    
    return answer;
}

function is_op(op_start_m, op_start_s, op_end_m, op_end_s, pos_m, pos_s){
    if ((op_start_m < pos_m || (op_start_m == pos_m && op_start_s <= pos_s)) &&
       (op_end_m > pos_m || (op_end_m == pos_m && op_end_s >= pos_s))){
        return true;
    }
    return false;
}