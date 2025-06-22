/*
3. Write a program to create a student personal class and student grade_calculation class.
    • Student personal class must get student rollno/Id, fullname, course and college details.
    • Student grade_calculation class must get paper_name, score from the user.
    • Your application must allow the user to provide three different paper name and score.
    • Implement single inheritance to generate the mark sheet as like,
            John Peter’s Mark Sheet
        Name : John Peter
        Rollno : 23478343
        Course : BCS
        Paper Score Grade
        ***************************************
        Ux design 56 Pass
        Web Application 56 Pass
        Mobile Application 32
        Overall grade : Fail
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Student {
private:
    int id;
    string name;
    string college;
    string course;

public:
    Student( int id, const string& name, const string& course, const string& college) : id(id), name(name), course(course) , college(college) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getCollege() const { return college; }
    string getCourse() const { return course; }

    //Modifiers. Note: I assume that ID is not changable once set by initializer. 
    void setName(const string& name) { this->name = name; }  //This is a pointer not a object.
    void setCollege(const string &college) { this->college = college; }

    string toString() const {
        std::ostringstream oss;
        oss << " Name: '" << name 
            << "\n Rollno: " << id 
            << "\n College: '" << college 
            << "'\n Course: '" << course ;
        
        return oss.str();
    }
};

// Grade calculator (single inheritance)
class StuGradeCalculator : public Student 
{
    private:
        struct Paper 
        {
            string name;
            double score;
    
            // Calculate the grade.
            string getGrade() const {
                if (score >= 50) return "Pass";
                return "Fail";
            }
        };
    
        vector<Paper> papers;
    
    public:
        
    StuGradeCalculator(int rollNo, const string& fullName, const string& course, const string& college)
            : Student(rollNo, fullName, course, college) {}
    
        // Add paper and its score
        void addPaperScore(const string& name, double score) {
            papers.push_back({name, score});
        }
    
        // Get papers and scores from user. 
        void inputPaperScoresFromUser() {
            string name;
            double score;
    
            for (int i = 0; i < 3; ++i) {
                cout << "Please enter the NO. " << i + 1 << " paper name: ";
                getline(cin >> ws, name);
    
                std::cout << "Please enter the score of paper " << name << ": ";
                while (!(cin >> score)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid score, please enter again: ";
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 
    
                addPaperScore(name, score);
            }
        }
    
        // Calculate the average score, whichi is to be used in overall grade calculation.
        double calculateAverage() const {
            if (papers.empty()) return 0.0;
            double sum = 0.0;
            for (const auto& paper : papers) {
                sum += paper.score;
            }
            return sum / papers.size();
        }
    
        // Get the overall grade
        string getOverallGrade() const {
            if (calculateAverage() >= 50) return "Pass";
            return "Fail";
        }
    
        // Print the mark sheet
        void printMarkSheet() const {
            toString(); // 调用基类的信息显示函数
    
            cout << "Paper\tscore\tgrade" << endl;
            cout << "*************************************" << endl;
    
            for (const auto& paper : papers) {
                cout << left << setw(15) << paper.name 
                          << setw(8) << paper.score 
                          << paper.getGrade() << endl;
            }
    
            std::cout << "Over all grade : " << getOverallGrade() << std::endl;
        }
};

int main() {
    int id;
    string fullname, college, course;

    cout << "Please enter student rollNumber or id: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer

    cout << "Please enter student fullname: ";
    getline(cin, fullname);

    cout << "Please enter student college: ";
    getline(cin,college);

    cout << "Please enter student course: ";
    getline(cin, course);

    StuGradeCalculator stuCal(id, fullname, course, college);
    stuCal.inputPaperScoresFromUser();

    cout << "\n\n";
    cout << stuCal.toString() << endl;
    stuCal.printMarkSheet();

    return 0;
}
