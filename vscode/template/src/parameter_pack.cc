#include <iostream>
#include <cstring>

template <typename T>
void print(T arg){std::cout << arg << std::endl;}

// parameter pack, called recursively
template <typename T, typename ...Types>
void print(T arg, Types ... args)
{   
    std::cout << arg << ", ";
    print(args...);
}

size_t GetStringSize(const char* s) { return strlen(s); }

size_t GetStringSize(const std::string& s) { return s.size(); }

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
  return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str) { return; }

template <typename String, typename... Stringss>
void AppendToString(std::string* concat_str, const String& s, Stringss... strs) {
  concat_str->append(s);
  AppendToString(concat_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
  // 먼저 합쳐질 문자열의 총 길이를 구한다.
  size_t total_size = GetStringSize(s, strs...);

  // reserve 를 통해 미리 공간concat_str을 할당해 놓는다.
  std::string concat_str;
  concat_str.reserve(total_size);

  concat_str = s;
  AppendToString(&concat_str, strs...);

  return concat_str;
}



// Fold
template <typename... Ints>
int sum_all(Ints... num)
{
    // return (num + ...);
    return (num + ...);
}

int main(){

    print("char*", 10);
    std::cout << sum_all(1,2,4) << std::endl;
    std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
                      " ", std::string("sentence"));
    return 0;
}