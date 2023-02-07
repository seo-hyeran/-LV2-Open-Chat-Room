// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include<algorithm>
#include <map>
#include<sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> tmp;
    map<string, string> m; //key(uid)와 value(name)분리를 위해 map 함수 이용 
    for (int i = 0; i < record.size(); i++) {
        vector<string> str;
        string word;
        
        stringstream ss(record[i]); //문자열 분류



        while (getline(ss,word,' ')) { //공백(' ') 분리
            str.push_back(word); //각 문자 배열에 저장
            
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
