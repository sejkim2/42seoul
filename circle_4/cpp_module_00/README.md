#ex01
*입출력 함수 2개
1. cin
-> 공백 전까지
2. getline
-> 델리미터 지정이 없다면 default : 엔터 까지 입력 받음

*cin.fail이 발생하는 경우
1. fd가 닫혀있을 때
2. 파일의 끝에 도달했을 때
3. 잘못된 데이터 형식을 입력했을 때

*cin.fail이 발생했을 때 적절한 처리방법
1. 오류 메시지 출력
2. 오류 플래그 초기화 -> cin.clear()
3. 잘못된 입력으로 인해 비워지지 않은 버퍼 비워주기 -> cin.ignore(buf_size, delim)
delim에 도착할 때까지 버퍼를 지워준다.
만약 버퍼를 비우지 않는다면 다음 입력 시 이전 잘못된 버퍼를 가져오므로 원하는 결과를 얻을 수 없음
₩₩₩
int num;

    std::cout << "정수를 입력하세요: ";
    std::cin >> num;

    if (std::cin.fail())
        std::cout << "잘못된 입력 형식입니다." << std::endl;

    std::cin >> num;
    std::cout << "입력된 정수: " << num << std::endl;
₩₩₩

*find_first_not_of(string)
-> string 중 첫번째로 나오는 문자의 위치 반환

*setw(size)
-> size만큼 너비 지정하여 출력(오른쪽 자동 정렬)

