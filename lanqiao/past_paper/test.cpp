#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Student {
  int enter_time;    // s_i
  int question_time; // q_i
  int exit_time;     // e_i
  
  // 计算总处理时间(不包括离开时间，因为离开时下一个学生可以进入)
  int process_time() const {
      return enter_time+question_time;
  }
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students(n);
    for (int i=0; i < n; i++) {
        cin >> students[i].enter_time >> students[i].question_time >> students[i].exit_time;
    }
    
    // 按总处理时间(s_i + q_i)排序
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
      return a.process_time() < b.process_time();
    });
    
    ll current_time=0;
    ll total_message_time=0;
    
    for (int i=0; i < n; i++) {
        // 学生进入办公室
        current_time+=students[i].enter_time;
        
        // 学生问问题老师解答
        current_time+=students[i].question_time;
        
        // 学生在这个时刻发消息
        total_message_time+=current_time;
        
        // 学生离开办公室
        current_time+=students[i].exit_time;
    }
    
    cout << total_message_time << endl;
    
    return 0;
}