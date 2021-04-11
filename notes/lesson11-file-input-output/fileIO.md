# FILE Input Output.

- Using `<fstream>` library to use:
  - `ostream`, `ifstream` and `fstream`.

### Example
```cpp
void Write() {
  std::ofstream out{"data.txt"};
  out << "Hello" << std::endl;
  out << 10 << std::endl;
  out.close();
}

void Read() {
  std::ifstream input;
  input.open("data.txt");
  std::string message;
  std::getline(input, message);
  int value{};
  input >> value;
  input.close();
  std::cout << message << ":" << value << std::endl;
}

int main() {
  Write();
  Read();
  return 0;
```
<br />
<br />

## File Open Modes
- These constants are defined in `std::ios_base` class.
- To combine mode: e.g. `std::ios::in | std::ios::out`

### Modes in table
| Mode   | Meaning                                      |
| ---    | ---                                          |
| app    | seek to the end before write each operation. |
| binary | open in binary mode                          |
| in     | opening for reading                          |
| out    | opening for writing                          |
| trunc  | discard file contentbefore opening           |
| ate    | seek to end after open                       |

<br />
<br />

## Error handling
- use `.is_open()` method from one of file object.

### Stream State Flags
- goodbit : having no error, use `good()`
- badbit: irrecoverable stream error, use `bad()`
- failbit: I/O operation failed, use `fail()`
- eofbit: end of file reached during input, use `eof()`.
- e.g. `input.good()`.
- To clear these bits, you need to call `clear()`.
- You can also set state: `setState(std::ios::failbit)`.
  - may be you can use this for testing `fail()`?

### Example
```cpp
std::string line;
while(!std::getline(input, line).eof()){
  output << line << std::endl;
}
```

## Furthernote
- `>>` operator will read upto first space.
- Binary file do not conatin eof.
- when no more characters can be read from a file, eof and failbit will be
  set to true while goodbit is set to false.