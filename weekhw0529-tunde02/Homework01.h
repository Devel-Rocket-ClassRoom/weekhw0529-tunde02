#pragma once

#include <string>

/*
1. 요일 구하기
   - 1년 1월 1일(월요일)을 기준으로 입력한 날짜까지 며칠이 지났는지 계산한 후, 7로 나눈 나머지로 요일을 구하기.
   - 윤년도 올바르게 처리할 것
     - 4의 배수는 윤년, 그러나 동시에 100의 배수면 윤년이 아님 / 400의 배수는 윤년
   - 입력받은 연, 월, 일을 기준으로 요일을 출력.
     - 예시 입력 : 2026 5 29 → 결과 : 금요일
   - Homework01_Run(); 함수로 실행 가능해야 함.
*/

enum EDay
{
    Mon = 0,
    Tue = 1,
    Wed = 2,
    Thu = 3,
    Fri = 4,
    Sat = 5,
    Sun = 6
};

const int DaysOfMonth[13] =
{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
//const int TotalDaysAtMonth[13] =
//{
//    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
//};
//const int TotalDaysAtMonthOfLeapYear[13] =
//{
//    0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
//};
const int ModOfTotalDaysAtMonth[13] =
{
    0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5, 1
};
const int ModOfTotalDaysAtMonthOfLeapYear[13] =
{
    0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6, 2
};

void Homework01_Run();
bool IsValidInput(const std::string& Input);
bool CanStoUnsignedI(const std::string& String);
bool IsLeapYear(int Year);
std::string EDay2String(EDay Day);
