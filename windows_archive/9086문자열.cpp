#include <iostream>
#include <string>

#define 정수 int
#define 메인 main
#define 입력 std::cin
#define 출력 std::cout
#define 반복(횟수) for (int i = 0; i < 횟수; i++)
#define 문자열 std::string
#define 상수 const
#define 무 void
#define 참조 &
#define 길이(_문자열) _문자열.length()
#define 개행 '\n'
#define 반환 return

무 문자열의_첫_글자와_마지막_글자_연속하여_출력하기(상수 문자열 참조 입력_문자열)
{
    출력 << 입력_문자열[0] << 입력_문자열[길이(입력_문자열) - 1] << 개행;
}

정수 메인()
{
    정수 테스트케이스_개수;
    입력 >> 테스트케이스_개수;
    반복(테스트케이스_개수)
    {
        문자열 입력_문자열;
        입력 >> 입력_문자열;
        문자열의_첫_글자와_마지막_글자_연속하여_출력하기(입력_문자열);
    }
    반환 0;
}
