// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<tuple>
#include<regex>
#include <map>
#include<sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> tmp;
    map<string, string> m;
    for (int i = 0; i < record.size(); i++) {
        vector<string> str;
        string token;
        
        stringstream ss(record[i]);



        while (getline(ss,token,' ')) {
            str.push_back(token);
            
        }

        
        if (str[0] == "Enter") {
            tmp.push_back("님이 들어왔습니다.");
            answer.push_back(str[1]);
            m[str[1]] = str[2];
        }
        else if (str[0] == "Leave") {
            tmp.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
            
        }
        else {
            m[str[1]] = str[2];
        }
    }
    for (int i = 0; i < answer.size(); i++) {
        answer[i] = m[answer[i]] + tmp[i];
    }
    
    return answer;
}
int main()
{ 
    vector<string> record ={"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
    solution(record);

}
