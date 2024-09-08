#ifndef _BITCOINEXCHANGE_HPP__
# define _BITCOINEXCHANGE_HPP__

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
    public:
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);

        BitcoinExchange(const std::string& filename);
    
    private:
        BitcoinExchange(void);
        const std::string filename;

        void fileOpen(void);
        void validateFormat(const std::string& line);
};

#endif


// 파일 이름 받아서 파일 오픈 검사
// 데이터베이스 파싱, map에 환율 저장
// "날짜 | 값" 형식이 맞는지 검사, "연도-월-일" 형식이 맞는지 검사, 0~1000 의 양의 정수 혹은 실수인지 검사 --> 한줄씩 검사
// 검사 통과하면 가장 가까운 하한 날짜를 찾아 환전 수행
// 검사 실패하면 에러 처리