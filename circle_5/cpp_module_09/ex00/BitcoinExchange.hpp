#ifndef _BITCOINEXCHANGE_HPP__
# define _BITCOINEXCHANGE_HPP__

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>

class BitcoinExchange
{
    public:
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& obj);

        BitcoinExchange(std::string filename);
    
    class FileOpenException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class NotNumberException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class NotInvalidException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class InputFileFormatException : public std::exception
    {
        public:
            const char* what() const throw();
    };

        void calculateBitcoin(void);
    private:
        BitcoinExchange(void);
        bool isLeapYear(int year);
        int daysInMonth(int month, int year);
        bool isValidDate(const std::string &dateStr);
        std::map<std::string, std::string> parseDataFile(void);
        void parseInputFile(std::map<std::string, std::string>& btcPrice);
        bool string2double(std::string value, double& price);
        std::string trim(const std::string& str);

        const std::string filename;
};

#endif


// 파일 이름 받아서 파일 오픈 검사
// 데이터베이스 파싱, map에 환율 저장
// "날짜 | 값" 형식이 맞는지 검사, "연도-월-일" 형식이 맞는지 검사, 0~1000 의 양의 정수 혹은 실수인지 검사 --> 한줄씩 검사
// 검사 통과하면 가장 가까운 하한 날짜를 찾아 환전 수행
// 검사 실패하면 에러 처리