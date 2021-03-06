/**
 * @file ConfigReader.hpp
 * @brief
 */

#ifndef CONFIGREADER_HPP
#define CONFIGREADER_HPP

#include <string>
#include <exception>
#include <map>
#include <iostream>

/**ParameterNotFoundException class
 *
 */
class ParameterNotFoundException: public std::exception {
public:
	/**ParameterNotFoundException constructor
	 *
	 * @param (const char* name):p(name)
	 */
	ParameterNotFoundException(const char* name):p(name){
		std::cout << p << " not found in config-file!" << std::endl;
	}

protected:
    std::string p;

};

/**UnknownParameterTypeException class
 *
 */
class UnknownParameterTypeException: public std::exception {
public:
	/**UnknownParameterTypeException constructor
	 *
	 * @param (const char* type):t(type)
	 */
	UnknownParameterTypeException(const char* type):t(type){
		std::cout << t << " is an unknown type!" << std::endl;
	}

protected:
    std::string t;

};

/**CannotOpenConfigFileException class
 *
 */
class CannotOpenConfigFileException: public std::exception {
public:
	/**CannotOpenConfigFileException constructor
	 *
	 * @param (const char* filename):fn(filename)
	 */
	CannotOpenConfigFileException(const char* filename):fn(filename){
		std::cout << fn << " not found!" << std::endl;
	}

protected:
    std::string fn;

};

/**ConfigFileChangedException class
 *
 */
class ConfigFileChangedException: public std::exception {
public:
	/**ConfigFileChangedException constructor
	 *
	 * @param (const char* filename)
	 */
	ConfigFileChangedException(const char* filename):fn(filename){
		std::cout << fn << " seems to have changed while KickIT was running!" << std::endl;
	}

protected:
    std::string fn;

};

/**ConfigReader class
 *
 */
class ConfigReader {
public:
	/**ConfigReader constructor
	 *
	 * @param (const char* filename)
	 */
	ConfigReader(const char* filename);

	/**getStringValue function
	 *
	 * Throws ParameterNotFoundException if the parameter cannot be found.
	 *
	 * @param (const char* name)
	 */
    std::string getStringValue(const char* name);

    /**getIntValue function
     *
     * Throws ParameterNotFoundException if the parameter cannot be found.
     *
     * @param (const char* name)
     */
    int getIntValue(const char* name);

    /**setStringValue function
     *
     * Function to update a value.
     * If the value doesn't exist yet, it will be added to the data set.
     *
     * @param (const char* name, const char* value)
     */
    void setStringValue(const char* name, const char* value);

    /**setIntValue function
     *
     * Function to update a value.
     * If the value doesn't exist yet, it will be added to the data set.
     *
     * @param (const char* name, const int value)
     */
    void setIntValue(const char* name, const int value);

    /**writeOut function
     *
     * Function to rewrite the file in case that any of the values have changed.
     *
     */
    void writeOut();

protected:
    const char* filename;
    bool valueChanged = false;

    std::map<std::string, int> values;
    std::map<std::string, std::string> strings;

    /**readFile function
     *
     */
    void readFile();

};

#endif //CONFIGREADER_HPP
