# String stream
- Helps you to make formatted output without `cout`.
- `stringstream` internally maintains string buffer.
- use `#include <sstream>`
  - `std::stringstream` provides both insertion and extraction
  - `std::istreamstream` provides only insertion
  - `std::ostreamstream` provides only extraction

## Example
```cpp
std::stringstream ss;
ss << "sum of " << a << " & " << b << " is : " << sum << std::endl;

// converting to string object
string str = ss.str();
std::cout << str;

// you can also use to_string
auto ssum = std::to_string(sum);
std::cout << ssum << std:: endl;

// Extraction
std::string data = "12 89 21";
int a;
std::stringstream ss;
ss.str(data);

// while not failed to read from stream,
while( ss >> a ) {
  std:: cout << a << std::endl;
}

//stoi - string to integer
int x = std::stoi("56");
```