#include <iostream>
#include "Homework01.h"

void Homework01_Run()
{
    while (true)
    {
        printf("\"연 월 일\"을 입력하세요 (입력예시: 2026 5 29) (종료하려면 -1 입력)\n");
        printf(": ");
        std::string DateString{};
        std::getline(std::cin, DateString);

        if (DateString == "-1")
        {
            break;
        }

        if (!IsValidInput(DateString))
        {
            printf("[ERROR] 입력 형태가 잘못됐습니다!!\n");
            continue;
        }

        size_t FirstSpaceIndex = DateString.find(' ');
        size_t SecondSpaceIndex = DateString.find(' ', FirstSpaceIndex + 1);

        int Year = std::stoi(DateString.substr(0, FirstSpaceIndex));
        int Month = std::stoi(DateString.substr(FirstSpaceIndex + 1, SecondSpaceIndex));
        int Day = std::stoi(DateString.substr(SecondSpaceIndex));
        int ModOfTotalDays = 0;

        // Year
        for (int i = 1; i < Year; i++)
        {
            ModOfTotalDays +=
                IsLeapYear(i)
                ? ModOfTotalDaysAtMonthOfLeapYear[12]
                : ModOfTotalDaysAtMonth[12];
        }

        // Month
        ModOfTotalDays += IsLeapYear(Year) ? ModOfTotalDaysAtMonthOfLeapYear[Month - 1] : ModOfTotalDaysAtMonth[Month - 1];

        // Day
        ModOfTotalDays += Day - 1;

        ModOfTotalDays %= 7;

        std::string DayString = EDay2String(static_cast<EDay>(ModOfTotalDays));

        printf("total : %d\n", ModOfTotalDays);
        printf("[%d년 %d월 %d일]은 [%s]입니다.\n\n", Year, Month, Day, DayString.c_str());
    }

    printf("\n[Homework01 프로그램이 종료되었습니다.]\n");
}

bool IsValidInput(const std::string& Input)
{
    // - 모든 입력은 글자, 0, 음수가 될 수 없다
    // - 스페이스는 2번까지만 가능하다
    // - 연도 1 ~ int의 최대값
    // - 월은 1 ~ 12
    // - 일은 기본적으로 1 ~ 31이지만, 월에 따라 다르다

    // 글자 확인
    int SpaceCount = 0;
    size_t InputLength = Input.length();
    for (size_t i = 0; i < InputLength; i++)
    {
        if (Input[i] == ' ')
        {
            SpaceCount++;
        }
        else if (!('0' <= Input[i] && Input[i] <= '9'))
        {
            return false;
        }
    }

    // 스페이스 개수 확인
    if (SpaceCount != 2)
    {
        return false;
    }

    // 년, 월, 일 유효성 확인
    size_t FirstSpaceIndex = Input.find(' ');
    size_t SecondSpaceIndex = Input.find(' ', FirstSpaceIndex + 1);
    std::string Year = Input.substr(0, FirstSpaceIndex);
    std::string Month = Input.substr(FirstSpaceIndex + 1, SecondSpaceIndex - FirstSpaceIndex - 1);
    std::string Day = Input.substr(SecondSpaceIndex + 1);

    if (!CanStoUnsignedI(Year))
    {
        return false;
    }

    if (!CanStoUnsignedI(Month) || !(0 < std::stoi(Month) || std::stoi(Month) < 13))
    {
        return false;
    }

    if (!CanStoUnsignedI(Day) || !(0 < std::stoi(Day) || std::stoi(Day) < DaysOfMonth[std::stoi(Month)] + 1))
    {
        return false;
    }

    return true;
}

bool CanStoUnsignedI(const std::string& String)
{
    size_t StringLength = String.length();
    for (size_t i = 0; i < StringLength; i++)
    {
        if (!('0' <= String[i] && String[i] <= '9'))
        {
            return false;
        }
    }

    return String.length() < 11
        && std::stoi(String.substr(0, 9)) <= INT32_MAX / 10
        && std::stoi(String) > 0;
}

bool IsLeapYear(int Year)
{
    // 4의 배수는 윤년, 그러나 동시에 100의 배수면 윤년이 아님 / 400의 배수는 윤년
    return ((Year % 4 == 0) && (Year % 100 != 0))
        || (Year % 400 == 0);
}

std::string EDay2String(EDay Day)
{
    std::string DayString{};

    switch (Day)
    {
        case Mon:
            DayString = "월요일";
            break;
        case Tue:
            DayString = "화요일";
            break;
        case Wed:
            DayString = "수요일";
            break;
        case Thu:
            DayString = "목요일";
            break;
        case Fri:
            DayString = "금요일";
            break;
        case Sat:
            DayString = "토요일";
            break;
        case Sun:
            DayString = "일요일";
            break;
        default:
            break;
    }

    return DayString;
}
