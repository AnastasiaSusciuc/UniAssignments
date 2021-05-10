#include <iostream>
#include <fstream>
#include <cstring>
#define Nmax 100005

using namespace std;

int t;
std::string s;

bool choose_piece(unsigned int left, unsigned int right, char colour)
// 0 if left, 1 for right
{
    unsigned int c_left = left, c_right = right;
    if (colour == 'I')
    {
        while (c_left < right-1 && (s[c_left] != s[c_left+1] || s[c_left] == 'O'))
            c_left++;

        while (c_right > left+1 && (s[c_right] != s[c_right-1] || s[c_right] == 'O'))
            c_right--;

        if (c_left - left <= right - c_right)
            return false;
        else return true;
    }
    else
    {
        while (c_left < right && (s[c_left] != s[c_left+1] || s[c_left] == 'I'))
            c_left++;

        while (c_right > left+1 && (s[c_right] != s[c_right-1] || s[c_right] == 'I'))
            c_right--;

        if (c_left - left <= right - c_right)
            return false;
        else return true;
    }
}

int play(int left, int right, char colour)
// izabella negative, olga positive;
{
    if (left > right)
    {
        if (colour == 'O')
            return -1;
        else return 1;
    }
//    cout << left << " " << right << '\n';

    if (colour == 'I')
    {

        if (s[left] == s[right] && s[left] == 'O')
        {
            // cout << "O " << right-left + 2 << '\n';
            return (right-left+2);
        }
        else if (s[left] == 'O')
        {
            return play(left, right-1, 'O');
        }
        else if (s[right] == 'O')
        {
            return play(left+1, right, 'O');
        }
        else
        {
            int score1 = play(left, right-1, 'O');
            int score2 = play(left+1, right, 'O');
//            std::cout << "IZABELA " << score1 << " " << score2 << '\n';
            return min(score1, score2);
        }
    }
    else
    {
        if (s[left] == s[right] && s[left] == 'I')
        {
            return (-1)*(right-left+2);
        }
        else if (s[left] == 'I')
        {
            return play(left, right-1, 'I');
        }
        else if (s[right] == 'I')
        {
            return play(left+1, right, 'I');
        }
        else
        {
            int score1 = play(left, right-1, 'I');
            int score2 = play(left+1, right, 'I');
//            std::cout << "OLGA " << score1 << " " << score2 << '\n';
            return max(score1, score2);
        }
    }
}

int main() {

    cin >> t;

    for (int l = 1; l <= t; l++)
    {

        cout << "Case #" << l << ": ";
        cin >> s;

        int left = 0, right = s.size()-1;

        int score = play(left, right, 'I');
        if (score < 0)
            cout << "I " << score*(-1) << '\n';
        else
            cout << "O " << score << '\n';

//        if (s[left] == s[right] && s[left] == 'O')
//        {
//            cout << "O " << right-left + 2 << '\n';
//            continue;
//        }
//
//
//        int round = 0; // izabella - 0, olga - 1
//        while (left <= right)
//        {
//            if (round == 0) // izabella's turn
//            {
//                if (s[left] == s[right] && s[left] == 'O')
//                {
//                    cout << "O " << right-left + 2 << '\n';
//                    break;
//                }
//                else if (s[left] == 'O')
//                    right--;
//                else if (s[right] == 'O')
//                    left++;
//                else
//                {
//                    bool res = choose_piece(left, right, 'I');
//                    if (res == 0)
//                        left++;
//                    else right--;
//                }
//            }
//            else // olga's turn
//            {
//                if (s[left] == s[right] && s[left] == 'I')
//                {
//                    cout << "I " << right-left + 2 << '\n';
//                    break;
//                }
//                else if (s[left] == 'I')
//                    right--;
//                else if (s[right] == 'I')
//                    left++;
//                else
//                {
//                    bool res = choose_piece(left, right, 'O');
//                    if (res == 0)
//                        left++;
//                    else right--;
//                }
//            }
//
//            round = 1-round;
//        }
//        if (left > right)
//        {
//            if (round == 1)
//                cout << "I " << 1 << '\n';
//            else
//                cout << "O " << 1 << '\n';
//        }
    }
    return 0;
}
