#include <iostream>
#include <vector>
using namespace std;
/*  Python AC代码
 *  class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        negative_feedback=set(negative_feedback)
        positive_feedback=set(positive_feedback)
        recordFirst = PriorityQueue()

        for index, v in enumerate(report):
            totalScore = 0
            tempStudentReport = v.split(" ")
            for i in tempStudentReport:
                if i in positive_feedback:
                    totalScore += 3
                elif i in negative_feedback:
                    totalScore -= 1
            recordFirst.put(item=(-totalScore, student_id[index]))

        return [recordFirst.get()[1] for i in range(k)]
 */

class Solution {    // TODO 2023/10/11 Python已过 缺少C++写法
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

    }
};

int main() {
    Solution solution;
    vector<string>positive_feedback = {"smart","brilliant","studious"};
    vector<string>negative_feedback = {"not"};
    vector<string>report = {"this student is not studious","the student is smart"};
    vector<int>student_id = {1,2};
    int k = 2;
    for (auto i:solution.topStudents(positive_feedback, negative_feedback, report,student_id,k)) {
        cout << i << " ";
    }
    return 0;
}
