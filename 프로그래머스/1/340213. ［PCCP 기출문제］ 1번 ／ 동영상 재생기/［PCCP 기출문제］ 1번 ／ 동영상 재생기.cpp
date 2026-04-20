#include <string>
#include <vector>

using namespace std;

struct Time{
    int minute;
    int second;
    Time(string pos){
        minute = stoi(pos.substr(0, 2));
        second = stoi(pos.substr(3, 2));
    }
};

string timeToStr(Time t){
    string sm = to_string(t.minute);
    if (sm.length() == 1){
        sm = "0"+sm;
    }
    string ss = to_string(t.second);
    if (ss.length() == 1){
        ss = "0"+ss;
    }
    
    string rtn = sm + ":" + ss;
    
    return rtn;
}

bool isOp(string op_start, string op_end, string pos){
    Time opStartT = Time(op_start);
    Time opEndT = Time(op_end);
    Time posT = Time(pos);
    
    int opStartS = 60 * opStartT.minute + opStartT.second;
    int opEndS = 60 * opEndT.minute + opEndT.second;
    int posS = 60 * posT.minute + posT.second;
    
    if (opStartS <= posS && posS <= opEndS){ 
        return true;
    }
    return false;
}

string cmdNext(string pos, string video_len, string op_start, string op_end){
    Time posT = Time(pos);
    posT.second += 10;
    
    while (posT.second >= 60){
        posT.second -= 60;
        posT.minute++;
    }
    if (isOp(op_start, op_end, timeToStr(posT))){
        return op_end;
    }
    Time endT = Time(video_len);
    int endS = endT.minute * 60 + endT.second;
    int posS = posT.minute * 60 + posT.second;
    
    if (posS >= endS){
        return video_len;
    }
    
    return timeToStr(posT);
}

string cmdPrev(string pos, string video_len, string op_start, string op_end){
    Time posT = Time(pos);
    posT.second -= 10;
    
    while (posT.second < 0){
        posT.second += 60;
        posT.minute--;
    }
    if (posT.minute < 0){
        posT = Time("00:00");
    }
    if (isOp(op_start, op_end, timeToStr(posT))){
        return op_end;
    }
    
    return timeToStr(posT);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    if (isOp(op_start, op_end, pos)){
        pos = op_end;
    }
    
    for (string cmd: commands){
        if (cmd == "next"){
            pos = cmdNext(pos, video_len, op_start, op_end);
        }
        else{
            pos = cmdPrev(pos, video_len, op_start, op_end);
        }
    }
    
    answer = pos;
    return answer;
}