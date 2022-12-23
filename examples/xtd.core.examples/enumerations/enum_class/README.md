# enum_class

* Shows how to use [xtd::enum_object](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1enum__object.html) class and [enum_class_](https://codedocs.xyz/gammasoft71/xtd/group__keywords.html#gade4794e2743558ee1eb5bbad10c7f6d4) helper.


## Sources

[src/enum_class.cpp](src/enum_class.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
name = value_four
value = 3
as<int> = 3
values = [0, 1, 2, 3]
names = [value_one, value_two, value_three, value_four]
entries = [(0, value_one), (1, value_two), (2, value_three), (3, value_four)]
```