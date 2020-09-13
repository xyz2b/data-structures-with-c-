#ifndef DATASTRUCT_EXCEPTION_H
#define DATASTRUCT_EXCEPTION_H

#include <iostream>
#include <execinfo.h>	/* for backtrace() */
#include <cstdlib>

#define SIZE	100

using namespace std;

class Exception
{
private:
    const string errorMsg;
	const string errorFile;
	const int errorLine;
	string errorFunc;

	static string _CutParenthesesNTail(string& prettyFunc);

    // void dump(void);
public:
    Exception(const string msg, const string file, const int line, const string func);
};

inline
Exception::Exception(const string msg, const string file, const int line, const string func): errorMsg(msg), errorFile(file), errorLine(line), errorFunc(func) {

    cout << "Exception: file = " << errorFile << ", line = " << errorLine << ", func = " << _CutParenthesesNTail(errorFunc) << ", msg = " << errorMsg << endl;
	exit(-1);
    // dump();
}

inline string 
Exception::_CutParenthesesNTail(string& prettyFunc)
{
	// 在字符串中找到"("， 并删除"("包括"("之后的内容
	size_t pos = prettyFunc.find('(');

    if(pos != string::npos) {
		prettyFunc.erase(prettyFunc.begin() + pos, prettyFunc.end());
	}
        
	
	// 在字符串中找到" "， 并删除" "包括" "之后的内容
	pos = prettyFunc.find(' ');

	if(pos != string::npos) {
		prettyFunc.erase(prettyFunc.begin(), prettyFunc.begin() + pos + 1);
	}
        
    return move(prettyFunc);
}

// inline void
// Exception::dump(void) {
//     int j, nptrs;
// 	void *buffer[100];
// 	char **strings;

// 	nptrs = backtrace(buffer, SIZE);
// 	printf("backtrace() returned %d addresses\n", nptrs);

// 	strings = backtrace_symbols(buffer, nptrs);
// 	if (strings == NULL) {
// 		perror("backtrace_symbols");
// 		exit(EXIT_FAILURE);
// 	}

// 	for (j = 0; j < nptrs; j++)
// 		printf("  [%02d] %s\n", j, strings[j]);

// 	free(strings);
// }

#endif /* DATASTRUCT_EXCEPTION_H */