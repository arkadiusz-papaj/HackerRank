#include <numeric>
class Student
{
    public:
        void input();
        int calculateTotalScore();
    private:
        vector<int> scores;
};
void Student::input()
{
    int score;
    for (int i = 0; i < 5; i++)
    {
        cin >> score;
        scores.push_back(score);
    }
};

int Student::calculateTotalScore()
{
    return std::accumulate(scores.begin(), scores.end(), 0);
};