#ifndef _BITCOINEXCHANGE_HPP__
# define _BITCOINEXCHANGE_HPP__

# include <iostream>
# include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);

        BitcoinExchange(std::string filename);

};

#endif


//1. 파일 이름 받아서 파일 오픈 검사
//2. "날짜 | 값" 형식이 맞는지 검사, "연도-월-일" 형식이 맞는지 검사, 0~1000 의 양의 정수 혹은 실수인지 검사 --> 한줄씩 검사
//3. 검사 통과하면 가장 가까운 하한 날짜를 찾아 환전 수행
//4. 검사 실패하면 에러 처리