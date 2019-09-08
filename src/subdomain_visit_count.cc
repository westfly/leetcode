#include "code_utils.h"
#include <unordered_map>
vector<string> subdomainVisits(vector<string>& cpdomains) {
    std::unordered_map<std::string, int> domainCounter(cpdomains.size()*3);
    for(auto& record : cpdomains) {        
        auto spaceIdx= record.find(" ");
        int count = atoi(record.substr(0, spaceIdx).c_str());
        while (spaceIdx != string::npos) {
            domainCounter[record.substr(spaceIdx + 1)] += count;
            spaceIdx = record.find('.', spaceIdx + 1);
        }
    }
    vector<string> res;
    // 貌似不能省效率
    res.reserve(domainCounter.size());
    for (auto& a : domainCounter) {
        res.emplace_back(to_string(a.second) + " " + a.first);
    }
    return res;
}

int main()
{
    return 0;
}

