#ifndef INTERVIEW_H_
#define INTERVIEW_H_
#include <unordered_map>
#include <string>
class Interview final {
public:
	Interview() = delete;
	static std::unordered_map<std::string, std::string> dialogue;
private:
	static std::unordered_map<std::string, std::string> fillUmap(const std::string&, const std::string&);
};


#endif

