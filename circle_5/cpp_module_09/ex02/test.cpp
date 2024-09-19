#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class MergeInsertionSort {
public:
    static std::vector<T> sort(std::vector<T>& arr) {
        if (arr.size() <= 1) {
            return arr; // 기본 경우: 길이가 1 이하이면 그대로 반환
        }
        
        // 1. 배열을 쌍으로 나누기
        std::vector<T> larger;
        std::vector<T> unpaired;

        for (size_t i = 0; i < arr.size(); i += 2) {
            if (i + 1 < arr.size()) {
                // 두 개의 요소를 쌍으로 비교
                if (arr[i] > arr[i + 1]) {
                    larger.push_back(arr[i]);
                } else {
                    larger.push_back(arr[i + 1]);
                }
            } else {
                // 홀수 개일 경우 마지막 요소는 unpaired에 추가
                unpaired.push_back(arr[i]);
            }
        }

        // 2. 재귀적으로 정렬하기
        std::vector<T> sortedLarger = sort(larger);

        // 3. unpaired 요소를 정렬된 larger 요소에 삽입
        for (const auto& value : unpaired) {
            insertInOrder(sortedLarger, value);
        }

        return sortedLarger; // 정렬된 배열 반환
    }

private:
    // 야곱 수열을 생성하는 함수
    static std::vector<int> generateJacobsthal(size_t n) {
        std::vector<int> jacobsthal(n);
        jacobsthal[0] = 1;
        jacobsthal[1] = 2;
        for (size_t i = 2; i < n; ++i) {
            jacobsthal[i] = jacobsthal[i - 1] + jacobsthal[i - 2];
        }
        return jacobsthal;
    }

    // 정렬된 위치에 요소를 삽입하는 함수
    static void insertInOrder(std::vector<T>& sortedArr, T value) {
        auto pos = std::lower_bound(sortedArr.begin(), sortedArr.end(), value);
        sortedArr.insert(pos, value);
    }

    // 야곱 수열을 활용하여 요소를 삽입하는 함수
    static void insertUsingJacobsthal(std::vector<T>& sortedArr, const std::vector<T>& unpaired) {
        auto jacobsthal = generateJacobsthal(unpaired.size());
        size_t idx = 0;

        for (const auto& value : unpaired) {
            if (idx < jacobsthal.size()) {
                // 야곱 수열 인덱스를 사용하여 정렬된 위치에 요소 삽입
                auto pos = std::lower_bound(sortedArr.begin(), sortedArr.end(), value);
                sortedArr.insert(pos, value);
                idx++;
            }
        }
    }
};

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Ford-Johnson 알고리즘으로 정렬
    std::vector<int> sortedArr = MergeInsertionSort<int>::sort(arr);
    
    // 정렬 결과 출력
    std::cout << "Sorted Array: ";
    for (const auto& num : sortedArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
