#include <iostream>
#include <fstream>

#include <string>
using namespace std;

/* ================= STUDENT LOGIN ================= */
bool checkStudentLogin(string id, string password) 
{
    ifstream fin;
    string line;
    string line1;
    string line2;


    fin.open("Students.txt",ios::in);
    while(getline(fin,line,',')){
        getline(fin,line1,',');
        getline(fin,line2);
        if(line==id && line2==password)
        {
            cout<<"=======Welcome"<<" "<<line1<<"========"<<endl;
            return true;

        }


    }
    fin.close();
    return false;

   
   

   
}

/* ================= QUIZ ================= */
void takeQuiz() 
{
    ifstream fin;
    fin.open(("Questions.txt"));
    if (!fin) {
        cout << "Questions.txt file not found!\n";
        return;
    }

    string question;
    string options;
    string Answer;
    string User_option;
    int count =0;
    int score=0;
    
    while( count<5 && getline(fin,question))
    {
        cout<<"\n"<<question<<endl;
        getline(fin,options,',');
        cout<<options<<endl;
        cout<<"Enter your option:";
        cin>>User_option;
        
        for(int i =0; i<User_option.length();i++)
        {
            if(User_option[i]>='a'&& User_option[i]<='z'){
            User_option[i]=User_option[i]-32;
            }

        }
        getline(fin,Answer);
        
        
        if(User_option ==Answer)
        {
            cout<<"Well Done!"<<endl;
            cout<<"Your answer is correct."<<endl;
            score++;
        }
        else
        {
            cout<<"Wrong!"<<endl;
            cout<<"Correct Answer is:"<<Answer<<endl;

        }
        count++;


    }
    cout<<"Your score is:"<<score<<endl;
   
    fin.close();

}

/* ================= ADMIN VIEW ================= */

void viewQuestions() {
    ifstream fin("Questions.txt");
    string line;

    if (!fin) 
    {
        cout << "Questions.txt not found!\n";
        return;
    }

    cout << "\n--- ALL QUESTIONS ---\n";
    while (getline(fin, line)) 
    {
        cout << line << endl;
    }

    fin.close();
}

/* ================= ADMIN ADD QUESTION ================= */
void addQuestion() 
{
    ofstream fout("Questions.csv", ios::app);
    if (!fout)
    {
        cout << "Error opening Questions.csv\n";
        return;
    }

    string qno, question, A, B, C, D, correct;
    cin.ignore();

    cout << "Enter Question No (e.g Q51): ";
    getline(cin, qno);
    cout << "Question: ";
    getline(cin, question);
    cout << "Option A: ";
    getline(cin, A);
    cout << "Option B: ";
    getline(cin, B);
    cout << "Option C: ";
    getline(cin, C);
    cout << "Option D: ";
    getline(cin, D);
    cout << "Correct Option (A/B/C/D): ";
    cin >> correct;

    fout << qno << "," << question << "," << A << "," << B << "," 
         << C << "," << D << "," << correct << "\n";

    fout.close();
    cout << "Question Added Successfully!\n";
}

/* ================= ADMIN PANEL ================= */
void adminPanel()
{
    int choice;
    do {
        cout << "\n--- ADMIN PANEL ---\n";
        cout << "1. View Questions\n";
        cout << "2. Add Question\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) viewQuestions();
        else if (choice == 2) addQuestion();
        else if (choice == 3) cout << "Admin Logged Out\n";
        else cout << "Invalid Choice!\n";

    }
        while (choice != 3);
}

/* ================= MAIN ================= */
int main() 
{
    int choice;
    cout << "===== QUIZ MANAGEMENT SYSTEM =====\n";

    do 
    {
        cout << "\n1. Admin\n2. Student\n3. Exit\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            string pass;
            cout << "Enter Admin Password: ";
            cin >> pass;
            if (pass == "admin123")
                adminPanel();
            else
                cout << "Wrong Admin Password!\n";
        }
        else if (choice == 2) 
        {
            string id, pass;
            cout << "Student ID: ";
            cin >> id;
            cout << "Password: ";
            cin >> pass;

            if (checkStudentLogin(id, pass))
                takeQuiz();
            else
                cout << "Invalid ID or Password!\n";
        }
        else if (choice == 3)
        {
            cout << "Program Exit\n";
        }
        else 
        {
            cout << "Invalid Option!\n";
        }

    }
        while (choice != 3);

    return 0;

}
