#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 야곱 수열을 미리 계산하는 함수
std::vector<int> generateJacobsthalSequence(int n) {
    std::vector<int> jacobsthal(n + 1);
    if (n > 0) jacobsthal[0] = 1;
    if (n > 1) jacobsthal[1] = 3;

    for (int i = 2; i <= n; i++) {
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2]; // 점화식
    }
    // for(int i = 0; i <= n; i++)
    //     jacobsthal[i] -= 1;

    return jacobsthal;
}

// 이진 삽입 함수
void binaryInsertion(std::list<int>& d, int value) {
    std::list<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}

// 재귀적 MergeInsertion 알고리즘
std::list<int> mergeInsertion(std::list<int>& d, const std::vector<int>& jacobsthal) {
    int n = d.size();
    if (n <= 1) return d; // 기저 사례: 배열에 원소가 하나면 그대로 반환

    std::list<int> mainchain, pending;

    // 쌍으로 비교하여 mainchain과 pending에 저장
    std::list<int>::iterator prev = d.begin();
    int cnt = 0;

    while (1)
    {
        if (cnt + 1 < n)
        {
            std::list<int>::iterator next = prev;
            next++;
            if (*prev > *next)
            {
                mainchain.push_back(*prev);
                pending.push_back(*next);
            }
            else
            {
                mainchain.push_back(*next);
                pending.push_back(*prev);
            }
        }
        else
        {
            pending.push_back(*prev);
            break ;
        }
        cnt += 2;
        prev++;
        prev++;
    }

    // std::cout << "정렬된 배열: ";
    std::list<int>::iterator tttt = mainchain.begin();
    std::list<int>::iterator ttttt = pending.begin();
    for (size_t i = 0; i < mainchain.size(); ++i) {
        std::cout << *tttt << " ";
        tttt++;
    }
    std::cout << std::endl;

    // std::cout << "정렬된 배열: ";
    for (size_t i = 0; i < pending.size(); ++i) {
        std::cout << *ttttt << " ";
        ttttt++;
    }
    std::cout << std::endl;

    exit(1);

    // for (size_t i = 0; i < d.size(); i += 2) {
    //     if (i + 1 < d.size()) {
    //         if (d[i] > d[i + 1]) {
    //             mainchain.push_back(d[i]);
    //             pending.push_back(d[i + 1]);
    //         } else {
    //             mainchain.push_back(d[i + 1]);
    //             pending.push_back(d[i]);
    //         }
    //     } else {
    //         pending.push_back(d[i]);
    //     }
    // }

    // 재귀적 정렬
    mainchain = mergeInsertion(mainchain, jacobsthal);

    // 결과 배열 생성
    std::list<int> sorted_array;
    sorted_array.insert(sorted_array.end(), mainchain.begin(), mainchain.end());

    int previousJacobsthal = jacobsthal[0];
    std::list<int>::iterator it = pending.begin();
    binaryInsertion(sorted_array, *it);

    for(int i = 1; i < jacobsthal.size(); i++)
    {
        int curentJacobsthal = jacobsthal[i];
        std::list<int>::iterator it2 = it;
        int cnt2 = curentJacobsthal - previousJacobsthal;
        while (cnt2 < curentJacobsthal)
        {
            it++;
            cnt2++;
        }

        for(int j = curentJacobsthal; j > previousJacobsthal; j--)
        {
            if (j < pending.size())
            {
                std::cout << *it2 << " ";
                binaryInsertion(sorted_array, *it2);
                it2--;
            }
        }

        previousJacobsthal = curentJacobsthal;
    }

    return sorted_array; // 최종 정렬된 배열 반환
}

int main(int argc, char**argv) {

    int d_array[] = {34, 7, 32, 5, 62, 45}; // 테스트 데이터
    // int d_array[] = {3}; // 테스트 데이터
    int n = sizeof(d_array) / sizeof(d_array[0]);
    std::list<int> d(d_array, d_array + n);

    // n 크기의 야곱 수열 생성
    std::vector<int> jacobsthal = generateJacobsthalSequence(n);

    // MergeInsertion 알고리즘을 이용해 배열 정렬
    std::list<int> sorted = mergeInsertion(d, jacobsthal);
    std::list<int>::iterator it = sorted.begin();

    // 정렬된 배열 출력
    // std::cout << "정렬된 배열: ";
    // for (size_t i = 0; i < sorted.size(); ++i) {
    //     std::cout << *it << " ";
    //     it++;
    // }
    // std::cout << std::endl;

    return 0;
}
