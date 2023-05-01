#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>
#include <chrono>

using namespace std;
int seed = 408;

//job구조체 선언
struct Job{
    int start_time;
    int end_time;
};

//두개의 job의 위치를 바꿀 swap함수
void swap(Job *job1, Job *job2){
    Job temp;
    temp = *job1;
    *job1 = *job2;
    *job2 = temp;
}

//Dynamic Program시 start time기준 오름 차순으로 정렬하기 위해 사용되는 함수
bool cmp_dp(const Job &p1, const Job &p2){
    if(p1.start_time < p2.start_time){
        return true;
    }
    else if(p1.start_time == p2.start_time){
        return true;
    }
    else{
        return false;
    }
}

//Greedy사용시 ent_time기준 오름 차순으로 정렬하기 위해 사용되는 함수
bool cmp_greedy(const Job &p1, const Job &p2){
    if(p1.end_time < p2.end_time){
        return true;
    }
    else if(p1.end_time == p2.end_time){
        return true;
    }
    else{
        return false;
    }
}

//Greedy알고리즘 함수
int greedy(Job *job, int jobNumber){
    int max = 1;
    int start, end;
    int end_index = 0;

    sort(job, job+jobNumber, cmp_greedy); //end_time기준으로 오름차순 정렬

    for(int i = 1; i<jobNumber-1; i++){
        end = job[end_index].end_time;  //비교할 end_time
        start = job[i].start_time;  //뒤에 나오는 activity의 start_time

        if(end <= start){   //다음 activity의 start_time이 이전 activity의 end_time보다 크거나 같다면 max+1
            end_index = i;
            max +=1;
        }
    }

    return max;

}

//Dynamic Programing알고리즘 함수
int dp(Job *job, int jobNumber){
    int dp_arr[jobNumber] = {};  //Mutually compatible activites의 개수를 저장할 배열
    fill(dp_arr, dp_arr+jobNumber, 0);  //초기 배열값 모두 0으로 설정 (쓰래기값 방지)
    sort(job, job+jobNumber, cmp_dp);  //start_time기준 오름차순으로 정렬
    

    for(int i=0; i<jobNumber; i++){ //각각의 job을 기준으로 Mutually compatilbe activites 개수를 dp배열에 저장, 따라서 계산에 필요한 subset이 이미 존재한다면 배열에서 바로 불러와서 계산 가능
        for(int j=0; j<i; j++){
            if(job[j].end_time <= job[i].start_time && dp_arr[i] < dp_arr[j]){
                dp_arr[i] = dp_arr[j];
            }
        }
        dp_arr[i]++;    //다음 주소로 이동
    }

    return *max_element(dp_arr, dp_arr+jobNumber);  //각 activity를 기준으로 추출한 Mutuzally compatible activites의 개수가 가장 큰 값 반환

}


int main(){

    int jobNumber, start, end, gd_result, dp_result;
    int testcase[4] = {10, 100, 1000, 10000};   //테스트할 job개수 저장
    int count = 0;

    srand(seed);    //random number을 생성하기 위한 seed할당(408)

    cout << "-----------------------------------------------------------------------------\n";
    cout << right << setw(15) << "Number" << " | " << "\tExecution time in microseconds\n";
    cout << right << setw(15) << "of jobs" << " | " << setw(15) << "Greedy" << setw(15) << " | "<< setw(25) << "Dynamic Programing\n";
    cout << "-----------------------------------------------------------------------------\n";

    // Job개수 10, 100, 1,000, 10,000경우 실행시간 출력 (100,000안 경우는 마지막에 따로 greedy에서만 출력)
    for(int i=0; i<4; i++){
        jobNumber = testcase[i];

        struct Job gd_job[jobNumber];   //greedy에 사용할 Job구조체 배열
        struct Job dp_job[jobNumber];   //Dynamic Programing에 사용할 Job구조체 배열

        while(count < jobNumber){   //random number생성 후 각 job생성
            start = rand()%jobNumber*10+1;
            end = rand()%jobNumber*10+1;

            if(start <= end && start != end){
                gd_job[count].start_time = start;
                dp_job[count].start_time = start;
                gd_job[count].end_time = end;
                dp_job[count].end_time = end;
                count ++;
            }
        }
        //시간 측정 + 출력(micro단위)
        chrono::system_clock::time_point startTime = chrono::system_clock::now();
        greedy(gd_job, jobNumber);
        chrono::system_clock::time_point endTime = chrono::system_clock::now();
        chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

        chrono::system_clock::time_point dp_startTime = chrono::system_clock::now();
        dp(gd_job, jobNumber);
        chrono::system_clock::time_point dp_endTime = chrono::system_clock::now();
        chrono::microseconds dp_micro = chrono::duration_cast<chrono::microseconds>(dp_endTime - dp_startTime);

        cout << right << setw(15) << jobNumber << " | " << internal << setw(15) << micro.count() << right <<setw(15) << " | " << internal << setw(15) << dp_micro.count() << "\n";

        count = 0;
    }

    jobNumber = 100000; // job의 개수가 100,000인 경우
    struct Job gd_job[jobNumber];
    while(count < jobNumber){
        start = rand()%jobNumber*10+1;
        end = rand()%jobNumber*10+1;

        if(start <= end && start != end){
            gd_job[count].start_time = start;
            gd_job[count].end_time = end;
            count ++;
        }
    }
    chrono::system_clock::time_point startTime = chrono::system_clock::now();
    greedy(gd_job, jobNumber);
    chrono::system_clock::time_point endTime = chrono::system_clock::now();
    chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(endTime - startTime);
    cout << right << setw(15) << jobNumber << " | " << internal << setw(15) << micro.count() << right <<setw(15) << " | " << internal << setw(15) << " X " << "\n"; //Greedy만 따로 출력, DP는 X

    cout << "-----------------------------------------------------------------------------\n";

    

    return 0;
}