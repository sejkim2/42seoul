#include <iostream>
#include <vector>
#include <algorithm>

// 야곱 수열을 미리 계산하는 함수
std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal(n + 1);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;

    for (int i = 2; i <= n; ++i) {
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2]; // 점화식
    }

    return jacobsthal;
}

// 이진 삽입 함수
void binaryInsertion(std::vector<int>& d, int value) {
    std::vector<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}

// 재귀적 MergeInsertion 알고리즘
std::vector<int> mergeInsertion(std::vector<int>& d, const std::vector<int>& jacobsthal) {
    int n = d.size();
    if (n <= 1) return d; // 기저 사례: 배열에 원소가 하나면 그대로 반환

    std::vector<int> mainchain, pending;

    // 쌍으로 비교하여 mainchain과 pending에 저장
    for (size_t i = 0; i < d.size(); i += 2) {
        if (i + 1 < d.size()) {
            if (d[i] > d[i + 1]) {
                mainchain.push_back(d[i]);
                pending.push_back(d[i + 1]);
            } else {
                mainchain.push_back(d[i + 1]);
                pending.push_back(d[i]);
            }
        } else {
            pending.push_back(d[i]);
        }
    }

    // 재귀적 정렬
    mainchain = mergeInsertion(mainchain, jacobsthal);

    // 결과 배열 생성
    std::vector<int> sorted_array;
    sorted_array.insert(sorted_array.end(), mainchain.begin(), mainchain.end());

    int previousJacobsthal = jacobsthal[2];
    binaryInsertion(sorted_array, pending[previousJacobsthal - 1]);

    int i = 3;
    while (true)
    {
        int flag = true;
        int curentJacobsthal = jacobsthal[i];
        for(int j = curentJacobsthal; j > previousJacobsthal; j--)
        {
            if (j - 1 < pending.size())
                binaryInsertion(sorted_array, pending[j - 1]);
            else
                flag = false;
        }
        previousJacobsthal = curentJacobsthal;
        if (!flag)
            break ;
        i++;
    }

    // 야곱 수열을 따라 pending의 원소를 삽입
    // for (size_t k = 2; k < jacobsthal.size(); ++k) {
    //     int index = jacobsthal[k];
    //     if (index < pending.size()) {
    //         int value = pending[index];
    //         binaryInsertion(sorted_array, value);
    //     }
    // }

    // pending에 남아 있는 원소를 삽입
    // for (size_t i = 0; i < pending.size(); ++i) {
    //     if (std::find(sorted_array.begin(), sorted_array.end(), pending[i]) == sorted_array.end()) {
    //         binaryInsertion(sorted_array, pending[i]);
    //     }
    // }

    return sorted_array; // 최종 정렬된 배열 반환
}

int main(int argc, char**argv) {
    // int d_array[] = {34, 7, 32, 5, 62, 45, 8, 1, 30, 40, 22, 134}; // 테스트 데이터
    int d_array[] = {3}; // 테스트 데이터
    int n = sizeof(d_array) / sizeof(d_array[0]);
    std::vector<int> d(d_array, d_array + n);

    // n 크기의 야곱 수열 생성
    if (n < 3)
        n = 3;
    std::vector<int> jacobsthal = generateJacobsthalSequence(n);

    // MergeInsertion 알고리즘을 이용해 배열 정렬
    std::vector<int> sorted = mergeInsertion(d, jacobsthal);

    // 정렬된 배열 출력
    std::cout << "정렬된 배열: ";
    for (size_t i = 0; i < sorted.size(); ++i) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
