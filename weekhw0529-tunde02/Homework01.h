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

/// <summary>
/// 요일을 구분하기 위한 Enum
/// </summary>
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

/// <summary>
/// 평년일 때 각 월의 총 일수를 저장한 배열
/// 입력값을 검사할 때 사용합니다
/// ex) 2026 5 32 -> 올바르지 않은 입력
/// </summary>
const int DaysOfMonth[13] =
{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/// <summary>
/// 윤년일 때 각 월의 총 일수를 저장한 배열
/// 입력값을 검사할 때 사용합니다
/// ex) 2000 2 29 -> 올바른 입력
/// </summary>
const int DaysOfMonthOfLeapYear[13] =
{
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

//const int TotalDaysAtMonth[13] =
//{
//    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
//};

//const int TotalDaysAtMonthOfLeapYear[13] =
//{
//    0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
//};

/// <summary>
/// 평년일 때 각 달까지의 총 일수를 7로 나눈 나머지를 저장한 배열
/// ex) ModOfTotalDaysAtMonth[3] : 3월까지의 총 일수(31 + 28 + 31) % 7 = 6
/// </summary>
const int ModOfTotalDaysAtMonth[13] =
{
    0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5, 1
};

/// <summary>
/// 윤년일 때 각 달까지의 총 일수를 7로 나눈 나머지를 저장한 배열
/// ex) ModOfTotalDaysAtMonth[3] : 3월까지의 총 일수(31 + 29 + 31) % 7 = 0
/// </summary>
const int ModOfTotalDaysAtMonthOfLeapYear[13] =
{
    0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6, 2
};

/// <summary>
/// 프로그램 실행 함수
/// </summary>
void Homework01_Run();

/// <summary>
/// 사용자의 입력을 다음의 규칙에 따라 검사한 후 올바른 형태인지 아닌지 여부를 반환하는 함수
/// 1. 입력의 모든 문자는 숫자, 공백으로만 이루어져야 한다
/// 2. 공백은 2개 존재해야만 한다
/// 3. 연도는 1 ~ INT_MAX
/// 4. 월은 1 ~ 12
/// 5. 일은 월이 무엇인지에 따라 1 ~ 28 일수도, 1 ~ 31 일수도 있다
/// </summary>
/// <param name="Input">사용자의 입력 문자열</param>
/// <returns>입력 문자열이 올바르면 true, 올바르지 않으면 false</returns>
bool IsValidInput(const std::string& Input);

/// <summary>
/// 문자열을 양의 정수 형태로 변환할 수 있는지 여부를 반환하는 함수
/// </summary>
/// <param name="String">변환할 문자열</param>
/// <returns>변환할 수 있으면 true, 변환할 수 없으면 false</returns>
bool CanStoUnsignedI(const std::string& String);

/// <summary>
/// 연도가 윤년인지 여부를 반환하는 함수
/// </summary>
/// <param name="Year">연도</param>
/// <returns>윤년이라면 true, 평년이라면 false</returns>
bool IsLeapYear(int Year);

/// <summary>
/// EDay 형태를 전달받아 알맞은 요일 문자열로 반환하는 함수
/// </summary>
/// <param name="Day">EDay enum</param>
/// <returns>EDay에 따라 변환된 요일 문자열</returns>
std::string EDay2String(EDay Day);
