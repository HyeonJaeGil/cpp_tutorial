// Ex3_04.cpp
// 힙을 우선순위 큐로 사용하는 예제
#include <iostream>           // 표준 스트림
#include <iomanip>            // 스트림 조작자
#include <algorithm>          // 힙 함수
#include <string>             // string 클래스
#include <deque>              // deque 컨테이너
using std::string;
 
// deque에 저장된 단어 목록을 출력
void show(const std::deque<string>& words, size_t count = 5)
{
    if(words.empty()) return; // deque에 원소가 있는지 확인
    // 가장 긴 문자열을 찾기
    auto max_len = std::max_element(std::begin(words), std::end(words),
                                    [](const string& s1, const string& s2)
                                    { return s1.size() < s2.size(); })->size();
 
    // 단어들을 출력한다
    size_t n {count};
    for(const auto& word : words)
    {
        std::cout << std::setw(max_len + 1) << word << " ";
        if(!n) continue;
        std::cout << std::endl;
        n = count;
    }
    std::cout << std::endl;
}
 
int main()
{
  std::deque<string> words;
  std::string word;
  std::cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
  while (true)
  {
    if ((std::cin >> word).eof())
    {
      std::cin.clear();
      break;
    }
    words.push_back(word);
  }
  std::cout << "The words in the list are:" << std::endl;
  show(words);
 
  std::make_heap(std::begin(words), std::end(words));
  std::cout << "\nAfter making a heap, the words in the list are:" << std::endl;
  show(words);
  std::cout << "\nYou entered " << words.size() << " words. Enter some more:" << std::endl;
  while (true)
  {
    if ((std::cin >> word).eof())
    {
      std::cin.clear();
      break;
    }
    words.push_back(word);
    std::push_heap(std::begin(words), std::end(words));
  }
  std::cout << "\nThe words in the list are now:" << std::endl;
  show(words);
}