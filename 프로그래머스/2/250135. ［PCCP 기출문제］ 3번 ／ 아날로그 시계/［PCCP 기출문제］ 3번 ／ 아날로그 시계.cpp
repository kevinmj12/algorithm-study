#include <vector>

using namespace std;

// 특정 시점(초)에서 각 바늘의 위치(각도)를 계산
// 정수 연산을 위해 12 * 60 * 60을 곱한 값을 사용하기도 합니다.
bool isOver(int h, int m, int s, int nh, int nm, int ns, bool checkHour) {
    // 현재 각도와 다음 각도 계산 (여기서는 이해를 돕기 위해 개념적 설명)
    // 1초 동안 초침이 시침(또는 분침)을 지나갔는지 판별
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    long start = h1 * 3600 + m1 * 60 + s1;
    long end = h2 * 3600 + m2 * 60 + s2;

    // 0초부터 시작해서 1초 단위로 검사
    for (long t = start; t < end; t++) {
        // 현재 시간의 각 바늘 각도
        double curr_s = (t % 60) * 6;
        double curr_m = (t % 3600) / 10.0;
        double curr_h = (t % 43200) / 120.0;

        // 1초 뒤 시간의 각 바늘 각도
        double next_s = ((t + 1) % 60 == 0) ? 360 : ((t + 1) % 60) * 6;
        double next_m = ((t + 1) % 3600 / 10.0 == 0) ? 360 : (t + 1) % 3600 / 10.0;
        double next_h = ((t + 1) % 43200 / 120.0 == 0) ? 360 : (t + 1) % 43200 / 120.0;

        bool s_m = (curr_s < curr_m) && (next_s >= next_m);
        bool s_h = (curr_s < curr_h) && (next_s >= next_h);

        if (s_m && s_h) {
            // 시침, 분침, 초침이 한꺼번에 만나는 경우 (12시 등)
            if (next_m == next_h) answer += 1;
            else answer += 2;
        } else if (s_m || s_h) {
            answer += 1;
        }
    }

    // 시작 시간에 이미 겹쳐 있는 경우 예외 처리
    if (start == 0 || start == 12 * 3600) answer += 1;

    return answer;
}