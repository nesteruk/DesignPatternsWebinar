#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>

class String {
  std::string s;
public:

  String(const string &s) : s(s) { }

  String to_lower_copy() const {
    return {boost::to_lower_copy(s)};
  }

  vector<String> split(const string& delimeter = " ") const {
    vector<string> parts;
    boost::split(parts, s, boost::is_any_of(delimeter),
                 boost::token_compress_on);
    return vector<String>(parts.begin(), parts.end());
  }

  size_t get_length() const { return s.length(); }
};

int main()
{
  // goal: take a string "Hello  World",
  //       make lowercase, split into words and measure their length

  string s{"Hello  World"};

  // Standard library is not enough, we need to use Boost:

  string sl = boost::to_lower_copy(s);
  vector<string> parts;
  boost::split(parts, sl, boost::is_any_of(" "), boost::token_compress_on);

  for (auto& p : parts)
    cout << p.length() << "\n"; // length or size?

  // same with an adapter
  String s2{"Hello  World"};
  for (auto& q : s2.to_lower_copy().split())
    cout << q.get_length() << "\n";

  getchar();
  return 0;
}