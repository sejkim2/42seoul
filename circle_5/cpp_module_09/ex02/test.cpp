#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// 야곱 수열을 미리 계산하는 함수
std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal(n);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;

    for (int i = 2; i < n; ++i) {
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

    // mainchain과 pendingchain으로 나누기
    std::vector<int> mainchain((n + 1) / 2), pendingchain(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        mainchain[i] = std::max(d[i], d[i + n / 2]); // 큰 값
        pendingchain[i] = std::min(d[i], d[i + n / 2]); // 작은 값
    }
    if (n % 2 == 1) {
        mainchain[n / 2] = d[n - 1]; // 홀수인 경우 마지막 원소
    }

    // 재귀적 정렬
    mainchain = mergeInsertion(mainchain, jacobsthal);

    // Step 3: pair-wise 정렬
    std::vector<int> sorted_array;
    sorted_array.insert(sorted_array.end(), mainchain.begin(), mainchain.end());

    // pendingchain의 원소를 정렬된 위치에 삽입
    for (size_t i = 0; i < pendingchain.size(); ++i) {
        binaryInsertion(sorted_array, pendingchain[i]);
    }

    return sorted_array; // 최종 정렬된 배열 반환
}

int main() {
    int d_array[] = {34, 7, 23, 32, 5, 62, 45, 8, 9};
    int n = sizeof(d_array) / sizeof(d_array[0]);
    std::vector<int> d(d_array, d_array + n);

    // n 크기의 야곱 수열 생성
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
