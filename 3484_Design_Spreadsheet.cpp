//#3484 Design Spreadsheet  - https://leetcode.com/problems/design-spreadsheet/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> cells;
public:
    Spreadsheet(int rows) {
        cells.resize(26, vector<int>(rows + 1));
    }

    void setCell(string cell, int value) {
        cells[cell[0] - 'A'][stoi(cell.substr(1))] = value;
    }

    void resetCell(string cell) {
        cells[cell[0] - 'A'][stoi(cell.substr(1))] = 0;
    }

    int getValue(string formula) {
        string left, right;
        int pos = 1;
        while(formula[pos] != '+')
            left += formula[pos++];
        pos++;
        while(pos != (int)formula.size())
            right += formula[pos++];
        int result = 0;
        if(left[0] >= 'A' && left[0] <= 'Z')
            result = cells[left[0] - 'A'][stoi(left.substr(1))];
        else
            result = stoi(left);
        if(right[0] >= 'A' && right[0] <= 'Z')
            result += cells[right[0] - 'A'][stoi(right.substr(1))];
        else
            result += stoi(right);
        return result;
    }
};


int main()
{
    int givenRows = 3;
    Spreadsheet solution(givenRows);
    int expectedAnswer = 12;
    string givenFormula = "=5+7";
    assert(solution.getValue(givenFormula) == expectedAnswer);

    string givenCell = "A1";
    int givenValue = 10;
    solution.setCell(givenCell, givenValue);
    givenCell = "B2";
    givenValue = 15;
    solution.setCell(givenCell, givenValue);
    givenFormula = "=A1+B2";
    expectedAnswer = 25;
    assert(solution.getValue(givenFormula) == expectedAnswer);

    return 0;
}
