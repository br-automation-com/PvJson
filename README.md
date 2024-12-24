# PvJson

PvJson exported library and demo project

# General

PvJson is a library composed by two Function Blocks:

- **JsonSerializer**: This Function Block will take a PV name as input and will generate a json serialized string with its values as output. Additionally, this string can be directly written to a file if the FileDevice and FileName parameters are given.

- **JsonParser**: This Function Block will take a json string as an input, containing a PV and its value. This string can be built manually, however it's recommended to start from one generated by *JsonSerializer* to avoid syntax errors. This string can be provided as a pointer to a memory area or read from a file if the FileDevice and FileName parameters are given.

  

# Versions

PvJson has been compiled using several AR versions. These AR versions have been chosen with the target of covering most of the use cases, if your particular case is not covered, please open an issue in the repository.

The rules to follow to select the proper library version are:
- When using AR >= 6.0 version **6.0.xxx** should be used.
- When using AR >= 4.4 and AR <= 4.93 , version **4.73** should be used together with compiler version GCC 6.3.0 							***(1)(4)***
- When using AR >= 4.33 and AR < 4.4, version **4.34** should be used together with compiler version GCC 4.1.2   ***(1)(4)***
- When using AR >= 4.25 and AR < 4.33, version **4.26** should be used together with compiler version GCC 4.1.2 ***(1)(4)***
- When using AR < 4.25, version **3.10** should be used together with compiler version GCC 4.1.2                            ***(1)(2)(3)(4)***

# Limitations

Depending on the library version chosen, they can have different limitations regarding which variables they are able to treat.

***(1)*** Enumerations can only be treated as numbers, these must be considered when modifying an enumeration type to delete or incorporate new elements that might affect the associated number the rest of the members have.

***(2)*** Multidimensional variables are not supported. E.g. MyArray[0..5,0..10] 

***(3)*** Arrays with negative indexes are not working correctly. E.g. MyArray[-5 .. 5] (https://github.com/br-automation-com/PvJson/issues/2)

***(4)*** AR version supported up to rev06
